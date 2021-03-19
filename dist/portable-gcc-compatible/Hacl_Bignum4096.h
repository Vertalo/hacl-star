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


#ifndef __Hacl_Bignum4096_H
#define __Hacl_Bignum4096_H

#if defined(__cplusplus)
extern "C" {
#endif

#include "evercrypt_targetconfig.h"
#include "libintvector.h"
#include "kremlin/internal/types.h"
#include "kremlin/lowstar_endianness.h"
#include <string.h>
#include "kremlin/internal/target.h"


#include "Hacl_Kremlib.h"
#include "Hacl_Bignum.h"

/* SNIPPET_START: Hacl_Bignum4096_add */

/*******************************************************************************

A verified 4096-bit bignum library.

This is a 64-bit optimized version, where bignums are represented as an array
of sixty four unsigned 64-bit integers, i.e. uint64_t[64]. Furthermore, the
limbs are stored in little-endian format, i.e. the least significant limb is at
index 0. Each limb is stored in native format in memory. Example:

  uint64_t sixteen[64] = { 0x10 }

  (relying on the fact that when an initializer-list is provided, the remainder
  of the object gets initialized as if it had static storage duration, i.e. with
  zeroes)

We strongly encourage users to go through the conversion functions, e.g.
bn_from_bytes_be, to i) not depend on internal representation choices and ii)
have the ability to switch easily to a 32-bit optimized version in the future.

*******************************************************************************/

/************************/
/* Arithmetic functions */
/************************/


/*
Write `a + b mod 2^4096` in `res`.

  This functions returns the carry.

  The arguments a, b and res are meant to be 4096-bit bignums, i.e. uint64_t[64]
*/
uint64_t Hacl_Bignum4096_add(uint64_t *a, uint64_t *b, uint64_t *res);

/* SNIPPET_END: Hacl_Bignum4096_add */

/* SNIPPET_START: Hacl_Bignum4096_sub */

/*
Write `a - b mod 2^4096` in `res`.

  This functions returns the carry.

  The arguments a, b and res are meant to be 4096-bit bignums, i.e. uint64_t[64]
*/
uint64_t Hacl_Bignum4096_sub(uint64_t *a, uint64_t *b, uint64_t *res);

/* SNIPPET_END: Hacl_Bignum4096_sub */

/* SNIPPET_START: Hacl_Bignum4096_mul */

/*
Write `a * b` in `res`.

  The arguments a and b are meant to be 4096-bit bignums, i.e. uint64_t[64].
  The outparam res is meant to be a 8192-bit bignum, i.e. uint64_t[128].
*/
void Hacl_Bignum4096_mul(uint64_t *a, uint64_t *b, uint64_t *res);

/* SNIPPET_END: Hacl_Bignum4096_mul */

/* SNIPPET_START: Hacl_Bignum4096_sqr */

/*
Write `a * a` in `res`.

  The argument a is meant to be a 4096-bit bignum, i.e. uint64_t[64].
  The outparam res is meant to be a 8192-bit bignum, i.e. uint64_t[128].
*/
void Hacl_Bignum4096_sqr(uint64_t *a, uint64_t *res);

/* SNIPPET_END: Hacl_Bignum4096_sqr */

/* SNIPPET_START: Hacl_Bignum4096_mod_precompr2 */

/*
Write `a mod n` in `res` if a < n * n.

  The argument a is meant to be a 8192-bit bignum, i.e. uint64_t[128].
  The argument n, r2 and the outparam res are meant to be 4096-bit bignums, i.e. uint64_t[64].
  The argument r2 is a precomputed constant 2 ^ 8192 mod n obtained through Hacl_Bignum4096_new_precompr2.

  This function is *UNSAFE* and requires C clients to observe the precondition
  of bn_mod_slow_precompr2_lemma in Hacl.Spec.Bignum.ModReduction.fst, which
  amounts to:
  • 1 < n
  • n % 2 = 1
  • a < n * n

  Owing to the absence of run-time checks, and factoring out the precomputation
  r2, this function is notably faster than mod below.
*/
void Hacl_Bignum4096_mod_precompr2(uint64_t *n, uint64_t *a, uint64_t *r2, uint64_t *res);

/* SNIPPET_END: Hacl_Bignum4096_mod_precompr2 */

/* SNIPPET_START: Hacl_Bignum4096_mod */

/*
Write `a mod n` in `res` if a < n * n.

  The argument a is meant to be a 8192-bit bignum, i.e. uint64_t[128].
  The argument n and the outparam res are meant to be 4096-bit bignums, i.e. uint64_t[64].

  The function returns false if any of the preconditions of mod_precompr2 above
  are violated, true otherwise.
*/
bool Hacl_Bignum4096_mod(uint64_t *n, uint64_t *a, uint64_t *res);

/* SNIPPET_END: Hacl_Bignum4096_mod */

/* SNIPPET_START: Hacl_Bignum4096_mod_exp_vartime_precompr2 */

/*
Write `a ^ b mod n` in `res`.

  The arguments a, n, r2 and the outparam res are meant to be 4096-bit bignums, i.e. uint64_t[64].
  The argument r2 is a precomputed constant 2 ^ 8192 mod n obtained through Hacl_Bignum4096_new_precompr2.
  The argument b is a bignum of any size, and bBits is an upper bound on the
  number of significant bits of b. A tighter bound results in faster execution
  time. When in doubt, the number of bits for the bignum size is always a safe
  default, e.g. if b is a 4096-bit bignum, bBits should be 4096.

  The function is *NOT* constant-time on the argument b. See the
  mod_exp_consttime_* functions for constant-time variants.

  This function is *UNSAFE* and requires C clients to observe bn_mod_exp_pre
  from Hacl.Spec.Bignum.Exponentiation.fsti, which amounts to:
  • n % 2 = 1
  • 1 < n
  • 0 < b
  • b < pow2 bBits
  • a < n

  Owing to the absence of run-time checks, and factoring out the precomputation
  r2, this function is notably faster than mod_exp_vartime below.
*/
void
Hacl_Bignum4096_mod_exp_vartime_precompr2(
  uint64_t *n,
  uint64_t *a,
  uint32_t bBits,
  uint64_t *b,
  uint64_t *r2,
  uint64_t *res
);

/* SNIPPET_END: Hacl_Bignum4096_mod_exp_vartime_precompr2 */

/* SNIPPET_START: Hacl_Bignum4096_mod_exp_consttime_precompr2 */

/*
Write `a ^ b mod n` in `res`.

  The arguments a, n, r2 and the outparam res are meant to be 4096-bit bignums, i.e. uint64_t[64].
  The argument r2 is a precomputed constant 2 ^ 8192 mod n obtained through Hacl_Bignum4096_new_precompr2.
  The argument b is a bignum of any size, and bBits is an upper bound on the
  number of significant bits of b. A tighter bound results in faster execution
  time. When in doubt, the number of bits for the bignum size is always a safe
  default, e.g. if b is a 4096-bit bignum, bBits should be 4096.

  This function is constant-time over its argument b, at the cost of a slower
  execution time than mod_exp_vartime_precompr2.

  This function is *UNSAFE* and requires C clients to observe bn_mod_exp_pre
  from Hacl.Spec.Bignum.Exponentiation.fsti, which amounts to:
  • n % 2 = 1
  • 1 < n
  • 0 < b
  • b < pow2 bBits
  • a < n

  Owing to the absence of run-time checks, and factoring out the precomputation
  r2, this function is notably faster than mod_exp_consttime below.
*/
void
Hacl_Bignum4096_mod_exp_consttime_precompr2(
  uint64_t *n,
  uint64_t *a,
  uint32_t bBits,
  uint64_t *b,
  uint64_t *r2,
  uint64_t *res
);

/* SNIPPET_END: Hacl_Bignum4096_mod_exp_consttime_precompr2 */

/* SNIPPET_START: Hacl_Bignum4096_mod_exp_vartime */

/*
Write `a ^ b mod n` in `res`.

  The arguments a, n and the outparam res are meant to be 4096-bit bignums, i.e. uint64_t[64].
  The argument b is a bignum of any size, and bBits is an upper bound on the
  number of significant bits of b. A tighter bound results in faster execution
  time. When in doubt, the number of bits for the bignum size is always a safe
  default, e.g. if b is a 4096-bit bignum, bBits should be 4096.

  The function is *NOT* constant-time on the argument b. See the
  mod_exp_consttime_* functions for constant-time variants.

  The function returns false if any of the preconditions of mod_exp_precompr2 are
  violated, true otherwise.
*/
bool
Hacl_Bignum4096_mod_exp_vartime(
  uint64_t *n,
  uint64_t *a,
  uint32_t bBits,
  uint64_t *b,
  uint64_t *res
);

/* SNIPPET_END: Hacl_Bignum4096_mod_exp_vartime */

/* SNIPPET_START: Hacl_Bignum4096_mod_exp_consttime */

/*
Write `a ^ b mod n` in `res`.

  The arguments a, n and the outparam res are meant to be 4096-bit bignums, i.e. uint64_t[64].
  The argument b is a bignum of any size, and bBits is an upper bound on the
  number of significant bits of b. A tighter bound results in faster execution
  time. When in doubt, the number of bits for the bignum size is always a safe
  default, e.g. if b is a 4096-bit bignum, bBits should be 4096.

  This function is constant-time over its argument b, at the cost of a slower
  execution time than mod_exp_vartime.

  The function returns false if any of the preconditions of
  mod_exp_consttime_precompr2 are violated, true otherwise.
*/
bool
Hacl_Bignum4096_mod_exp_consttime(
  uint64_t *n,
  uint64_t *a,
  uint32_t bBits,
  uint64_t *b,
  uint64_t *res
);

/* SNIPPET_END: Hacl_Bignum4096_mod_exp_consttime */

/* SNIPPET_START: Hacl_Bignum4096_new_precompr2 */

/*
Compute `2 ^ 8192 mod n`.

  The argument n points to a 4096-bit bignum of valid memory.
  The function returns a heap-allocated 4096-bit bignum, or NULL if:
  • the allocation failed, or
  • n % 2 = 1 && 1 < n does not hold

  If the return value is non-null, clients must eventually call free(3) on it to
  avoid memory leaks.
*/
uint64_t *Hacl_Bignum4096_new_precompr2(uint64_t *n);

/* SNIPPET_END: Hacl_Bignum4096_new_precompr2 */

/* SNIPPET_START: Hacl_Bignum4096_mod_inv_prime_vartime */

/*
Write `a ^ (-1) mod n` in `res`.

  The arguments a, n and the outparam res are meant to be 4096-bit bignums, i.e. uint64_t[64].

  This function is *UNSAFE* and requires C clients to observe bn_mod_inv_prime_pre
  from Hacl.Spec.Bignum.ModInv.fst, which amounts to:
  • n is a prime

  The function returns false if any of the following preconditions are violated, true otherwise.
  • n % 2 = 1
  • 1 < n
  • 0 < a
  • a < n 
*/
bool Hacl_Bignum4096_mod_inv_prime_vartime(uint64_t *n, uint64_t *a, uint64_t *res);

/* SNIPPET_END: Hacl_Bignum4096_mod_inv_prime_vartime */

/* SNIPPET_START: Hacl_Bignum4096_new_bn_from_bytes_be */


/********************/
/* Loads and stores */
/********************/


/*
Load a bid-endian bignum from memory.

  The argument b points to len bytes of valid memory.
  The function returns a heap-allocated bignum of size sufficient to hold the
   result of loading b, or NULL if either the allocation failed, or the amount of
    required memory would exceed 4GB.

  If the return value is non-null, clients must eventually call free(3) on it to
  avoid memory leaks.
*/
uint64_t *Hacl_Bignum4096_new_bn_from_bytes_be(uint32_t len, uint8_t *b);

/* SNIPPET_END: Hacl_Bignum4096_new_bn_from_bytes_be */

/* SNIPPET_START: Hacl_Bignum4096_new_bn_from_bytes_le */

/*
Load a little-endian bignum from memory.

  The argument b points to len bytes of valid memory.
  The function returns a heap-allocated bignum of size sufficient to hold the
   result of loading b, or NULL if either the allocation failed, or the amount of
    required memory would exceed 4GB.

  If the return value is non-null, clients must eventually call free(3) on it to
  avoid memory leaks.
*/
uint64_t *Hacl_Bignum4096_new_bn_from_bytes_le(uint32_t len, uint8_t *b);

/* SNIPPET_END: Hacl_Bignum4096_new_bn_from_bytes_le */

/* SNIPPET_START: Hacl_Bignum4096_bn_to_bytes_be */

/*
Serialize a bignum into big-endian memory.

  The argument b points to a 4096-bit bignum.
  The outparam res points to 512 bytes of valid memory.
*/
void Hacl_Bignum4096_bn_to_bytes_be(uint64_t *b, uint8_t *res);

/* SNIPPET_END: Hacl_Bignum4096_bn_to_bytes_be */

/* SNIPPET_START: Hacl_Bignum4096_bn_to_bytes_le */

/*
Serialize a bignum into little-endian memory.

  The argument b points to a 4096-bit bignum.
  The outparam res points to 512 bytes of valid memory.
*/
void Hacl_Bignum4096_bn_to_bytes_le(uint64_t *b, uint8_t *res);

/* SNIPPET_END: Hacl_Bignum4096_bn_to_bytes_le */

/* SNIPPET_START: Hacl_Bignum4096_lt_mask */


/***************/
/* Comparisons */
/***************/


/*
Returns 2 ^ 64 - 1 if and only if argument a is strictly less than the argument b, otherwise returns 0.
*/
uint64_t Hacl_Bignum4096_lt_mask(uint64_t *a, uint64_t *b);

/* SNIPPET_END: Hacl_Bignum4096_lt_mask */

#if defined(__cplusplus)
}
#endif

#define __Hacl_Bignum4096_H_DEFINED
#endif
