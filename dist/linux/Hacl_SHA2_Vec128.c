/* MIT License
 *
 * Copyright (c) 2016-2020 INRIA, CMU and Microsoft Corporation
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */


#include "Hacl_SHA2_Vec128.h"

static inline void
sha256_update4(K____u8__K____u8__K____u8___u8_ b, Lib_IntVector_Intrinsics_vec128 *hash)
{
  Lib_IntVector_Intrinsics_vec128 hash_old[8U];
  {
    u32 _i;
    for (_i = 0U; _i < (u32)8U; ++_i)
      hash_old[_i] = Lib_IntVector_Intrinsics_vec128_zero;
  }
  {
    Lib_IntVector_Intrinsics_vec128 ws[16U];
    {
      u32 _i;
      for (_i = 0U; _i < (u32)16U; ++_i)
        ws[_i] = Lib_IntVector_Intrinsics_vec128_zero;
    }
    {
      u8 *b3;
      u8 *b2;
      u8 *b10;
      u8 *b00;
      Lib_IntVector_Intrinsics_vec128 v00;
      Lib_IntVector_Intrinsics_vec128 v10;
      Lib_IntVector_Intrinsics_vec128 v20;
      Lib_IntVector_Intrinsics_vec128 v30;
      Lib_IntVector_Intrinsics_vec128 v0_;
      Lib_IntVector_Intrinsics_vec128 v1_;
      Lib_IntVector_Intrinsics_vec128 v2_;
      Lib_IntVector_Intrinsics_vec128 v3_;
      Lib_IntVector_Intrinsics_vec128 v0__;
      Lib_IntVector_Intrinsics_vec128 v1__;
      Lib_IntVector_Intrinsics_vec128 v2__;
      Lib_IntVector_Intrinsics_vec128 v3__;
      Lib_IntVector_Intrinsics_vec128 v0__0;
      Lib_IntVector_Intrinsics_vec128 v2__0;
      Lib_IntVector_Intrinsics_vec128 v1__0;
      Lib_IntVector_Intrinsics_vec128 v3__0;
      Lib_IntVector_Intrinsics_vec128 ws0;
      Lib_IntVector_Intrinsics_vec128 ws1;
      Lib_IntVector_Intrinsics_vec128 ws2;
      Lib_IntVector_Intrinsics_vec128 ws3;
      Lib_IntVector_Intrinsics_vec128 v01;
      Lib_IntVector_Intrinsics_vec128 v11;
      Lib_IntVector_Intrinsics_vec128 v21;
      Lib_IntVector_Intrinsics_vec128 v31;
      Lib_IntVector_Intrinsics_vec128 v0_0;
      Lib_IntVector_Intrinsics_vec128 v1_0;
      Lib_IntVector_Intrinsics_vec128 v2_0;
      Lib_IntVector_Intrinsics_vec128 v3_0;
      Lib_IntVector_Intrinsics_vec128 v0__1;
      Lib_IntVector_Intrinsics_vec128 v1__1;
      Lib_IntVector_Intrinsics_vec128 v2__1;
      Lib_IntVector_Intrinsics_vec128 v3__1;
      Lib_IntVector_Intrinsics_vec128 v0__2;
      Lib_IntVector_Intrinsics_vec128 v2__2;
      Lib_IntVector_Intrinsics_vec128 v1__2;
      Lib_IntVector_Intrinsics_vec128 v3__2;
      Lib_IntVector_Intrinsics_vec128 ws4;
      Lib_IntVector_Intrinsics_vec128 ws5;
      Lib_IntVector_Intrinsics_vec128 ws6;
      Lib_IntVector_Intrinsics_vec128 ws7;
      Lib_IntVector_Intrinsics_vec128 v02;
      Lib_IntVector_Intrinsics_vec128 v12;
      Lib_IntVector_Intrinsics_vec128 v22;
      Lib_IntVector_Intrinsics_vec128 v32;
      Lib_IntVector_Intrinsics_vec128 v0_1;
      Lib_IntVector_Intrinsics_vec128 v1_1;
      Lib_IntVector_Intrinsics_vec128 v2_1;
      Lib_IntVector_Intrinsics_vec128 v3_1;
      Lib_IntVector_Intrinsics_vec128 v0__3;
      Lib_IntVector_Intrinsics_vec128 v1__3;
      Lib_IntVector_Intrinsics_vec128 v2__3;
      Lib_IntVector_Intrinsics_vec128 v3__3;
      Lib_IntVector_Intrinsics_vec128 v0__4;
      Lib_IntVector_Intrinsics_vec128 v2__4;
      Lib_IntVector_Intrinsics_vec128 v1__4;
      Lib_IntVector_Intrinsics_vec128 v3__4;
      Lib_IntVector_Intrinsics_vec128 ws8;
      Lib_IntVector_Intrinsics_vec128 ws9;
      Lib_IntVector_Intrinsics_vec128 ws10;
      Lib_IntVector_Intrinsics_vec128 ws11;
      Lib_IntVector_Intrinsics_vec128 v0;
      Lib_IntVector_Intrinsics_vec128 v1;
      Lib_IntVector_Intrinsics_vec128 v2;
      Lib_IntVector_Intrinsics_vec128 v3;
      Lib_IntVector_Intrinsics_vec128 v0_2;
      Lib_IntVector_Intrinsics_vec128 v1_2;
      Lib_IntVector_Intrinsics_vec128 v2_2;
      Lib_IntVector_Intrinsics_vec128 v3_2;
      Lib_IntVector_Intrinsics_vec128 v0__5;
      Lib_IntVector_Intrinsics_vec128 v1__5;
      Lib_IntVector_Intrinsics_vec128 v2__5;
      Lib_IntVector_Intrinsics_vec128 v3__5;
      Lib_IntVector_Intrinsics_vec128 v0__6;
      Lib_IntVector_Intrinsics_vec128 v2__6;
      Lib_IntVector_Intrinsics_vec128 v1__6;
      Lib_IntVector_Intrinsics_vec128 v3__6;
      Lib_IntVector_Intrinsics_vec128 ws12;
      Lib_IntVector_Intrinsics_vec128 ws13;
      Lib_IntVector_Intrinsics_vec128 ws14;
      Lib_IntVector_Intrinsics_vec128 ws15;
      memcpy(hash_old, hash, (u32)8U * sizeof (hash[0U]));
      b3 = b.snd.snd.snd;
      b2 = b.snd.snd.fst;
      b10 = b.snd.fst;
      b00 = b.fst;
      ws[0U] = Lib_IntVector_Intrinsics_vec128_load32_be(b00);
      ws[1U] = Lib_IntVector_Intrinsics_vec128_load32_be(b10);
      ws[2U] = Lib_IntVector_Intrinsics_vec128_load32_be(b2);
      ws[3U] = Lib_IntVector_Intrinsics_vec128_load32_be(b3);
      ws[4U] = Lib_IntVector_Intrinsics_vec128_load32_be(b00 + (u32)16U);
      ws[5U] = Lib_IntVector_Intrinsics_vec128_load32_be(b10 + (u32)16U);
      ws[6U] = Lib_IntVector_Intrinsics_vec128_load32_be(b2 + (u32)16U);
      ws[7U] = Lib_IntVector_Intrinsics_vec128_load32_be(b3 + (u32)16U);
      ws[8U] = Lib_IntVector_Intrinsics_vec128_load32_be(b00 + (u32)32U);
      ws[9U] = Lib_IntVector_Intrinsics_vec128_load32_be(b10 + (u32)32U);
      ws[10U] = Lib_IntVector_Intrinsics_vec128_load32_be(b2 + (u32)32U);
      ws[11U] = Lib_IntVector_Intrinsics_vec128_load32_be(b3 + (u32)32U);
      ws[12U] = Lib_IntVector_Intrinsics_vec128_load32_be(b00 + (u32)48U);
      ws[13U] = Lib_IntVector_Intrinsics_vec128_load32_be(b10 + (u32)48U);
      ws[14U] = Lib_IntVector_Intrinsics_vec128_load32_be(b2 + (u32)48U);
      ws[15U] = Lib_IntVector_Intrinsics_vec128_load32_be(b3 + (u32)48U);
      v00 = ws[0U];
      v10 = ws[1U];
      v20 = ws[2U];
      v30 = ws[3U];
      v0_ = Lib_IntVector_Intrinsics_vec128_interleave_low32(v00, v10);
      v1_ = Lib_IntVector_Intrinsics_vec128_interleave_high32(v00, v10);
      v2_ = Lib_IntVector_Intrinsics_vec128_interleave_low32(v20, v30);
      v3_ = Lib_IntVector_Intrinsics_vec128_interleave_high32(v20, v30);
      v0__ = Lib_IntVector_Intrinsics_vec128_interleave_low64(v0_, v2_);
      v1__ = Lib_IntVector_Intrinsics_vec128_interleave_high64(v0_, v2_);
      v2__ = Lib_IntVector_Intrinsics_vec128_interleave_low64(v1_, v3_);
      v3__ = Lib_IntVector_Intrinsics_vec128_interleave_high64(v1_, v3_);
      v0__0 = v0__;
      v2__0 = v2__;
      v1__0 = v1__;
      v3__0 = v3__;
      ws0 = v0__0;
      ws1 = v1__0;
      ws2 = v2__0;
      ws3 = v3__0;
      v01 = ws[4U];
      v11 = ws[5U];
      v21 = ws[6U];
      v31 = ws[7U];
      v0_0 = Lib_IntVector_Intrinsics_vec128_interleave_low32(v01, v11);
      v1_0 = Lib_IntVector_Intrinsics_vec128_interleave_high32(v01, v11);
      v2_0 = Lib_IntVector_Intrinsics_vec128_interleave_low32(v21, v31);
      v3_0 = Lib_IntVector_Intrinsics_vec128_interleave_high32(v21, v31);
      v0__1 = Lib_IntVector_Intrinsics_vec128_interleave_low64(v0_0, v2_0);
      v1__1 = Lib_IntVector_Intrinsics_vec128_interleave_high64(v0_0, v2_0);
      v2__1 = Lib_IntVector_Intrinsics_vec128_interleave_low64(v1_0, v3_0);
      v3__1 = Lib_IntVector_Intrinsics_vec128_interleave_high64(v1_0, v3_0);
      v0__2 = v0__1;
      v2__2 = v2__1;
      v1__2 = v1__1;
      v3__2 = v3__1;
      ws4 = v0__2;
      ws5 = v1__2;
      ws6 = v2__2;
      ws7 = v3__2;
      v02 = ws[8U];
      v12 = ws[9U];
      v22 = ws[10U];
      v32 = ws[11U];
      v0_1 = Lib_IntVector_Intrinsics_vec128_interleave_low32(v02, v12);
      v1_1 = Lib_IntVector_Intrinsics_vec128_interleave_high32(v02, v12);
      v2_1 = Lib_IntVector_Intrinsics_vec128_interleave_low32(v22, v32);
      v3_1 = Lib_IntVector_Intrinsics_vec128_interleave_high32(v22, v32);
      v0__3 = Lib_IntVector_Intrinsics_vec128_interleave_low64(v0_1, v2_1);
      v1__3 = Lib_IntVector_Intrinsics_vec128_interleave_high64(v0_1, v2_1);
      v2__3 = Lib_IntVector_Intrinsics_vec128_interleave_low64(v1_1, v3_1);
      v3__3 = Lib_IntVector_Intrinsics_vec128_interleave_high64(v1_1, v3_1);
      v0__4 = v0__3;
      v2__4 = v2__3;
      v1__4 = v1__3;
      v3__4 = v3__3;
      ws8 = v0__4;
      ws9 = v1__4;
      ws10 = v2__4;
      ws11 = v3__4;
      v0 = ws[12U];
      v1 = ws[13U];
      v2 = ws[14U];
      v3 = ws[15U];
      v0_2 = Lib_IntVector_Intrinsics_vec128_interleave_low32(v0, v1);
      v1_2 = Lib_IntVector_Intrinsics_vec128_interleave_high32(v0, v1);
      v2_2 = Lib_IntVector_Intrinsics_vec128_interleave_low32(v2, v3);
      v3_2 = Lib_IntVector_Intrinsics_vec128_interleave_high32(v2, v3);
      v0__5 = Lib_IntVector_Intrinsics_vec128_interleave_low64(v0_2, v2_2);
      v1__5 = Lib_IntVector_Intrinsics_vec128_interleave_high64(v0_2, v2_2);
      v2__5 = Lib_IntVector_Intrinsics_vec128_interleave_low64(v1_2, v3_2);
      v3__5 = Lib_IntVector_Intrinsics_vec128_interleave_high64(v1_2, v3_2);
      v0__6 = v0__5;
      v2__6 = v2__5;
      v1__6 = v1__5;
      v3__6 = v3__5;
      ws12 = v0__6;
      ws13 = v1__6;
      ws14 = v2__6;
      ws15 = v3__6;
      ws[0U] = ws0;
      ws[1U] = ws1;
      ws[2U] = ws2;
      ws[3U] = ws3;
      ws[4U] = ws4;
      ws[5U] = ws5;
      ws[6U] = ws6;
      ws[7U] = ws7;
      ws[8U] = ws8;
      ws[9U] = ws9;
      ws[10U] = ws10;
      ws[11U] = ws11;
      ws[12U] = ws12;
      ws[13U] = ws13;
      ws[14U] = ws14;
      ws[15U] = ws15;
      {
        u32 i0;
        for (i0 = (u32)0U; i0 < (u32)4U; i0++)
        {
          {
            u32 i;
            for (i = (u32)0U; i < (u32)16U; i++)
            {
              u32 k_t = Hacl_Impl_SHA2_Generic_k224_256[(u32)16U * i0 + i];
              Lib_IntVector_Intrinsics_vec128 ws_t = ws[i];
              Lib_IntVector_Intrinsics_vec128 a0 = hash[0U];
              Lib_IntVector_Intrinsics_vec128 b0 = hash[1U];
              Lib_IntVector_Intrinsics_vec128 c0 = hash[2U];
              Lib_IntVector_Intrinsics_vec128 d0 = hash[3U];
              Lib_IntVector_Intrinsics_vec128 e0 = hash[4U];
              Lib_IntVector_Intrinsics_vec128 f0 = hash[5U];
              Lib_IntVector_Intrinsics_vec128 g0 = hash[6U];
              Lib_IntVector_Intrinsics_vec128 h02 = hash[7U];
              Lib_IntVector_Intrinsics_vec128 k_e_t = Lib_IntVector_Intrinsics_vec128_load32(k_t);
              Lib_IntVector_Intrinsics_vec128
              t1 =
                Lib_IntVector_Intrinsics_vec128_add32(Lib_IntVector_Intrinsics_vec128_add32(Lib_IntVector_Intrinsics_vec128_add32(Lib_IntVector_Intrinsics_vec128_add32(h02,
                        Lib_IntVector_Intrinsics_vec128_xor(Lib_IntVector_Intrinsics_vec128_rotate_right32(e0,
                            (u32)6U),
                          Lib_IntVector_Intrinsics_vec128_xor(Lib_IntVector_Intrinsics_vec128_rotate_right32(e0,
                              (u32)11U),
                            Lib_IntVector_Intrinsics_vec128_rotate_right32(e0, (u32)25U)))),
                      Lib_IntVector_Intrinsics_vec128_xor(Lib_IntVector_Intrinsics_vec128_and(e0,
                          f0),
                        Lib_IntVector_Intrinsics_vec128_and(Lib_IntVector_Intrinsics_vec128_lognot(e0),
                          g0))),
                    k_e_t),
                  ws_t);
              Lib_IntVector_Intrinsics_vec128
              t2 =
                Lib_IntVector_Intrinsics_vec128_add32(Lib_IntVector_Intrinsics_vec128_xor(Lib_IntVector_Intrinsics_vec128_rotate_right32(a0,
                      (u32)2U),
                    Lib_IntVector_Intrinsics_vec128_xor(Lib_IntVector_Intrinsics_vec128_rotate_right32(a0,
                        (u32)13U),
                      Lib_IntVector_Intrinsics_vec128_rotate_right32(a0, (u32)22U))),
                  Lib_IntVector_Intrinsics_vec128_xor(Lib_IntVector_Intrinsics_vec128_and(a0, b0),
                    Lib_IntVector_Intrinsics_vec128_xor(Lib_IntVector_Intrinsics_vec128_and(a0, c0),
                      Lib_IntVector_Intrinsics_vec128_and(b0, c0))));
              Lib_IntVector_Intrinsics_vec128 a1 = Lib_IntVector_Intrinsics_vec128_add32(t1, t2);
              Lib_IntVector_Intrinsics_vec128 b1 = a0;
              Lib_IntVector_Intrinsics_vec128 c1 = b0;
              Lib_IntVector_Intrinsics_vec128 d1 = c0;
              Lib_IntVector_Intrinsics_vec128 e1 = Lib_IntVector_Intrinsics_vec128_add32(d0, t1);
              Lib_IntVector_Intrinsics_vec128 f1 = e0;
              Lib_IntVector_Intrinsics_vec128 g1 = f0;
              Lib_IntVector_Intrinsics_vec128 h12 = g0;
              hash[0U] = a1;
              hash[1U] = b1;
              hash[2U] = c1;
              hash[3U] = d1;
              hash[4U] = e1;
              hash[5U] = f1;
              hash[6U] = g1;
              hash[7U] = h12;
            }
          }
          if (i0 < (u32)4U - (u32)1U)
          {
            u32 i;
            for (i = (u32)0U; i < (u32)16U; i++)
            {
              Lib_IntVector_Intrinsics_vec128 t16 = ws[i];
              Lib_IntVector_Intrinsics_vec128 t15 = ws[(i + (u32)1U) % (u32)16U];
              Lib_IntVector_Intrinsics_vec128 t7 = ws[(i + (u32)9U) % (u32)16U];
              Lib_IntVector_Intrinsics_vec128 t2 = ws[(i + (u32)14U) % (u32)16U];
              Lib_IntVector_Intrinsics_vec128
              s1 =
                Lib_IntVector_Intrinsics_vec128_xor(Lib_IntVector_Intrinsics_vec128_rotate_right32(t2,
                    (u32)17U),
                  Lib_IntVector_Intrinsics_vec128_xor(Lib_IntVector_Intrinsics_vec128_rotate_right32(t2,
                      (u32)19U),
                    Lib_IntVector_Intrinsics_vec128_shift_right32(t2, (u32)10U)));
              Lib_IntVector_Intrinsics_vec128
              s0 =
                Lib_IntVector_Intrinsics_vec128_xor(Lib_IntVector_Intrinsics_vec128_rotate_right32(t15,
                    (u32)7U),
                  Lib_IntVector_Intrinsics_vec128_xor(Lib_IntVector_Intrinsics_vec128_rotate_right32(t15,
                      (u32)18U),
                    Lib_IntVector_Intrinsics_vec128_shift_right32(t15, (u32)3U)));
              ws[i] =
                Lib_IntVector_Intrinsics_vec128_add32(Lib_IntVector_Intrinsics_vec128_add32(Lib_IntVector_Intrinsics_vec128_add32(s1,
                      t7),
                    s0),
                  t16);
            }
          }
        }
      }
      {
        u32 i;
        for (i = (u32)0U; i < (u32)8U; i++)
        {
          Lib_IntVector_Intrinsics_vec128 *os = hash;
          Lib_IntVector_Intrinsics_vec128
          x = Lib_IntVector_Intrinsics_vec128_add32(hash[i], hash_old[i]);
          os[i] = x;
        }
      }
    }
  }
}

void
Hacl_SHA2_Vec128_sha256_4(
  u8 *r0,
  u8 *r1,
  u8 *r2,
  u8 *r3,
  u32 len,
  u8 *b0,
  u8 *b1,
  u8 *b2,
  u8 *b3
)
{
  K____u8__K____u8__K____u8___u8_
  ib = { .fst = b0, .snd = { .fst = b1, .snd = { .fst = b2, .snd = b3 } } };
  K____u8__K____u8__K____u8___u8_
  rb = { .fst = r0, .snd = { .fst = r1, .snd = { .fst = r2, .snd = r3 } } };
  Lib_IntVector_Intrinsics_vec128 st[8U];
  {
    u32 _i;
    for (_i = 0U; _i < (u32)8U; ++_i)
      st[_i] = Lib_IntVector_Intrinsics_vec128_zero;
  }
  {
    u32 rem;
    u64 len_;
    u32 blocks0;
    u32 rem1;
    u8 *b310;
    u8 *b210;
    u8 *b110;
    u8 *b010;
    u8 *bl0;
    u8 *bl10;
    u8 *bl20;
    u8 *bl30;
    K____u8__K____u8__K____u8___u8_ lb;
    {
      u32 i;
      for (i = (u32)0U; i < (u32)8U; i++)
      {
        Lib_IntVector_Intrinsics_vec128 *os = st;
        u32 hi = Hacl_Impl_SHA2_Generic_h256[i];
        Lib_IntVector_Intrinsics_vec128 x = Lib_IntVector_Intrinsics_vec128_load32(hi);
        os[i] = x;
      }
    }
    rem = len % (u32)64U;
    len_ = (u64)len;
    blocks0 = len / (u32)64U;
    {
      u32 i;
      for (i = (u32)0U; i < blocks0; i++)
      {
        u8 *b31 = ib.snd.snd.snd;
        u8 *b21 = ib.snd.snd.fst;
        u8 *b11 = ib.snd.fst;
        u8 *b01 = ib.fst;
        u8 *bl00 = b01 + i * (u32)64U;
        u8 *bl1 = b11 + i * (u32)64U;
        u8 *bl2 = b21 + i * (u32)64U;
        u8 *bl3 = b31 + i * (u32)64U;
        K____u8__K____u8__K____u8___u8_
        mb = { .fst = bl00, .snd = { .fst = bl1, .snd = { .fst = bl2, .snd = bl3 } } };
        sha256_update4(mb, st);
      }
    }
    rem1 = len % (u32)64U;
    b310 = ib.snd.snd.snd;
    b210 = ib.snd.snd.fst;
    b110 = ib.snd.fst;
    b010 = ib.fst;
    bl0 = b010 + len - rem1;
    bl10 = b110 + len - rem1;
    bl20 = b210 + len - rem1;
    bl30 = b310 + len - rem1;
    lb =
      (
        (K____u8__K____u8__K____u8___u8_){
          .fst = bl0,
          .snd = { .fst = bl10, .snd = { .fst = bl20, .snd = bl30 } }
        }
      );
    {
      u32 blocks;
      if (rem + (u32)8U + (u32)1U <= (u32)64U)
        blocks = (u32)1U;
      else
        blocks = (u32)2U;
      {
        u32 fin = blocks * (u32)64U;
        u8 last[512U] = { 0U };
        u8 totlen_buf[8U] = { 0U };
        u64 total_len_bits = len_ << (u32)3U;
        u8 *b311;
        u8 *b211;
        u8 *b111;
        u8 *b011;
        u8 *last00;
        u8 *last10;
        u8 *last2;
        u8 *last3;
        u8 *last010;
        u8 *last110;
        K____u8___u8_ scrut0;
        u8 *l00;
        u8 *l01;
        u8 *last011;
        u8 *last111;
        K____u8___u8_ scrut1;
        u8 *l10;
        u8 *l11;
        u8 *last012;
        u8 *last112;
        K____u8___u8_ scrut2;
        u8 *l20;
        u8 *l21;
        u8 *last01;
        u8 *last11;
        K____u8___u8_ scrut3;
        u8 *l30;
        u8 *l31;
        K____u8__K____u8__K____u8___u8_ mb0;
        K____u8__K____u8__K____u8___u8_ mb1;
        K___K____u8__K____u8__K____u8___u8__K____u8__K____u8__K____u8___u8_ scrut;
        K____u8__K____u8__K____u8___u8_ last0;
        K____u8__K____u8__K____u8___u8_ last1;
        store64_be(totlen_buf, total_len_bits);
        b311 = lb.snd.snd.snd;
        b211 = lb.snd.snd.fst;
        b111 = lb.snd.fst;
        b011 = lb.fst;
        last00 = last;
        last10 = last + (u32)128U;
        last2 = last + (u32)256U;
        last3 = last + (u32)384U;
        memcpy(last00, b011, rem * sizeof (b011[0U]));
        last00[rem] = (u8)0x80U;
        memcpy(last00 + fin - (u32)8U, totlen_buf, (u32)8U * sizeof (totlen_buf[0U]));
        last010 = last00;
        last110 = last00 + (u32)64U;
        scrut0 = ((K____u8___u8_){ .fst = last010, .snd = last110 });
        l00 = scrut0.fst;
        l01 = scrut0.snd;
        memcpy(last10, b111, rem * sizeof (b111[0U]));
        last10[rem] = (u8)0x80U;
        memcpy(last10 + fin - (u32)8U, totlen_buf, (u32)8U * sizeof (totlen_buf[0U]));
        last011 = last10;
        last111 = last10 + (u32)64U;
        scrut1 = ((K____u8___u8_){ .fst = last011, .snd = last111 });
        l10 = scrut1.fst;
        l11 = scrut1.snd;
        memcpy(last2, b211, rem * sizeof (b211[0U]));
        last2[rem] = (u8)0x80U;
        memcpy(last2 + fin - (u32)8U, totlen_buf, (u32)8U * sizeof (totlen_buf[0U]));
        last012 = last2;
        last112 = last2 + (u32)64U;
        scrut2 = ((K____u8___u8_){ .fst = last012, .snd = last112 });
        l20 = scrut2.fst;
        l21 = scrut2.snd;
        memcpy(last3, b311, rem * sizeof (b311[0U]));
        last3[rem] = (u8)0x80U;
        memcpy(last3 + fin - (u32)8U, totlen_buf, (u32)8U * sizeof (totlen_buf[0U]));
        last01 = last3;
        last11 = last3 + (u32)64U;
        scrut3 = ((K____u8___u8_){ .fst = last01, .snd = last11 });
        l30 = scrut3.fst;
        l31 = scrut3.snd;
        mb0 =
          (
            (K____u8__K____u8__K____u8___u8_){
              .fst = l00,
              .snd = { .fst = l10, .snd = { .fst = l20, .snd = l30 } }
            }
          );
        mb1 =
          (
            (K____u8__K____u8__K____u8___u8_){
              .fst = l01,
              .snd = { .fst = l11, .snd = { .fst = l21, .snd = l31 } }
            }
          );
        scrut =
          (
            (K___K____u8__K____u8__K____u8___u8__K____u8__K____u8__K____u8___u8_){
              .fst = mb0,
              .snd = mb1
            }
          );
        last0 = scrut.fst;
        last1 = scrut.snd;
        sha256_update4(last0, st);
        if (blocks > (u32)1U)
          sha256_update4(last1, st);
        KRML_CHECK_SIZE(sizeof (u8), (u32)4U * (u32)8U * (u32)4U);
        {
          u8 hbuf[(u32)4U * (u32)8U * (u32)4U];
          memset(hbuf, 0U, (u32)4U * (u32)8U * (u32)4U * sizeof (hbuf[0U]));
          {
            Lib_IntVector_Intrinsics_vec128 v00 = st[0U];
            Lib_IntVector_Intrinsics_vec128 v10 = st[1U];
            Lib_IntVector_Intrinsics_vec128 v20 = st[2U];
            Lib_IntVector_Intrinsics_vec128 v30 = st[3U];
            Lib_IntVector_Intrinsics_vec128
            v0_ = Lib_IntVector_Intrinsics_vec128_interleave_low32(v00, v10);
            Lib_IntVector_Intrinsics_vec128
            v1_ = Lib_IntVector_Intrinsics_vec128_interleave_high32(v00, v10);
            Lib_IntVector_Intrinsics_vec128
            v2_ = Lib_IntVector_Intrinsics_vec128_interleave_low32(v20, v30);
            Lib_IntVector_Intrinsics_vec128
            v3_ = Lib_IntVector_Intrinsics_vec128_interleave_high32(v20, v30);
            Lib_IntVector_Intrinsics_vec128
            v0__ = Lib_IntVector_Intrinsics_vec128_interleave_low64(v0_, v2_);
            Lib_IntVector_Intrinsics_vec128
            v1__ = Lib_IntVector_Intrinsics_vec128_interleave_high64(v0_, v2_);
            Lib_IntVector_Intrinsics_vec128
            v2__ = Lib_IntVector_Intrinsics_vec128_interleave_low64(v1_, v3_);
            Lib_IntVector_Intrinsics_vec128
            v3__ = Lib_IntVector_Intrinsics_vec128_interleave_high64(v1_, v3_);
            Lib_IntVector_Intrinsics_vec128 v0__0 = v0__;
            Lib_IntVector_Intrinsics_vec128 v2__0 = v2__;
            Lib_IntVector_Intrinsics_vec128 v1__0 = v1__;
            Lib_IntVector_Intrinsics_vec128 v3__0 = v3__;
            Lib_IntVector_Intrinsics_vec128 st0_ = v0__0;
            Lib_IntVector_Intrinsics_vec128 st1_ = v1__0;
            Lib_IntVector_Intrinsics_vec128 st2_ = v2__0;
            Lib_IntVector_Intrinsics_vec128 st3_ = v3__0;
            Lib_IntVector_Intrinsics_vec128 v0 = st[4U];
            Lib_IntVector_Intrinsics_vec128 v1 = st[5U];
            Lib_IntVector_Intrinsics_vec128 v2 = st[6U];
            Lib_IntVector_Intrinsics_vec128 v3 = st[7U];
            Lib_IntVector_Intrinsics_vec128
            v0_0 = Lib_IntVector_Intrinsics_vec128_interleave_low32(v0, v1);
            Lib_IntVector_Intrinsics_vec128
            v1_0 = Lib_IntVector_Intrinsics_vec128_interleave_high32(v0, v1);
            Lib_IntVector_Intrinsics_vec128
            v2_0 = Lib_IntVector_Intrinsics_vec128_interleave_low32(v2, v3);
            Lib_IntVector_Intrinsics_vec128
            v3_0 = Lib_IntVector_Intrinsics_vec128_interleave_high32(v2, v3);
            Lib_IntVector_Intrinsics_vec128
            v0__1 = Lib_IntVector_Intrinsics_vec128_interleave_low64(v0_0, v2_0);
            Lib_IntVector_Intrinsics_vec128
            v1__1 = Lib_IntVector_Intrinsics_vec128_interleave_high64(v0_0, v2_0);
            Lib_IntVector_Intrinsics_vec128
            v2__1 = Lib_IntVector_Intrinsics_vec128_interleave_low64(v1_0, v3_0);
            Lib_IntVector_Intrinsics_vec128
            v3__1 = Lib_IntVector_Intrinsics_vec128_interleave_high64(v1_0, v3_0);
            Lib_IntVector_Intrinsics_vec128 v0__2 = v0__1;
            Lib_IntVector_Intrinsics_vec128 v2__2 = v2__1;
            Lib_IntVector_Intrinsics_vec128 v1__2 = v1__1;
            Lib_IntVector_Intrinsics_vec128 v3__2 = v3__1;
            Lib_IntVector_Intrinsics_vec128 st4_ = v0__2;
            Lib_IntVector_Intrinsics_vec128 st5_ = v1__2;
            Lib_IntVector_Intrinsics_vec128 st6_ = v2__2;
            Lib_IntVector_Intrinsics_vec128 st7_ = v3__2;
            u8 *b31;
            u8 *b21;
            u8 *b11;
            u8 *b01;
            st[0U] = st0_;
            st[1U] = st4_;
            st[2U] = st1_;
            st[3U] = st5_;
            st[4U] = st2_;
            st[5U] = st6_;
            st[6U] = st3_;
            st[7U] = st7_;
            {
              u32 i;
              for (i = (u32)0U; i < (u32)8U; i++)
                Lib_IntVector_Intrinsics_vec128_store32_be(hbuf + i * (u32)16U, st[i]);
            }
            b31 = rb.snd.snd.snd;
            b21 = rb.snd.snd.fst;
            b11 = rb.snd.fst;
            b01 = rb.fst;
            memcpy(b01, hbuf, (u32)32U * sizeof (hbuf[0U]));
            memcpy(b11, hbuf + (u32)32U, (u32)32U * sizeof ((hbuf + (u32)32U)[0U]));
            memcpy(b21, hbuf + (u32)64U, (u32)32U * sizeof ((hbuf + (u32)64U)[0U]));
            memcpy(b31, hbuf + (u32)96U, (u32)32U * sizeof ((hbuf + (u32)96U)[0U]));
          }
        }
      }
    }
  }
}
