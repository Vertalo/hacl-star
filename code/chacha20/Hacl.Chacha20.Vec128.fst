module Hacl.Chacha20.Vec128

open Hacl.Meta.Chacha20.Vec

private
let double_round_128 = Hacl.Impl.Chacha20.Core32xN.double_round #4
private
let chacha20_core_128 = chacha20_core_higher #4 double_round_128
private
let chacha20_init_128 = Hacl.Impl.Chacha20.Vec.chacha20_init #4

let chacha20_encrypt_128 = chacha20_encrypt_higher #4 chacha20_init_128 chacha20_core_128
let chacha20_decrypt_128 = chacha20_decrypt_higher #4 chacha20_init_128 chacha20_core_128