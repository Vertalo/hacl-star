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


#include "Hacl_Blake2s_32.h"

static inline void blake2s_update_block(uint32_t *hash, bool flag, uint64_t totlen, uint8_t *d)
{
  KRML_CHECK_SIZE(sizeof (uint32_t), (uint32_t)4U * (uint32_t)4U);
  uint32_t b[(uint32_t)4U * (uint32_t)4U];
  memset(b, 0U, (uint32_t)4U * (uint32_t)4U * sizeof (b[0U]));
  uint32_t mask[4U] = { 0U };
  uint32_t wv_14;
  if (flag)
  {
    wv_14 = (uint32_t)0xFFFFFFFFU;
  }
  else
  {
    wv_14 = (uint32_t)0U;
  }
  uint32_t wv_15 = (uint32_t)0U;
  mask[0U] = (uint32_t)totlen;
  mask[1U] = (uint32_t)(totlen >> (uint32_t)32U);
  mask[2U] = wv_14;
  mask[3U] = wv_15;
  memcpy(b, hash, (uint32_t)4U * (uint32_t)4U * sizeof (hash[0U]));
  uint32_t *wv3 = b + (uint32_t)3U * (uint32_t)4U;
  for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
  {
    uint32_t *os = wv3;
    uint32_t x = wv3[i] ^ mask[i];
    os[i] = x;
  }
  for (uint32_t i0 = (uint32_t)0U; i0 < (uint32_t)10U; i0++)
  {
    uint32_t start_idx = i0 % (uint32_t)10U * (uint32_t)16U;
    KRML_CHECK_SIZE(sizeof (uint32_t), (uint32_t)4U * (uint32_t)4U);
    uint32_t m_st[(uint32_t)4U * (uint32_t)4U];
    memset(m_st, 0U, (uint32_t)4U * (uint32_t)4U * sizeof (m_st[0U]));
    uint32_t *r00 = m_st + (uint32_t)0U * (uint32_t)4U;
    uint32_t *r10 = m_st + (uint32_t)1U * (uint32_t)4U;
    uint32_t *r20 = m_st + (uint32_t)2U * (uint32_t)4U;
    uint32_t *r30 = m_st + (uint32_t)3U * (uint32_t)4U;
    uint32_t s0 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx];
    uint32_t s1 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)1U];
    uint32_t s2 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)2U];
    uint32_t s3 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)3U];
    uint32_t s4 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)4U];
    uint32_t s5 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)5U];
    uint32_t s6 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)6U];
    uint32_t s7 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)7U];
    uint32_t s8 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)8U];
    uint32_t s9 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)9U];
    uint32_t s10 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)10U];
    uint32_t s11 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)11U];
    uint32_t s12 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)12U];
    uint32_t s13 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)13U];
    uint32_t s14 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)14U];
    uint32_t s15 = Hacl_Impl_Blake2_Constants_sigmaTable[start_idx + (uint32_t)15U];
    uint32_t nb = (uint32_t)4U;
    uint8_t *b00 = d + s0 * nb;
    uint8_t *b10 = d + s2 * nb;
    uint8_t *b20 = d + s4 * nb;
    uint8_t *b30 = d + s6 * nb;
    uint32_t u0 = load32_le(b00);
    uint32_t u00 = u0;
    uint32_t u1 = load32_le(b10);
    uint32_t u11 = u1;
    uint32_t u2 = load32_le(b20);
    uint32_t u20 = u2;
    uint32_t u3 = load32_le(b30);
    uint32_t u30 = u3;
    r00[0U] = u00;
    r00[1U] = u11;
    r00[2U] = u20;
    r00[3U] = u30;
    uint32_t nb0 = (uint32_t)4U;
    uint8_t *b01 = d + s1 * nb0;
    uint8_t *b11 = d + s3 * nb0;
    uint8_t *b21 = d + s5 * nb0;
    uint8_t *b31 = d + s7 * nb0;
    uint32_t u4 = load32_le(b01);
    uint32_t u01 = u4;
    uint32_t u5 = load32_le(b11);
    uint32_t u110 = u5;
    uint32_t u6 = load32_le(b21);
    uint32_t u21 = u6;
    uint32_t u7 = load32_le(b31);
    uint32_t u31 = u7;
    r10[0U] = u01;
    r10[1U] = u110;
    r10[2U] = u21;
    r10[3U] = u31;
    uint32_t nb1 = (uint32_t)4U;
    uint8_t *b02 = d + s8 * nb1;
    uint8_t *b12 = d + s10 * nb1;
    uint8_t *b22 = d + s12 * nb1;
    uint8_t *b32 = d + s14 * nb1;
    uint32_t u8 = load32_le(b02);
    uint32_t u02 = u8;
    uint32_t u9 = load32_le(b12);
    uint32_t u111 = u9;
    uint32_t u10 = load32_le(b22);
    uint32_t u22 = u10;
    uint32_t u12 = load32_le(b32);
    uint32_t u32 = u12;
    r20[0U] = u02;
    r20[1U] = u111;
    r20[2U] = u22;
    r20[3U] = u32;
    uint32_t nb2 = (uint32_t)4U;
    uint8_t *b0 = d + s9 * nb2;
    uint8_t *b13 = d + s11 * nb2;
    uint8_t *b2 = d + s13 * nb2;
    uint8_t *b3 = d + s15 * nb2;
    uint32_t u13 = load32_le(b0);
    uint32_t u03 = u13;
    uint32_t u14 = load32_le(b13);
    uint32_t u112 = u14;
    uint32_t u15 = load32_le(b2);
    uint32_t u23 = u15;
    uint32_t u = load32_le(b3);
    uint32_t u33 = u;
    r30[0U] = u03;
    r30[1U] = u112;
    r30[2U] = u23;
    r30[3U] = u33;
    uint32_t *x = m_st + (uint32_t)0U * (uint32_t)4U;
    uint32_t *y = m_st + (uint32_t)1U * (uint32_t)4U;
    uint32_t *z = m_st + (uint32_t)2U * (uint32_t)4U;
    uint32_t *w = m_st + (uint32_t)3U * (uint32_t)4U;
    uint32_t a = (uint32_t)0U;
    uint32_t b14 = (uint32_t)1U;
    uint32_t c0 = (uint32_t)2U;
    uint32_t d10 = (uint32_t)3U;
    uint32_t r01 = Hacl_Impl_Blake2_Constants_rTable_S[0U];
    uint32_t r12 = Hacl_Impl_Blake2_Constants_rTable_S[1U];
    uint32_t r21 = Hacl_Impl_Blake2_Constants_rTable_S[2U];
    uint32_t r31 = Hacl_Impl_Blake2_Constants_rTable_S[3U];
    uint32_t zz0[4U] = { 0U };
    uint32_t *wv_a0 = b + a * (uint32_t)4U;
    uint32_t *wv_b0 = b + b14 * (uint32_t)4U;
    for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
    {
      uint32_t *os = wv_a0;
      uint32_t x1 = wv_a0[i] + wv_b0[i];
      os[i] = x1;
    }
    for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
    {
      uint32_t *os = wv_a0;
      uint32_t x1 = wv_a0[i] + x[i];
      os[i] = x1;
    }
    uint32_t *wv_a1 = b + d10 * (uint32_t)4U;
    uint32_t *wv_b1 = b + a * (uint32_t)4U;
    for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
    {
      uint32_t *os = wv_a1;
      uint32_t x1 = wv_a1[i] ^ wv_b1[i];
      os[i] = x1;
    }
    uint32_t *r110 = wv_a1;
    for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
    {
      uint32_t *os = r110;
      uint32_t x1 = r110[i];
      uint32_t x10 = x1 >> r01 | x1 << ((uint32_t)32U - r01);
      os[i] = x10;
    }
    uint32_t *wv_a2 = b + c0 * (uint32_t)4U;
    uint32_t *wv_b2 = b + d10 * (uint32_t)4U;
    for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
    {
      uint32_t *os = wv_a2;
      uint32_t x1 = wv_a2[i] + wv_b2[i];
      os[i] = x1;
    }
    for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
    {
      uint32_t *os = wv_a2;
      uint32_t x1 = wv_a2[i] + zz0[i];
      os[i] = x1;
    }
    uint32_t *wv_a3 = b + b14 * (uint32_t)4U;
    uint32_t *wv_b3 = b + c0 * (uint32_t)4U;
    for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
    {
      uint32_t *os = wv_a3;
      uint32_t x1 = wv_a3[i] ^ wv_b3[i];
      os[i] = x1;
    }
    uint32_t *r111 = wv_a3;
    for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
    {
      uint32_t *os = r111;
      uint32_t x1 = r111[i];
      uint32_t x10 = x1 >> r12 | x1 << ((uint32_t)32U - r12);
      os[i] = x10;
    }
    uint32_t *wv_a4 = b + a * (uint32_t)4U;
    uint32_t *wv_b4 = b + b14 * (uint32_t)4U;
    for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
    {
      uint32_t *os = wv_a4;
      uint32_t x1 = wv_a4[i] + wv_b4[i];
      os[i] = x1;
    }
    for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
    {
      uint32_t *os = wv_a4;
      uint32_t x1 = wv_a4[i] + y[i];
      os[i] = x1;
    }
    uint32_t *wv_a5 = b + d10 * (uint32_t)4U;
    uint32_t *wv_b5 = b + a * (uint32_t)4U;
    for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
    {
      uint32_t *os = wv_a5;
      uint32_t x1 = wv_a5[i] ^ wv_b5[i];
      os[i] = x1;
    }
    uint32_t *r112 = wv_a5;
    for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
    {
      uint32_t *os = r112;
      uint32_t x1 = r112[i];
      uint32_t x10 = x1 >> r21 | x1 << ((uint32_t)32U - r21);
      os[i] = x10;
    }
    uint32_t *wv_a6 = b + c0 * (uint32_t)4U;
    uint32_t *wv_b6 = b + d10 * (uint32_t)4U;
    for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
    {
      uint32_t *os = wv_a6;
      uint32_t x1 = wv_a6[i] + wv_b6[i];
      os[i] = x1;
    }
    for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
    {
      uint32_t *os = wv_a6;
      uint32_t x1 = wv_a6[i] + zz0[i];
      os[i] = x1;
    }
    uint32_t *wv_a7 = b + b14 * (uint32_t)4U;
    uint32_t *wv_b7 = b + c0 * (uint32_t)4U;
    for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
    {
      uint32_t *os = wv_a7;
      uint32_t x1 = wv_a7[i] ^ wv_b7[i];
      os[i] = x1;
    }
    uint32_t *r113 = wv_a7;
    for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
    {
      uint32_t *os = r113;
      uint32_t x1 = r113[i];
      uint32_t x10 = x1 >> r31 | x1 << ((uint32_t)32U - r31);
      os[i] = x10;
    }
    uint32_t *r13 = b + (uint32_t)1U * (uint32_t)4U;
    uint32_t *r22 = b + (uint32_t)2U * (uint32_t)4U;
    uint32_t *r32 = b + (uint32_t)3U * (uint32_t)4U;
    uint32_t n00 = (uint32_t)1U;
    uint32_t n10 = ((uint32_t)1U + (uint32_t)1U) % (uint32_t)4U;
    uint32_t n20 = ((uint32_t)1U + (uint32_t)2U) % (uint32_t)4U;
    uint32_t n30 = ((uint32_t)1U + (uint32_t)3U) % (uint32_t)4U;
    uint32_t *r114 = r13;
    uint32_t x00 = r114[n00];
    uint32_t x10 = r114[n10];
    uint32_t x20 = r114[n20];
    uint32_t x30 = r114[n30];
    r114[0U] = x00;
    r114[1U] = x10;
    r114[2U] = x20;
    r114[3U] = x30;
    uint32_t n01 = (uint32_t)2U;
    uint32_t n11 = ((uint32_t)2U + (uint32_t)1U) % (uint32_t)4U;
    uint32_t n21 = ((uint32_t)2U + (uint32_t)2U) % (uint32_t)4U;
    uint32_t n31 = ((uint32_t)2U + (uint32_t)3U) % (uint32_t)4U;
    uint32_t *r115 = r22;
    uint32_t x01 = r115[n01];
    uint32_t x11 = r115[n11];
    uint32_t x21 = r115[n21];
    uint32_t x31 = r115[n31];
    r115[0U] = x01;
    r115[1U] = x11;
    r115[2U] = x21;
    r115[3U] = x31;
    uint32_t n02 = (uint32_t)3U;
    uint32_t n12 = ((uint32_t)3U + (uint32_t)1U) % (uint32_t)4U;
    uint32_t n22 = ((uint32_t)3U + (uint32_t)2U) % (uint32_t)4U;
    uint32_t n32 = ((uint32_t)3U + (uint32_t)3U) % (uint32_t)4U;
    uint32_t *r116 = r32;
    uint32_t x02 = r116[n02];
    uint32_t x12 = r116[n12];
    uint32_t x22 = r116[n22];
    uint32_t x32 = r116[n32];
    r116[0U] = x02;
    r116[1U] = x12;
    r116[2U] = x22;
    r116[3U] = x32;
    uint32_t a0 = (uint32_t)0U;
    uint32_t b1 = (uint32_t)1U;
    uint32_t c = (uint32_t)2U;
    uint32_t d1 = (uint32_t)3U;
    uint32_t r0 = Hacl_Impl_Blake2_Constants_rTable_S[0U];
    uint32_t r1 = Hacl_Impl_Blake2_Constants_rTable_S[1U];
    uint32_t r23 = Hacl_Impl_Blake2_Constants_rTable_S[2U];
    uint32_t r33 = Hacl_Impl_Blake2_Constants_rTable_S[3U];
    uint32_t zz[4U] = { 0U };
    uint32_t *wv_a = b + a0 * (uint32_t)4U;
    uint32_t *wv_b8 = b + b1 * (uint32_t)4U;
    for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
    {
      uint32_t *os = wv_a;
      uint32_t x1 = wv_a[i] + wv_b8[i];
      os[i] = x1;
    }
    for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
    {
      uint32_t *os = wv_a;
      uint32_t x1 = wv_a[i] + z[i];
      os[i] = x1;
    }
    uint32_t *wv_a8 = b + d1 * (uint32_t)4U;
    uint32_t *wv_b9 = b + a0 * (uint32_t)4U;
    for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
    {
      uint32_t *os = wv_a8;
      uint32_t x1 = wv_a8[i] ^ wv_b9[i];
      os[i] = x1;
    }
    uint32_t *r117 = wv_a8;
    for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
    {
      uint32_t *os = r117;
      uint32_t x1 = r117[i];
      uint32_t x13 = x1 >> r0 | x1 << ((uint32_t)32U - r0);
      os[i] = x13;
    }
    uint32_t *wv_a9 = b + c * (uint32_t)4U;
    uint32_t *wv_b10 = b + d1 * (uint32_t)4U;
    for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
    {
      uint32_t *os = wv_a9;
      uint32_t x1 = wv_a9[i] + wv_b10[i];
      os[i] = x1;
    }
    for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
    {
      uint32_t *os = wv_a9;
      uint32_t x1 = wv_a9[i] + zz[i];
      os[i] = x1;
    }
    uint32_t *wv_a10 = b + b1 * (uint32_t)4U;
    uint32_t *wv_b11 = b + c * (uint32_t)4U;
    for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
    {
      uint32_t *os = wv_a10;
      uint32_t x1 = wv_a10[i] ^ wv_b11[i];
      os[i] = x1;
    }
    uint32_t *r118 = wv_a10;
    for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
    {
      uint32_t *os = r118;
      uint32_t x1 = r118[i];
      uint32_t x13 = x1 >> r1 | x1 << ((uint32_t)32U - r1);
      os[i] = x13;
    }
    uint32_t *wv_a11 = b + a0 * (uint32_t)4U;
    uint32_t *wv_b12 = b + b1 * (uint32_t)4U;
    for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
    {
      uint32_t *os = wv_a11;
      uint32_t x1 = wv_a11[i] + wv_b12[i];
      os[i] = x1;
    }
    for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
    {
      uint32_t *os = wv_a11;
      uint32_t x1 = wv_a11[i] + w[i];
      os[i] = x1;
    }
    uint32_t *wv_a12 = b + d1 * (uint32_t)4U;
    uint32_t *wv_b13 = b + a0 * (uint32_t)4U;
    for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
    {
      uint32_t *os = wv_a12;
      uint32_t x1 = wv_a12[i] ^ wv_b13[i];
      os[i] = x1;
    }
    uint32_t *r119 = wv_a12;
    for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
    {
      uint32_t *os = r119;
      uint32_t x1 = r119[i];
      uint32_t x13 = x1 >> r23 | x1 << ((uint32_t)32U - r23);
      os[i] = x13;
    }
    uint32_t *wv_a13 = b + c * (uint32_t)4U;
    uint32_t *wv_b14 = b + d1 * (uint32_t)4U;
    for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
    {
      uint32_t *os = wv_a13;
      uint32_t x1 = wv_a13[i] + wv_b14[i];
      os[i] = x1;
    }
    for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
    {
      uint32_t *os = wv_a13;
      uint32_t x1 = wv_a13[i] + zz[i];
      os[i] = x1;
    }
    uint32_t *wv_a14 = b + b1 * (uint32_t)4U;
    uint32_t *wv_b = b + c * (uint32_t)4U;
    for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
    {
      uint32_t *os = wv_a14;
      uint32_t x1 = wv_a14[i] ^ wv_b[i];
      os[i] = x1;
    }
    uint32_t *r1110 = wv_a14;
    for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
    {
      uint32_t *os = r1110;
      uint32_t x1 = r1110[i];
      uint32_t x13 = x1 >> r33 | x1 << ((uint32_t)32U - r33);
      os[i] = x13;
    }
    uint32_t *r14 = b + (uint32_t)1U * (uint32_t)4U;
    uint32_t *r2 = b + (uint32_t)2U * (uint32_t)4U;
    uint32_t *r3 = b + (uint32_t)3U * (uint32_t)4U;
    uint32_t n0 = (uint32_t)3U;
    uint32_t n13 = ((uint32_t)3U + (uint32_t)1U) % (uint32_t)4U;
    uint32_t n23 = ((uint32_t)3U + (uint32_t)2U) % (uint32_t)4U;
    uint32_t n33 = ((uint32_t)3U + (uint32_t)3U) % (uint32_t)4U;
    uint32_t *r1111 = r14;
    uint32_t x03 = r1111[n0];
    uint32_t x13 = r1111[n13];
    uint32_t x23 = r1111[n23];
    uint32_t x33 = r1111[n33];
    r1111[0U] = x03;
    r1111[1U] = x13;
    r1111[2U] = x23;
    r1111[3U] = x33;
    uint32_t n03 = (uint32_t)2U;
    uint32_t n14 = ((uint32_t)2U + (uint32_t)1U) % (uint32_t)4U;
    uint32_t n24 = ((uint32_t)2U + (uint32_t)2U) % (uint32_t)4U;
    uint32_t n34 = ((uint32_t)2U + (uint32_t)3U) % (uint32_t)4U;
    uint32_t *r1112 = r2;
    uint32_t x04 = r1112[n03];
    uint32_t x14 = r1112[n14];
    uint32_t x24 = r1112[n24];
    uint32_t x34 = r1112[n34];
    r1112[0U] = x04;
    r1112[1U] = x14;
    r1112[2U] = x24;
    r1112[3U] = x34;
    uint32_t n04 = (uint32_t)1U;
    uint32_t n1 = ((uint32_t)1U + (uint32_t)1U) % (uint32_t)4U;
    uint32_t n2 = ((uint32_t)1U + (uint32_t)2U) % (uint32_t)4U;
    uint32_t n3 = ((uint32_t)1U + (uint32_t)3U) % (uint32_t)4U;
    uint32_t *r11 = r3;
    uint32_t x0 = r11[n04];
    uint32_t x1 = r11[n1];
    uint32_t x2 = r11[n2];
    uint32_t x3 = r11[n3];
    r11[0U] = x0;
    r11[1U] = x1;
    r11[2U] = x2;
    r11[3U] = x3;
  }
  uint32_t *s0 = hash + (uint32_t)0U * (uint32_t)4U;
  uint32_t *s1 = hash + (uint32_t)1U * (uint32_t)4U;
  uint32_t *r0 = b + (uint32_t)0U * (uint32_t)4U;
  uint32_t *r1 = b + (uint32_t)1U * (uint32_t)4U;
  uint32_t *r2 = b + (uint32_t)2U * (uint32_t)4U;
  uint32_t *r3 = b + (uint32_t)3U * (uint32_t)4U;
  for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
  {
    uint32_t *os = s0;
    uint32_t x = s0[i] ^ r0[i];
    os[i] = x;
  }
  for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
  {
    uint32_t *os = s0;
    uint32_t x = s0[i] ^ r2[i];
    os[i] = x;
  }
  for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
  {
    uint32_t *os = s1;
    uint32_t x = s1[i] ^ r1[i];
    os[i] = x;
  }
  for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
  {
    uint32_t *os = s1;
    uint32_t x = s1[i] ^ r3[i];
    os[i] = x;
  }
  memset(b, 0U, (uint32_t)4U * (uint32_t)4U * sizeof (b[0U]));
}

typedef struct __uint32_t_uint32_t_s
{
  uint32_t fst;
  uint32_t snd;
}
__uint32_t_uint32_t;

void
Hacl_Blake2s_32_blake2s(
  uint32_t nn,
  uint8_t *output,
  uint32_t ll,
  uint8_t *d,
  uint32_t kk,
  uint8_t *k
)
{
  KRML_CHECK_SIZE(sizeof (uint32_t), (uint32_t)4U * (uint32_t)4U);
  uint32_t h[(uint32_t)4U * (uint32_t)4U];
  memset(h, 0U, (uint32_t)4U * (uint32_t)4U * sizeof (h[0U]));
  uint64_t prev0;
  if (kk == (uint32_t)0U)
  {
    prev0 = (uint64_t)(uint32_t)0U;
  }
  else
  {
    prev0 = (uint64_t)(uint32_t)64U;
  }
  uint8_t b0[64U] = { 0U };
  uint32_t *r0 = h + (uint32_t)0U * (uint32_t)4U;
  uint32_t *r1 = h + (uint32_t)1U * (uint32_t)4U;
  uint32_t *r2 = h + (uint32_t)2U * (uint32_t)4U;
  uint32_t *r3 = h + (uint32_t)3U * (uint32_t)4U;
  uint32_t iv0 = Hacl_Impl_Blake2_Constants_ivTable_S[0U];
  uint32_t iv1 = Hacl_Impl_Blake2_Constants_ivTable_S[1U];
  uint32_t iv2 = Hacl_Impl_Blake2_Constants_ivTable_S[2U];
  uint32_t iv3 = Hacl_Impl_Blake2_Constants_ivTable_S[3U];
  uint32_t iv4 = Hacl_Impl_Blake2_Constants_ivTable_S[4U];
  uint32_t iv5 = Hacl_Impl_Blake2_Constants_ivTable_S[5U];
  uint32_t iv6 = Hacl_Impl_Blake2_Constants_ivTable_S[6U];
  uint32_t iv7 = Hacl_Impl_Blake2_Constants_ivTable_S[7U];
  r2[0U] = iv0;
  r2[1U] = iv1;
  r2[2U] = iv2;
  r2[3U] = iv3;
  r3[0U] = iv4;
  r3[1U] = iv5;
  r3[2U] = iv6;
  r3[3U] = iv7;
  uint32_t kk_shift_8 = kk << (uint32_t)8U;
  uint32_t iv0_ = iv0 ^ ((uint32_t)0x01010000U ^ (kk_shift_8 ^ nn));
  r0[0U] = iv0_;
  r0[1U] = iv1;
  r0[2U] = iv2;
  r0[3U] = iv3;
  r1[0U] = iv4;
  r1[1U] = iv5;
  r1[2U] = iv6;
  r1[3U] = iv7;
  if (!(kk == (uint32_t)0U))
  {
    memcpy(b0, k, kk * sizeof (k[0U]));
    uint64_t totlen = (uint64_t)(uint32_t)0U + (uint64_t)(uint32_t)64U;
    uint8_t *b1 = b0 + (uint32_t)0U * (uint32_t)64U;
    blake2s_update_block(h, false, totlen, b1);
  }
  memset(b0, 0U, (uint32_t)64U * sizeof (b0[0U]));
  uint32_t nb = ll / (uint32_t)64U;
  uint32_t rem1 = ll % (uint32_t)64U;
  __uint32_t_uint32_t scrut;
  if (rem1 == (uint32_t)0U && nb > (uint32_t)0U)
  {
    uint32_t nb_ = nb - (uint32_t)1U;
    uint32_t rem_ = (uint32_t)64U;
    scrut = ((__uint32_t_uint32_t){ .fst = nb_, .snd = rem_ });
  }
  else
  {
    scrut = ((__uint32_t_uint32_t){ .fst = nb, .snd = rem1 });
  }
  uint32_t nb0 = scrut.fst;
  for (uint32_t i = (uint32_t)0U; i < nb0; i++)
  {
    uint64_t totlen = prev0 + (uint64_t)((i + (uint32_t)1U) * (uint32_t)64U);
    uint8_t *b = d + i * (uint32_t)64U;
    blake2s_update_block(h, false, totlen, b);
  }
  uint32_t rem2 = ll % (uint32_t)64U;
  uint8_t *last1 = d + ll - rem2;
  uint8_t last_block[64U] = { 0U };
  memcpy(last_block, last1, rem2 * sizeof (last1[0U]));
  uint64_t totlen = prev0 + (uint64_t)ll;
  blake2s_update_block(h, true, totlen, last_block);
  KRML_CHECK_SIZE(sizeof (uint8_t), (uint32_t)2U * (uint32_t)4U * (uint32_t)4U);
  uint8_t b[(uint32_t)2U * (uint32_t)4U * (uint32_t)4U];
  memset(b, 0U, (uint32_t)2U * (uint32_t)4U * (uint32_t)4U * sizeof (b[0U]));
  uint8_t *uu____0 = b;
  uint32_t *uu____1 = h + (uint32_t)0U * (uint32_t)4U;
  for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
  {
    store32_le(uu____0 + i * (uint32_t)4U, uu____1[i]);
  }
  uint8_t *uu____2 = b + (uint32_t)4U * (uint32_t)4U;
  uint32_t *uu____3 = h + (uint32_t)1U * (uint32_t)4U;
  for (uint32_t i = (uint32_t)0U; i < (uint32_t)4U; i++)
  {
    store32_le(uu____2 + i * (uint32_t)4U, uu____3[i]);
  }
  uint8_t *final = b;
  memcpy(output, final, nn * sizeof (final[0U]));
  memset(b, 0U, (uint32_t)2U * (uint32_t)4U * (uint32_t)4U * sizeof (b[0U]));
}
