
open Prims
let op_Bar_Amp = (fun x y -> (UInt.log_and_wide x y))

let op_Bar_Greater_Greater = (fun x y -> (UInt.shift_right_wide x y))

let op_Bar_Plus = (fun x y -> (UInt.add_wide x y))

let op_Bar_Star = (fun x y -> (UInt.mul_wide x y))

let satisfies_modulo_constraints = (fun h b -> (Obj.magic (())))

let lemma_satisfies = (fun h b n -> ())

let sum_satisfies_constraints = (fun h0 h1 cpy a b -> ())

let n0 = Parameters.ndiff'

let n1 = Parameters.ndiff

let difference_satisfies_constraints = (fun h0 h1 cpy a b -> ())

let lemma_satisfies_2 = (fun h b -> ())

let lemma_satisfies_4 = (fun a b c d -> ())

let lemma_satisfies_3 = (fun b c -> ())

let mul_satisfies_constraints = (fun h0 h1 res a b -> ())

let lemma_helper_000 = (fun ctr -> ())

let lemma_helper_001 = (fun ctr -> ())

let rec lemma_helper_002 = (fun a b -> ())

let lemma_helper_003 = (fun ctr -> ())

let lemma_helper_004 = (fun ctr -> ())

let rec pow2_bitweight_lemma_1 = (fun ctr -> ())

let bitweight_norm_length_lemma = (fun _25_129 -> ())

let freduce_degree_lemma_0 = (Obj.magic ((fun h0 h1 b ctr -> (FStar_All.failwith "Not yet implemented:freduce_degree_lemma_0"))))

let lemma_helper_0 = (fun x y -> ())

let freduce_degree_1 = (fun b -> (let b14 = (Bigint.index_wide b 14)
in (let b13 = (Bigint.index_wide b 13)
in (let b12 = (Bigint.index_wide b 12)
in (let b11 = (Bigint.index_wide b 11)
in (let b10 = (Bigint.index_wide b 10)
in (let b9 = (Bigint.index_wide b 9)
in (let b8 = (Bigint.index_wide b 8)
in (let b7 = (Bigint.index_wide b 7)
in (let b6 = (Bigint.index_wide b 6)
in (let b5 = (Bigint.index_wide b 5)
in (let b4 = (Bigint.index_wide b 4)
in (let b3 = (Bigint.index_wide b 3)
in (let h0 = (FStar_ST.get ())
in (let _25_179 = ()
in (let _25_181 = ()
in (let _25_183 = (Bigint.upd_wide b 10 (op_Bar_Plus b10 b14))
in (let _25_185 = (Bigint.upd_wide b 6 (op_Bar_Plus b6 b14))
in (let h1 = (FStar_ST.get ())
in (let _25_188 = ()
in (let _25_190 = ()
in (let _25_192 = ()
in (let _25_194 = (Bigint.upd_wide b 9 (op_Bar_Plus b9 b13))
in (let _25_196 = (Bigint.upd_wide b 5 (op_Bar_Plus b5 b13))
in (let h2 = (FStar_ST.get ())
in (let _25_199 = ()
in (let _25_201 = ()
in (let _25_203 = ()
in (let _25_205 = (Bigint.upd_wide b 8 (op_Bar_Plus b8 b12))
in (let _25_207 = (Bigint.upd_wide b 4 (op_Bar_Plus b4 b12))
in (let h3 = (FStar_ST.get ())
in (let _25_210 = ()
in (let _25_212 = ()
in (let _25_214 = ()
in (let _25_216 = (Bigint.upd_wide b 7 (op_Bar_Plus b7 b11))
in (let _25_218 = (Bigint.upd_wide b 3 (op_Bar_Plus b3 b11))
in (let h4 = (FStar_ST.get ())
in ())))))))))))))))))))))))))))))))))))))

let lemma_helper_1 = (fun x y -> ())

let freduce_degree_2 = (fun b -> (let b11 = (Bigint.index_wide b 11)
in (let b10 = (Bigint.index_wide b 10)
in (let b9 = (Bigint.index_wide b 9)
in (let b8 = (Bigint.index_wide b 8)
in (let b6 = (Bigint.index_wide b 6)
in (let b5 = (Bigint.index_wide b 5)
in (let b4 = (Bigint.index_wide b 4)
in (let b2 = (Bigint.index_wide b 2)
in (let b1 = (Bigint.index_wide b 1)
in (let b0 = (Bigint.index_wide b 0)
in (let h0 = (FStar_ST.get ())
in (let _25_248 = ()
in (let _25_250 = ()
in (let _25_252 = (Bigint.upd_wide b 6 (op_Bar_Plus b6 b10))
in (let _25_254 = (Bigint.upd_wide b 2 (op_Bar_Plus b2 b10))
in (let h1 = (FStar_ST.get ())
in (let _25_257 = ()
in (let _25_259 = ()
in (let _25_261 = ()
in (let _25_263 = (Bigint.upd_wide b 5 (op_Bar_Plus b5 b9))
in (let _25_265 = (Bigint.upd_wide b 1 (op_Bar_Plus b1 b9))
in (let h2 = (FStar_ST.get ())
in (let _25_268 = ()
in (let _25_270 = ()
in (let _25_272 = ()
in (let _25_274 = (Bigint.upd_wide b 4 (op_Bar_Plus b4 b8))
in (let _25_276 = (Bigint.upd_wide b 0 (op_Bar_Plus b0 b8))
in (let h3 = (FStar_ST.get ())
in ())))))))))))))))))))))))))))))

let trim_2_56 = (fun x -> (let mask = (UInt.shift_left_wide UInt.one_wide 56)
in (let _25_283 = ()
in (let _25_285 = ()
in (let _25_287 = ()
in (let mask = (UInt.sub_wide mask UInt.one_wide)
in (let res = (op_Bar_Amp x mask)
in (let _25_291 = ()
in res))))))))

let lemma_helper_2 = (fun bip1 c -> ())

let pow2_bitweight_lemma = (fun ctr -> ())

let eval_carry_lemma = (fun ha a hb b ctr -> ())

let freduce_lemma_0 = (fun h0 h1 h2 b -> ())

let rec carry = (fun b i -> (let _25_397 = ()
in (let h0 = (FStar_ST.get ())
in (match ((Parameters.norm_length - i)) with
| 0 -> begin
()
end
| _25_402 -> begin
(let bi = (Bigint.index_wide b i)
in (let ri = (trim_2_56 bi)
in (let _25_405 = ()
in (let _25_407 = (Bigint.upd_wide b i ri)
in (let h1 = (FStar_ST.get ())
in (let c = (op_Bar_Greater_Greater bi 56)
in (let _25_411 = ()
in (let _25_413 = ()
in (let bip1 = (Bigint.index_wide b (i + 1))
in (let _25_416 = ()
in (let z = (op_Bar_Plus bip1 c)
in (let _25_419 = (Bigint.upd_wide b (i + 1) z)
in (let h2 = (FStar_ST.get ())
in (let _25_422 = ()
in (let _25_424 = ()
in (carry b (i + 1)))))))))))))))))
end))))

let lemma_helper_3 = (fun x y -> ())

let carry_top_to_0 = (fun b -> (let h0 = (FStar_ST.get ())
in (let btop = (Bigint.index_wide b 8)
in (let b0 = (Bigint.index_wide b 0)
in (let b4 = (Bigint.index_wide b 4)
in (let _25_446 = ()
in (let _25_448 = ()
in (let _25_450 = (Bigint.upd_wide b 0 (op_Bar_Plus b0 btop))
in (let _25_452 = (Bigint.upd_wide b 4 (op_Bar_Plus b4 btop))
in (let h1 = (FStar_ST.get ())
in ()))))))))))

let lemma_helper_6 = (Obj.magic ((fun x -> (FStar_All.failwith "Not yet implemented:lemma_helper_6"))))

let lemma_helper_7 = (fun x y -> ())

let lemma_helper_8 = (fun x y -> ())

let lemma_helper_9 = (fun x y -> ())

let lemma_helper_10 = (Obj.magic ((fun x n -> (FStar_All.failwith "Not yet implemented:lemma_helper_10"))))

let lemma_helper_11 = (fun x y -> ())

let lemma_helper_12 = (fun x y ny -> ())

let full_update = (fun b r0 r1 r2 r3 r4 r5 r6 r7 r8 -> (let h0 = (FStar_ST.get ())
in (let _25_512 = (Bigint.upd_wide b 0 r0)
in (let h1 = (FStar_ST.get ())
in (let _25_515 = ()
in (let _25_517 = (Bigint.upd_wide b 1 r1)
in (let h2 = (FStar_ST.get ())
in (let _25_520 = ()
in (let _25_522 = (Bigint.upd_wide b 2 r2)
in (let h3 = (FStar_ST.get ())
in (let _25_525 = ()
in (let _25_527 = (Bigint.upd_wide b 3 r3)
in (let h4 = (FStar_ST.get ())
in (let _25_530 = ()
in (let _25_532 = (Bigint.upd_wide b 4 r4)
in (let h5 = (FStar_ST.get ())
in (let _25_535 = ()
in (let _25_537 = (Bigint.upd_wide b 5 r5)
in (let h6 = (FStar_ST.get ())
in (let _25_540 = ()
in (let _25_542 = (Bigint.upd_wide b 6 r6)
in (let h7 = (FStar_ST.get ())
in (let _25_545 = ()
in (let _25_547 = (Bigint.upd_wide b 7 r7)
in (let h8 = (FStar_ST.get ())
in (let _25_550 = ()
in (let _25_552 = (Bigint.upd_wide b 8 r8)
in (let h9 = (FStar_ST.get ())
in ()))))))))))))))))))))))))))))

let carry2 = (fun b -> (let _25_564 = ()
in (let h0 = (FStar_ST.get ())
in (let b0 = (Bigint.index_wide b 0)
in (let b1 = (Bigint.index_wide b 1)
in (let b2 = (Bigint.index_wide b 2)
in (let b3 = (Bigint.index_wide b 3)
in (let b4 = (Bigint.index_wide b 4)
in (let b5 = (Bigint.index_wide b 5)
in (let b6 = (Bigint.index_wide b 6)
in (let b7 = (Bigint.index_wide b 7)
in (let r0 = (trim_2_56 b0)
in (let c1 = (op_Bar_Greater_Greater b0 56)
in (let _25_577 = ()
in (let _25_579 = ()
in (let _25_581 = ()
in (let d1 = (op_Bar_Plus b1 c1)
in (let r1 = (trim_2_56 d1)
in (let _25_585 = ()
in (let c2 = (op_Bar_Greater_Greater d1 56)
in (let _25_588 = ()
in (let _25_590 = ()
in (let _25_592 = ()
in (let _25_594 = ()
in (let d2 = (op_Bar_Plus b2 c2)
in (let r2 = (trim_2_56 d2)
in (let _25_598 = ()
in (let c3 = (op_Bar_Greater_Greater d2 56)
in (let _25_601 = ()
in (let _25_603 = ()
in (let _25_605 = ()
in (let _25_607 = ()
in (let d3 = (op_Bar_Plus b3 c3)
in (let r3 = (trim_2_56 d3)
in (let _25_611 = ()
in (let c4 = (op_Bar_Greater_Greater d3 56)
in (let _25_614 = ()
in (let _25_616 = ()
in (let _25_618 = ()
in (let _25_620 = ()
in (let d4 = (op_Bar_Plus b4 c4)
in (let r4 = (trim_2_56 d4)
in (let _25_624 = ()
in (let c5 = (op_Bar_Greater_Greater d4 56)
in (let _25_627 = ()
in (let _25_629 = ()
in (let _25_631 = ()
in (let d5 = (op_Bar_Plus b5 c5)
in (let r5 = (trim_2_56 d5)
in (let _25_635 = ()
in (let c6 = (op_Bar_Greater_Greater d5 56)
in (let _25_638 = ()
in (let _25_640 = ()
in (let _25_642 = ()
in (let _25_644 = ()
in (let d6 = (op_Bar_Plus b6 c6)
in (let r6 = (trim_2_56 d6)
in (let _25_648 = ()
in (let c7 = (op_Bar_Greater_Greater d6 56)
in (let _25_651 = ()
in (let _25_653 = ()
in (let _25_655 = ()
in (let _25_657 = ()
in (let d7 = (op_Bar_Plus b7 c7)
in (let r7 = (trim_2_56 d7)
in (let _25_661 = ()
in (let c8 = (op_Bar_Greater_Greater d7 56)
in (let _25_664 = ()
in (let _25_666 = ()
in (let _25_668 = ()
in (let _25_670 = ()
in (let _25_672 = ()
in (full_update b r0 r1 r2 r3 r4 r5 r6 r7 c8)))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))

let lemma_helper_13 = (fun x y -> ())

let carry2_top_to_0 = (fun b -> (let h0 = (FStar_ST.get ())
in (let btop = (Bigint.index_wide b 8)
in (let b0 = (Bigint.index_wide b 0)
in (let b4 = (Bigint.index_wide b 4)
in (let _25_691 = ()
in (let _25_693 = ()
in (let _25_695 = (Bigint.upd_wide b 0 (op_Bar_Plus b0 btop))
in (let _25_697 = (Bigint.upd_wide b 4 (op_Bar_Plus b4 btop))
in (let h1 = (FStar_ST.get ())
in ()))))))))))

let lemma_helper_14 = (fun x y -> ())

let lemma_helper_15 = (fun x -> ())

let lemma_helper_16 = (fun x y -> ())

let full_update2 = (fun b r0 r1 r2 r3 r4 r5 -> (let h0 = (FStar_ST.get ())
in (let _25_738 = (Bigint.upd_wide b 0 r0)
in (let h1 = (FStar_ST.get ())
in (let _25_741 = ()
in (let _25_743 = (Bigint.upd_wide b 1 r1)
in (let h2 = (FStar_ST.get ())
in (let _25_746 = ()
in (let _25_748 = (Bigint.upd_wide b 2 r2)
in (let h3 = (FStar_ST.get ())
in (let _25_751 = ()
in (let _25_753 = (Bigint.upd_wide b 3 r3)
in (let h4 = (FStar_ST.get ())
in (let _25_756 = ()
in (let _25_758 = (Bigint.upd_wide b 4 r4)
in (let h5 = (FStar_ST.get ())
in (let _25_761 = ()
in (let _25_763 = (Bigint.upd_wide b 5 r5)
in (let h6 = (FStar_ST.get ())
in ())))))))))))))))))))

let carry3 = (fun b -> (let h0 = (FStar_ST.get ())
in (let b0 = (Bigint.index_wide b 0)
in (let b1 = (Bigint.index_wide b 1)
in (let b2 = (Bigint.index_wide b 2)
in (let b3 = (Bigint.index_wide b 3)
in (let b4 = (Bigint.index_wide b 4)
in (let b5 = (Bigint.index_wide b 5)
in (let r0 = (trim_2_56 b0)
in (let c1 = (op_Bar_Greater_Greater b0 56)
in (let _25_782 = ()
in (let _25_784 = ()
in (let _25_786 = ()
in (let d1 = (op_Bar_Plus b1 c1)
in (let r1 = (trim_2_56 d1)
in (let c2 = (op_Bar_Greater_Greater d1 56)
in (let _25_791 = ()
in (let _25_793 = ()
in (let _25_795 = ()
in (let _25_797 = ()
in (let d2 = (op_Bar_Plus b2 c2)
in (let r2 = (trim_2_56 d2)
in (let c3 = (op_Bar_Greater_Greater d2 56)
in (let _25_802 = ()
in (let _25_804 = ()
in (let _25_806 = ()
in (let _25_808 = ()
in (let d3 = (op_Bar_Plus b3 c3)
in (let r3 = (trim_2_56 d3)
in (let _25_812 = ()
in (let c4 = (op_Bar_Greater_Greater d3 56)
in (let _25_815 = ()
in (let _25_817 = ()
in (let _25_819 = ()
in (let _25_821 = ()
in (let d4 = (op_Bar_Plus b4 c4)
in (let r4 = (trim_2_56 d4)
in (let c5 = (op_Bar_Greater_Greater d4 56)
in (let _25_826 = ()
in (let _25_828 = ()
in (let _25_830 = ()
in (let _25_832 = ()
in (let _25_834 = ()
in (let _25_836 = ()
in (let _25_838 = ()
in (let d5 = (op_Bar_Plus b5 c5)
in (let _25_841 = (full_update2 b r0 r1 r2 r3 r4 d5)
in (let h1 = (FStar_ST.get ())
in ()))))))))))))))))))))))))))))))))))))))))))))))))

let lemma_helper_4 = (fun x y -> ())

let lemma_helper_5 = (fun h0 h1 b -> ())

let upd_lemma_2 = (fun h0 h1 b idx x -> ())

let upd_lemma_3 = (fun h0 h1 h2 b idx x -> ())

let freduce_degree = (fun b -> (let h0 = (FStar_ST.get ())
in (let _25_886 = (freduce_degree_1 b)
in (let h1 = (FStar_ST.get ())
in (let _25_889 = ()
in (let _25_891 = (freduce_degree_2 b)
in (let h2 = (FStar_ST.get ())
in (let _25_894 = ()
in (let _25_896 = ()
in (let _25_898 = (Bigint.upd_wide b 8 UInt.zero_wide)
in (let h3 = (FStar_ST.get ())
in ())))))))))))

let freduce_coefficients = (fun b -> (let h0 = (FStar_ST.get ())
in (let _25_913 = (Bigint.upd_wide b Parameters.norm_length UInt.zero_wide)
in (let h1 = (FStar_ST.get ())
in (let _25_916 = ()
in (let _25_918 = ()
in (let _25_920 = (carry b 0)
in (let _25_922 = (carry_top_to_0 b)
in (let h2 = (FStar_ST.get ())
in (let _25_925 = (Bigint.upd_wide b Parameters.norm_length UInt.zero_wide)
in (let h3 = (FStar_ST.get ())
in (let _25_928 = ()
in (let _25_930 = (carry2 b)
in (let _25_932 = (carry2_top_to_0 b)
in (carry3 b)))))))))))))))

let normalize = (fun b -> (let _25_941 = ()
in (let two56m1 = (UInt.to_limb "0xffffffffffffff")
in (let two56m2 = (UInt.to_limb "0xfffffffffffffe")
in (let b7 = (Bigint.index_limb b 7)
in (let b6 = (Bigint.index_limb b 6)
in (let b5 = (Bigint.index_limb b 5)
in (let b4 = (Bigint.index_limb b 4)
in (let b3 = (Bigint.index_limb b 3)
in (let b2 = (Bigint.index_limb b 2)
in (let b1 = (Bigint.index_limb b 1)
in (let b0 = (Bigint.index_limb b 0)
in (let mask = (UInt.eq_limb b7 two56m1)
in (let mask = (UInt.log_and_limb mask (UInt.eq_limb b6 two56m1))
in (let mask = (UInt.log_and_limb mask (UInt.eq_limb b5 two56m1))
in (let mask1 = (UInt.log_and_limb mask (UInt.eq_limb b4 two56m2))
in (let mask1 = (UInt.log_and_limb mask1 (UInt.eq_limb b3 two56m1))
in (let mask1 = (UInt.log_and_limb mask1 (UInt.eq_limb b2 two56m1))
in (let mask1 = (UInt.log_and_limb mask1 (UInt.eq_limb b1 two56m1))
in (let mask1 = (UInt.log_and_limb mask1 (UInt.eq_limb b0 two56m1))
in (let mask2 = (UInt.log_and_limb mask (UInt.eq_limb b4 two56m1))
in (let mask = (UInt.log_or_limb mask1 mask2)
in (let mask' = (UInt.log_not_limb mask)
in (let _25_964 = (Bigint.upd_limb b 7 (UInt.log_and_limb b7 mask'))
in (let _25_966 = (Bigint.upd_limb b 6 (UInt.log_and_limb b6 mask'))
in (let _25_968 = (Bigint.upd_limb b 5 (UInt.log_and_limb b5 mask'))
in (let b4' = (UInt.log_and_limb (UInt.log_xor_limb b4 (UInt.to_limb "0x1")) (UInt.to_limb "0x1"))
in (let _25_971 = (Bigint.upd_limb b 4 (UInt.log_or_limb (UInt.log_and_limb b4' mask) (UInt.log_and_limb b4 mask')))
in (let _25_973 = (Bigint.upd_limb b 0 (UInt.add_limb b0 (UInt.log_and_limb mask UInt.one_limb)))
in (let mask3 = (UInt.to_limb "0xffffffffffffff")
in (let b0 = (Bigint.index_limb b 0)
in (let r0 = (UInt.log_and_limb b0 mask3)
in (let _25_978 = (Bigint.upd_limb b 0 r0)
in (let c = (UInt.shift_right_limb b0 56)
in (let b1 = (Bigint.index_limb b 1)
in (let _25_982 = (Bigint.upd_limb b 1 (UInt.add_limb b1 c))
in (let b1 = (Bigint.index_limb b 1)
in (let r1 = (UInt.log_and_limb b1 mask3)
in (let _25_986 = (Bigint.upd_limb b 1 r1)
in (let c = (UInt.shift_right_limb b1 56)
in (let b2 = (Bigint.index_limb b 2)
in (let _25_990 = (Bigint.upd_limb b 2 (UInt.add_limb b2 c))
in (let b2 = (Bigint.index_limb b 2)
in (let r2 = (UInt.log_and_limb b2 mask3)
in (let _25_994 = (Bigint.upd_limb b 2 r2)
in (let c = (UInt.shift_right_limb b2 56)
in (let b3 = (Bigint.index_limb b 3)
in (let _25_998 = (Bigint.upd_limb b 3 (UInt.add_limb b3 c))
in (let b3 = (Bigint.index_limb b 3)
in (let r3 = (UInt.log_and_limb b3 mask3)
in (let _25_1002 = (Bigint.upd_limb b 3 r3)
in (let c = (UInt.shift_right_limb b3 56)
in (let b4 = (Bigint.index_limb b 4)
in (let _25_1006 = (Bigint.upd_limb b 4 (UInt.add_limb b4 c))
in (let b4 = (Bigint.index_limb b 4)
in (Bigint.upd_limb b 4 (UInt.log_or_limb (UInt.log_and_limb (UInt.log_and_limb UInt.one_limb b4) mask) (UInt.log_and_limb b4 mask'))))))))))))))))))))))))))))))))))))))))))))))))))))))))))

let lemmma_bigzero_0 = (fun _25_1011 -> ())

let add_big_zero = (fun b -> (let _25_1025 = ()
in (let h0 = (FStar_ST.get ())
in (let two57m2 = (UInt.to_limb "0x1fffffffffffffe")
in (let two57m4 = (UInt.to_limb "0x1fffffffffffffc")
in (let _25_1030 = ()
in (let _25_1032 = ()
in (let b0 = (Bigint.index_limb b 0)
in (let b1 = (Bigint.index_limb b 1)
in (let b2 = (Bigint.index_limb b 2)
in (let b3 = (Bigint.index_limb b 3)
in (let b4 = (Bigint.index_limb b 4)
in (let b5 = (Bigint.index_limb b 5)
in (let b6 = (Bigint.index_limb b 6)
in (let b7 = (Bigint.index_limb b 7)
in (let _25_1042 = (Bigint.upd_limb b 0 (UInt.add_limb b0 two57m2))
in (let _25_1044 = (Bigint.upd_limb b 1 (UInt.add_limb b1 two57m2))
in (let _25_1046 = (Bigint.upd_limb b 2 (UInt.add_limb b2 two57m2))
in (let _25_1048 = (Bigint.upd_limb b 3 (UInt.add_limb b3 two57m2))
in (let _25_1050 = (Bigint.upd_limb b 4 (UInt.add_limb b4 two57m4))
in (let _25_1052 = (Bigint.upd_limb b 5 (UInt.add_limb b5 two57m2))
in (let _25_1054 = (Bigint.upd_limb b 6 (UInt.add_limb b6 two57m2))
in (let _25_1056 = (Bigint.upd_limb b 7 (UInt.add_limb b7 two57m2))
in (let h1 = (FStar_ST.get ())
in ()))))))))))))))))))))))))




