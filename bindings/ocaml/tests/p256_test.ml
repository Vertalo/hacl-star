open Test_utils

type 'a ecdsa_test =
  { name : string ; sk : 'a ; pk : 'a ; msg : 'a ; k : 'a ; expected_sig : 'a }

type 'a compression_test =
  { name : string; raw : 'a; compressed : 'a; uncompressed : 'a }

let tests = [
  {name = "Test 1";
   msg = Bytes.of_string "\x1c\xcb\xe9\x1c\x07\x5f\xc7\xf4\xf0\x33\xbf\xa2\x48\xdb\x8f\xcc\xd3\x56\x5d\xe9\x4b\xbf\xb1\x2f\x3c\x59\xff\x46\xc2\x71\xbf\x83";
   sk = Bytes.of_string "\x51\x9b\x42\x3d\x71\x5f\x8b\x58\x1f\x4f\xa8\xee\x59\xf4\x77\x1a\x5b\x44\xc8\x13\x0b\x4e\x3e\xac\xca\x54\xa5\x6d\xda\x72\xb4\x64";
   pk = Bytes.of_string "\x1c\xcb\xe9\x1c\x07\x5f\xc7\xf4\xf0\x33\xbf\xa2\x48\xdb\x8f\xcc\xd3\x56\x5d\xe9\x4b\xbf\xb1\x2f\x3c\x59\xff\x46\xc2\x71\xbf\x83\xce\x40\x14\xc6\x88\x11\xf9\xa2\x1a\x1f\xdb\x2c\x0e\x61\x13\xe0\x6d\xb7\xca\x93\xb7\x40\x4e\x78\xdc\x7c\xcd\x5c\xa8\x9a\x4c\xa9";
   k = Bytes.of_string "\x94\xa1\xbb\xb1\x4b\x90\x6a\x61\xa2\x80\xf2\x45\xf9\xe9\x3c\x7f\x3b\x4a\x62\x47\x82\x4f\x5d\x33\xb9\x67\x07\x87\x64\x2a\x68\xde";
   expected_sig = Bytes.of_string "\xf3\xac\x80\x61\xb5\x14\x79\x5b\x88\x43\xe3\xd6\x62\x95\x27\xed\x2a\xfd\x6b\x1f\x6a\x55\x5a\x7a\xca\xbb\x5e\x6f\x79\xc8\xc2\xac\xcf\xa7\x40\xfe\xc7\x67\x96\xd2\xe3\x92\x16\xbe\x7e\xbf\x58\x0e\xa3\xc0\xef\x4b\xb0\x0a\xb2\xe7\xe4\x20\x84\x34\xf4\x5f\x8c\x9c"
  }
]

let tests_sha256 = [
  { name = "Test 1";
    msg = Bytes.of_string "\x59\x05\x23\x88\x77\xc7\x74\x21\xf7\x3e\x43\xee\x3d\xa6\xf2\xd9\xe2\xcc\xad\x5f\xc9\x42\xdc\xec\x0c\xbd\x25\x48\x29\x35\xfa\xaf\x41\x69\x83\xfe\x16\x5b\x1a\x04\x5e\xe2\xbc\xd2\xe6\xdc\xa3\xbd\xf4\x6c\x43\x10\xa7\x46\x1f\x9a\x37\x96\x0c\xa6\x72\xd3\xfe\xb5\x47\x3e\x25\x36\x05\xfb\x1d\xdf\xd2\x80\x65\xb5\x3c\xb5\x85\x8a\x8a\xd2\x81\x75\xbf\x9b\xd3\x86\xa5\xe4\x71\xea\x7a\x65\xc1\x7c\xc9\x34\xa9\xd7\x91\xe9\x14\x91\xeb\x37\x54\xd0\x37\x99\x79\x0f\xe2\xd3\x08\xd1\x61\x46\xd5\xc9\xb0\xd0\xde\xbd\x97\xd7\x9c\xe8";
    sk    = Bytes.of_string "\x51\x9b\x42\x3d\x71\x5f\x8b\x58\x1f\x4f\xa8\xee\x59\xf4\x77\x1a\x5b\x44\xc8\x13\x0b\x4e\x3e\xac\xca\x54\xa5\x6d\xda\x72\xb4\x64";
    pk  = Bytes.of_string "\x1c\xcb\xe9\x1c\x07\x5f\xc7\xf4\xf0\x33\xbf\xa2\x48\xdb\x8f\xcc\xd3\x56\x5d\xe9\x4b\xbf\xb1\x2f\x3c\x59\xff\x46\xc2\x71\xbf\x83\xce\x40\x14\xc6\x88\x11\xf9\xa2\x1a\x1f\xdb\x2c\x0e\x61\x13\xe0\x6d\xb7\xca\x93\xb7\x40\x4e\x78\xdc\x7c\xcd\x5c\xa8\x9a\x4c\xa9";
    k    = Bytes.of_string "\x94\xa1\xbb\xb1\x4b\x90\x6a\x61\xa2\x80\xf2\x45\xf9\xe9\x3c\x7f\x3b\x4a\x62\x47\x82\x4f\x5d\x33\xb9\x67\x07\x87\x64\x2a\x68\xde";
    expected_sig   = Bytes.of_string "\xf3\xac\x80\x61\xb5\x14\x79\x5b\x88\x43\xe3\xd6\x62\x95\x27\xed\x2a\xfd\x6b\x1f\x6a\x55\x5a\x7a\xca\xbb\x5e\x6f\x79\xc8\xc2\xac\x8b\xf7\x78\x19\xca\x05\xa6\xb2\x78\x6c\x76\x26\x2b\xf7\x37\x1c\xef\x97\xb2\x18\xe9\x6f\x17\x5a\x3c\xcd\xda\x2a\xcc\x05\x89\x03";
  };
  { name = "Test 2";
    msg = Bytes.of_string "\xc3\x5e\x2f\x09\x25\x53\xc5\x57\x72\x92\x6b\xdb\xe8\x7c\x97\x96\x82\x7d\x17\x02\x4d\xbb\x92\x33\xa5\x45\x36\x6e\x2e\x59\x87\xdd\x34\x4d\xeb\x72\xdf\x98\x71\x44\xb8\xc6\xc4\x3b\xc4\x1b\x65\x4b\x94\xcc\x85\x6e\x16\xb9\x6d\x7a\x82\x1c\x8e\xc0\x39\xb5\x03\xe3\xd8\x67\x28\xc4\x94\xa9\x67\xd8\x30\x11\xa0\xe0\x90\xb5\xd5\x4c\xd4\x7f\x4e\x36\x6c\x09\x12\xbc\x80\x8f\xbb\x2e\xa9\x6e\xfa\xc8\x8f\xb3\xeb\xec\x93\x42\x73\x8e\x22\x5f\x7c\x7c\x2b\x01\x1c\xe3\x75\xb5\x66\x21\xa2\x06\x42\xb4\xd3\x6e\x06\x0d\xb4\x52\x4a\xf1";
    sk    = Bytes.of_string "\x0f\x56\xdb\x78\xca\x46\x0b\x05\x5c\x50\x00\x64\x82\x4b\xed\x99\x9a\x25\xaa\xf4\x8e\xbb\x51\x9a\xc2\x01\x53\x7b\x85\x47\x98\x13";
    pk  = Bytes.of_string "\xe2\x66\xdd\xfd\xc1\x26\x68\xdb\x30\xd4\xca\x3e\x8f\x77\x49\x43\x2c\x41\x60\x44\xf2\xd2\xb8\xc1\x0b\xf3\xd4\x01\x2a\xef\xfa\x8a\xbf\xa8\x64\x04\xa2\xe9\xff\xe6\x7d\x47\xc5\x87\xef\x7a\x97\xa7\xf4\x56\xb8\x63\xb4\xd0\x2c\xfc\x69\x28\x97\x3a\xb5\xb1\xcb\x39";
    k    = Bytes.of_string "\x6d\x3e\x71\x88\x2c\x3b\x83\xb1\x56\xbb\x14\xe0\xab\x18\x4a\xa9\xfb\x72\x80\x68\xd3\xae\x9f\xac\x42\x11\x87\xae\x0b\x2f\x34\xc6";
    expected_sig   = Bytes.of_string "\x97\x6d\x3a\x4e\x9d\x23\x32\x6d\xc0\xba\xa9\xfa\x56\x0b\x7c\x4e\x53\xf4\x28\x64\xf5\x08\x48\x3a\x64\x73\xb6\xa1\x10\x79\xb2\xdb\x1b\x76\x6e\x9c\xeb\x71\xba\x6c\x01\xdc\xd4\x6e\x0a\xf4\x62\xcd\x4c\xfa\x65\x2a\xe5\x01\x7d\x45\x55\xb8\xee\xef\xe3\x6e\x19\x32";
  }
]

let tests_compression = [
  { name = "Test 1";
    raw = Bytes.of_string "\x70\x0c\x48\xf7\x7f\x56\x58\x4c\x5c\xc6\x32\xca\x65\x64\x0d\xb9\x1b\x6b\xac\xce\x3a\x4d\xf6\xb4\x2c\xe7\xcc\x83\x88\x33\xd2\x87\xdb\x71\xe5\x09\xe3\xfd\x9b\x06\x0d\xdb\x20\xba\x5c\x51\xdc\xc5\x94\x8d\x46\xfb\xf6\x40\xdf\xe0\x44\x17\x82\xca\xb8\x5f\xa4\xac";
    compressed = Bytes.of_string "\x02\x70\x0c\x48\xf7\x7f\x56\x58\x4c\x5c\xc6\x32\xca\x65\x64\x0d\xb9\x1b\x6b\xac\xce\x3a\x4d\xf6\xb4\x2c\xe7\xcc\x83\x88\x33\xd2\x87";
    uncompressed = Bytes.of_string "\x04\x70\x0c\x48\xf7\x7f\x56\x58\x4c\x5c\xc6\x32\xca\x65\x64\x0d\xb9\x1b\x6b\xac\xce\x3a\x4d\xf6\xb4\x2c\xe7\xcc\x83\x88\x33\xd2\x87\xdb\x71\xe5\x09\xe3\xfd\x9b\x06\x0d\xdb\x20\xba\x5c\x51\xdc\xc5\x94\x8d\x46\xfb\xf6\x40\xdf\xe0\x44\x17\x82\xca\xb8\x5f\xa4\xac";
  }
]

module MakeTests (M: SharedDefs.ECDSA) = struct
  let test_noalloc (v: Bytes.t ecdsa_test) t =
    let test_result = test_result (t ^ " (noalloc) " ^ v.name) in

    let pk = Test_utils.init_bytes 64 in
    assert (Hacl.P256.valid_sk ~sk:v.sk);
    if not (Hacl.P256.Noalloc.dh_initiator ~sk:v.sk ~pk) then
      test_result Failure "DH initiator";
    assert (Hacl.P256.valid_pk ~pk);
    if Bytes.compare pk v.pk <> 0 then
      test_result Failure "Key generation";

    let signature = Test_utils.init_bytes 64 in
    assert (M.sign_noalloc ~sk:v.sk ~pt:v.msg ~k:v.k ~signature);
    if Bytes.compare signature v.expected_sig = 0 then
      begin
        if M.verify ~pk:v.pk ~pt:v.msg ~signature then
          test_result Success ""
        else
          test_result Failure "Verification"
      end
    else
      test_result Failure "Signing"

  let test (v: Bytes.t ecdsa_test) t =
    let test_result = test_result (t ^ " " ^ v.name) in

    assert (Hacl.P256.valid_sk ~sk:v.sk);
    match Hacl.P256.dh_initiator ~sk:v.sk with
    | Some pk -> begin
        assert (Hacl.P256.valid_pk ~pk);
        if Bytes.compare pk v.pk <> 0 then
          test_result Failure "Key generation";

        match M.sign ~sk:v.sk ~pt:v.msg ~k:v.k with
        | Some signature ->
          if Bytes.compare signature v.expected_sig = 0 then
            begin
              if M.verify ~pk:v.pk ~pt:v.msg ~signature then
                test_result Success ""
              else
                test_result Failure "Verification"
            end
        | None ->
          test_result Failure "Signing"
      end
    | None -> test_result Failure "DH initiator"

  let run_tests name tests =
    List.iter (fun v -> test_noalloc v name) tests;
    List.iter (fun v -> test v name) tests
end

let test_p256_compression_noalloc (v: Bytes.t compression_test) =
  let test_result = test_result ("P-256 compression (noalloc) " ^ v.name) in

  let result = Test_utils.init_bytes 33 in
  Hacl.P256.Noalloc.raw_to_compressed ~p:v.raw ~result;
  if Bytes.compare result v.compressed <> 0 then
    test_result Failure "Hacl.P256.Noalloc.raw_to_compressed";

  let result = Test_utils.init_bytes 65 in
  Hacl.P256.Noalloc.raw_to_uncompressed ~p:v.raw ~result;
  if Bytes.compare result v.uncompressed <> 0 then
    test_result Failure "Hacl.P256.Noalloc.raw_to_uncompressed";

  let result = Test_utils.init_bytes 64 in
  assert (Hacl.P256.Noalloc.compressed_to_raw ~p:v.compressed ~result);
  if Bytes.compare result v.raw <> 0 then
    test_result Failure "Hacl.P256.Noalloc.compressed_to_raw";

  let result = Test_utils.init_bytes 64 in
  assert (Hacl.P256.Noalloc.uncompressed_to_raw ~p:v.uncompressed ~result);
  if Bytes.compare result v.raw <> 0 then
    test_result Failure "Hacl.P256.Noalloc.uncompressed_to_raw";

  test_result Success "P256 point compression/decompression"

let test_p256_compression (v: Bytes.t compression_test) =
  let test_result = test_result ("P-256 compression " ^ v.name) in

  let result = Hacl.P256.raw_to_compressed v.raw in
  if Bytes.compare result v.compressed <> 0 then
    test_result Failure "Hacl.P256.raw_to_compressed";

  let result = Hacl.P256.raw_to_uncompressed v.raw in
  if Bytes.compare result v.uncompressed <> 0 then
    test_result Failure "Hacl.P256.raw_to_uncompressed";

  (match Hacl.P256.compressed_to_raw v.compressed with
  | Some result ->
    if Bytes.compare result v.raw <> 0 then
      test_result Failure "Hacl.P256.compressed_to_raw"
  | None ->
    test_result Failure "Hacl.P256.compressed_to_raw");

  (match Hacl.P256.uncompressed_to_raw v.uncompressed with
  | Some result ->
    if Bytes.compare result v.raw <> 0 then
      test_result Failure "Hacl.P256.uncompressed_to_raw"
  | None ->
    test_result Failure "Hacl.P256.uncompressed_to_raw");

  test_result Success "P256 point compression/decompression"


let _ =
  let module Tests = MakeTests (Hacl.P256) in
  Tests.run_tests "Hacl.P256" tests;

  let module Tests = MakeTests (Hacl.P256.SHA2_256) in
  Tests.run_tests "Hacl.P256_SHA_256" tests_sha256;

  List.iter test_p256_compression_noalloc tests_compression;
  List.iter test_p256_compression tests_compression
