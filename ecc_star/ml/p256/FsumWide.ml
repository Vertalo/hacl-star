
open Prims
let gfsum_index_lemma = (fun h0 h1 h2 a a_idx b b_idx len ctr -> ())

let fsum_index_lemma = (fun h0 h1 h2 a a_idx b b_idx len ctr -> ())

let rec fsum_index = (fun a a_idx b b_idx len ctr -> (let h0 = (FStar_ST.get ())
in (match ((len - ctr)) with
| 0 -> begin
()
end
| _27_158 -> begin
(let i = ctr
in (let _27_160 = ()
in (let _27_162 = ()
in (let ai = (Bigint.index_wide a (i + a_idx))
in (let bi = (Bigint.index_wide b (i + b_idx))
in (let _27_166 = ()
in (let _27_168 = ()
in (let z = (UInt.add_wide ai bi)
in (let _27_171 = (Bigint.upd_wide a (a_idx + i) z)
in (let h1 = (FStar_ST.get ())
in (let _27_174 = ()
in (let _27_176 = ()
in (let _27_178 = ()
in (let _27_180 = ()
in (let _27_182 = ()
in (let _27_185 = ()
in (let _27_187 = ()
in (let _27_189 = (fsum_index a a_idx b b_idx len (ctr + 1))
in (let h2 = (FStar_ST.get ())
in ())))))))))))))))))))
end)))

let gaddition_lemma_aux = (fun h0 h1 a b len -> ())

let addition_lemma_aux = (fun h0 h1 a b len -> ())

let rec addition_lemma = (fun h0 h1 a b len -> ())

let addition_max_value_lemma = (fun h0 h1 a b c -> ())

let max_value_lemma = (fun h a m -> ())

let addition_max_value_lemma_extended = (fun h0 h1 a b c idx len -> ())

let gauxiliary_lemma_2 = (fun ha a hb b i -> ())

let auxiliary_lemma_2 = (fun ha a hb b i -> ())

let auxiliary_lemma_0 = (fun ha a hb b -> ())

let auxiliary_lemma_1 = (fun h0 h1 b -> ())

let auxiliary_lemma_3 = (fun h0 h1 a b -> ())

let fsum' = (fun a b -> (let _27_410 = ()
in (let h0 = (FStar_ST.get ())
in (let _27_413 = ()
in (let _27_415 = (fsum_index a 0 b 0 Parameters.norm_length 0)
in (let h1 = (FStar_ST.get ())
in ()))))))




