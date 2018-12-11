module EverCrypt.Hash

#set-options "--max_fuel 0 --max_ifuel 0 --z3rlimit 100"

open FStar.HyperStack.ST

module B = LowStar.Buffer
module IB = LowStar.ImmutableBuffer
module HS = FStar.HyperStack
module ST = FStar.HyperStack.ST

module AC = EverCrypt.AutoConfig2
module SC = EverCrypt.StaticConfig

open LowStar.BufferOps
open FStar.Integers
open C.Failure

// Allow *just* the alg type to be inverted, so that the entire module can run
// with ifuel 0
let _: squash (inversion alg) = allow_inversion alg

let string_of_alg =
  let open C.String in function
  | MD5 -> !$"MD5"
  | SHA1 -> !$"SHA1"
  | SHA2_224 -> !$"SHA2_224"
  | SHA2_256 -> !$"SHA2_256"
  | SHA2_384 -> !$"SHA2_384"
  | SHA2_512 -> !$"SHA2_512"

let uint32_p = B.buffer uint_32
let uint64_p = B.buffer uint_64

// JP: not sharing the 224/256 and 384/512 cases, even though the internal state
//   is the same, to avoid the additional proof burden.
// JP: also note that we are sharing state between implementations, since Vale
//   kindly offers a wrapper that is compatible with the HACL* representation
noeq
type state_s: alg -> Type0 =
| MD5_s: p:Hacl.Hash.Definitions.state MD5 -> state_s MD5
| SHA1_s: p:Hacl.Hash.Definitions.state SHA1 -> state_s SHA1
| SHA2_224_s: p:Hacl.Hash.Definitions.state SHA2_224 -> state_s SHA2_224
| SHA2_256_s: p:Hacl.Hash.Definitions.state SHA2_256 -> state_s SHA2_256
| SHA2_384_s: p:Hacl.Hash.Definitions.state SHA2_384 -> state_s SHA2_384
| SHA2_512_s: p:Hacl.Hash.Definitions.state SHA2_512 -> state_s SHA2_512

let invert_state_s (a: alg): Lemma
  (requires True)
  (ensures (inversion (state_s a)))
  [ SMTPat (state_s a) ]
=
  allow_inversion (state_s a)

inline_for_extraction
let p #a (s: state_s a): Hacl.Hash.Definitions.state a =
  match s with
  | MD5_s p -> p
  | SHA1_s p -> p
  | SHA2_224_s p -> p
  | SHA2_256_s p -> p
  | SHA2_384_s p -> p
  | SHA2_512_s p -> p

let freeable_s #a s = B.freeable (p #a s)

let footprint_s #a (s: state_s a) =
  B.loc_addr_of_buffer (p s)

let invariant_s #a (s: state_s a) h =
  B.live h (p s)

let repr #a s h: GTot _ =
  let s = B.get h s 0 in
  B.as_seq h (p s)

let repr_eq (#a:alg) (r1 r2: acc a) =
  Seq.equal r1 r2

let fresh_is_disjoint l1 l2 h0 h1 = ()

let invariant_loc_in_footprint #a s m = ()

let frame_invariant #a l s h0 h1 =
  let state = B.deref h0 s in
  assert (repr_eq (repr s h0) (repr s h1))

inline_for_extraction noextract
let alloca a =
  let h0 = ST.get () in
  let s: state_s a =
    match a with
    | MD5 -> MD5_s (B.alloca 0ul 4ul)
    | SHA1 -> SHA1_s (B.alloca 0ul 5ul)
    | SHA2_224 -> SHA2_224_s (B.alloca 0ul 8ul)
    | SHA2_256 -> SHA2_256_s (B.alloca 0ul 8ul)
    | SHA2_384 -> SHA2_384_s (B.alloca 0UL 8ul)
    | SHA2_512 -> SHA2_512_s (B.alloca 0UL 8ul)
  in
  B.alloca s 1ul

let create a =
  let h0 = ST.get () in
  let s: state_s a =
    match a with
    | MD5 -> MD5_s (B.malloc HS.root 0ul 4ul)
    | SHA1 -> SHA1_s (B.malloc HS.root 0ul 5ul)
    | SHA2_224 -> SHA2_224_s (B.malloc HS.root 0ul 8ul)
    | SHA2_256 -> SHA2_256_s (B.malloc HS.root 0ul 8ul)
    | SHA2_384 -> SHA2_384_s (B.malloc HS.root 0UL 8ul)
    | SHA2_512 -> SHA2_512_s (B.malloc HS.root 0UL 8ul)
  in
  B.malloc HS.root s 1ul

let init #a s =
  match !*s with
  | MD5_s p -> Hacl.Hash.MD5.init p
  | SHA1_s p -> Hacl.Hash.SHA1.init p
  | SHA2_224_s p -> Hacl.Hash.SHA2.init_224 p
  | SHA2_256_s p -> Hacl.Hash.SHA2.init_256 p
  | SHA2_384_s p -> Hacl.Hash.SHA2.init_384 p
  | SHA2_512_s p -> Hacl.Hash.SHA2.init_512 p

friend SHA_helpers

assume val such_a_bad_hack: #a:Type -> b:IB.ibuffer a ->
  Stack (b': B.buffer a)
    (requires (fun h ->
      B.live h b))
    (ensures (fun h0 b' h1 ->
      forall h. {:pattern B.live h b } B.live h b ==> B.live h b' /\
      B.length b = B.length b' /\
      B.modifies B.loc_none h0 h1))

// A new switch between HACL and Vale; can be used in place of Hacl.Hash.SHA2.update_256
inline_for_extraction noextract
val update_multi_256: Hacl.Hash.Definitions.update_multi_st SHA2_256
let update_multi_256 s blocks n =
  let has_shaext = AC.has_shaext () in
  if SC.vale && has_shaext then begin
    let n = Int.Cast.Full.uint32_to_uint64 n in
    let open Hacl.Hash.Core.SHA2.Constants in
    B.recall k224_256;
    IB.recall_contents k224_256 Spec.SHA2.Constants.k224_256;
    // Hack alert!
    let k = such_a_bad_hack k224_256 in
    let h0 = ST.get () in
    assume (B.loc_disjoint (B.loc_buffer k) (B.loc_buffer s));
    assume (B.loc_disjoint (B.loc_buffer k) (B.loc_buffer blocks));
    assume (
      let k_b128 = LowStar.BufferView.mk_buffer_view k Views.view32_128 in
      SHA_helpers.k_reqs (LowStar.BufferView.as_seq h0 k_b128));
    Sha_update_bytes_stdcall.sha256_update s blocks n k;
    admit ()
  end else
    Hacl.Hash.SHA2.update_multi_256 s blocks n

// Need to unroll the definition of update_multi once to prove that it's update
#push-options "--max_fuel 1"
let update #a s block =
  match !*s with
  | MD5_s p -> Hacl.Hash.MD5.update p block
  | SHA1_s p -> Hacl.Hash.SHA1.update p block
  | SHA2_224_s p -> Hacl.Hash.SHA2.update_224 p block
  | SHA2_256_s p -> update_multi_256 p block 1ul
  | SHA2_384_s p -> Hacl.Hash.SHA2.update_384 p block
  | SHA2_512_s p -> Hacl.Hash.SHA2.update_512 p block
#pop-options

let update_multi #a s blocks len =
  match !*s with
  | MD5_s p ->
      let n = len / size_block_ul MD5 in
      Hacl.Hash.MD5.update_multi p blocks n
  | SHA1_s p ->
      let n = len / size_block_ul SHA1 in
      Hacl.Hash.SHA1.update_multi p blocks n
  | SHA2_224_s p ->
      let n = len / size_block_ul SHA2_224 in
      Hacl.Hash.SHA2.update_multi_224 p blocks n
  | SHA2_256_s p ->
      let n = len / size_block_ul SHA2_256 in
      update_multi_256 p blocks n
  | SHA2_384_s p ->
      let n = len / size_block_ul SHA2_384 in
      Hacl.Hash.SHA2.update_multi_384 p blocks n
  | SHA2_512_s p ->
      let n = len / size_block_ul SHA2_512 in
      Hacl.Hash.SHA2.update_multi_512 p blocks n

// Re-using the higher-order stateful combinator to get an instance of
// update_last that is capable of calling Vale under the hood
val update_last_256: Hacl.Hash.Definitions.update_last_st SHA2_256
let update_last_256 s prev_len input input_len =
  Hacl.Hash.MD.mk_update_last SHA2_256 update_multi_256 Hacl.Hash.SHA2.pad_256 s prev_len input input_len

// Splitting out these proof bits; the proof is highly unreliable when all six
// cases are done together in a single match
inline_for_extraction
let update_last_st (#a:e_alg) =
  let a = Ghost.reveal a in
  p:Hacl.Hash.Definitions.state a ->
  last:uint8_p { B.length last < size_block a } ->
  total_len:uint64_t {
    v total_len < max_input8 a /\
    (v total_len - B.length last) % size_block a = 0 } ->
  Stack unit
  (requires fun h0 ->
    B.live h0 p /\
    B.live h0 last /\
    B.(loc_disjoint (loc_buffer p) (loc_buffer last)))
  (ensures fun h0 _ h1 ->
    B.(modifies (loc_buffer p) h0 h1) /\
    (B.length last + Seq.length (Spec.Hash.Common.pad a (v total_len))) % size_block a = 0 /\
    B.as_seq h1 p ==
      compress_many (B.as_seq h0 p)
        (Seq.append (B.as_seq h0 last) (Spec.Hash.Common.pad a (v total_len))))

inline_for_extraction
val update_last_64 (a: e_alg{ G.reveal a <> SHA2_384 /\ G.reveal a <> SHA2_512 })
  (update_last: Hacl.Hash.Definitions.update_last_st (G.reveal a)):
  update_last_st #a
inline_for_extraction
let update_last_64 a update_last p last total_len =
  let input_len = total_len % Int.Cast.Full.uint32_to_uint64 (size_block_ul MD5) in
  let prev_len = total_len - input_len in
  update_last p prev_len last (Int.Cast.Full.uint64_to_uint32 input_len)

#push-options "--z3rlimit 1000"
inline_for_extraction
val update_last_128 (a: e_alg{ G.reveal a = SHA2_384 \/ G.reveal a = SHA2_512 })
  (update_last: Hacl.Hash.Definitions.update_last_st (G.reveal a)):
  update_last_st #a
inline_for_extraction
let update_last_128 a update_last p last total_len =
  let input_len = total_len % Int.Cast.Full.uint32_to_uint64 (size_block_ul SHA2_384) in
  let prev_len = Int.Cast.Full.uint64_to_uint128 (total_len - input_len) in
  update_last p prev_len last (Int.Cast.Full.uint64_to_uint32 input_len)
#pop-options

#push-options "--z3rlimit 50"
let update_last #a s last total_len =
  match !*s with
  | MD5_s p ->
      update_last_64 a Hacl.Hash.MD5.update_last p last total_len
  | SHA1_s p ->
      update_last_64 a Hacl.Hash.SHA1.update_last p last total_len
  | SHA2_224_s p ->
      update_last_64 a Hacl.Hash.SHA2.update_last_224 p last total_len
  | SHA2_256_s p ->
      update_last_64 a update_last_256 p last total_len
  | SHA2_384_s p ->
      update_last_128 a Hacl.Hash.SHA2.update_last_384 p last total_len
  | SHA2_512_s p ->
      update_last_128 a Hacl.Hash.SHA2.update_last_512 p last total_len
#pop-options

let finish #a s dst =
  match !*s with
  | MD5_s p -> Hacl.Hash.MD5.finish p dst
  | SHA1_s p -> Hacl.Hash.SHA1.finish p dst
  | SHA2_224_s p -> Hacl.Hash.SHA2.finish_224 p dst
  | SHA2_256_s p -> Hacl.Hash.SHA2.finish_256 p dst
  | SHA2_384_s p -> Hacl.Hash.SHA2.finish_384 p dst
  | SHA2_512_s p -> Hacl.Hash.SHA2.finish_512 p dst

let free #ea s =
  begin match !*s with
    | MD5_s p -> B.free p
    | SHA1_s p -> B.free p
    | SHA2_224_s p -> B.free p
    | SHA2_256_s p -> B.free p
    | SHA2_384_s p -> B.free p
    | SHA2_512_s p -> B.free p
  end;
  B.free s

// A full one-shot hash that relies on vale at each multiplexing point
val hash_256: Hacl.Hash.Definitions.hash_st SHA2_256
let hash_256 input input_len dst =
  let open Hacl.Hash.SHA2 in
  let open Hacl.Hash.MD in
  mk_hash SHA2_256 alloca_256 update_multi_256 update_last_256 finish_256 input input_len dst

let hash a dst input len =
  match a with
  | MD5 -> Hacl.Hash.MD5.hash input len dst
  | SHA1 -> Hacl.Hash.SHA1.hash input len dst
  | SHA2_224 -> Hacl.Hash.SHA2.hash_224 input len dst
  | SHA2_256 -> hash_256 input len dst
  | SHA2_384 -> Hacl.Hash.SHA2.hash_384 input len dst
  | SHA2_512 -> Hacl.Hash.SHA2.hash_512 input len dst
