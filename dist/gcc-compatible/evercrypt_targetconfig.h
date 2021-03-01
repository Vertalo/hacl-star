#ifndef __EVERCRYPT_TARGETCONFIG_H
#define __EVERCRYPT_TARGETCONFIG_H

enum {
  TARGET_ARCHI_NAME_X86,
  TARGET_ARCHI_NAME_X64,
  TARGET_ARCHI_NAME_ARM7,
  TARGET_ARCHI_NAME_ARM8,
  TARGET_ARCHI_NAME_SYSTEMZ,
  TARGET_ARCHI_NAME_POWERPC64,
  TARGET_ARCHI_NAME_UNKNOWN
};

#if __has_include("config.h")
#include "config.h"
#else
#define TARGET_ARCHITECTURE TARGET_ARCHITECTURE_NAME_UNKNOWN
#endif

// Those functions are called on non-x64 platforms for which the feature detection
// is not covered by vale's CPUID support; therefore, we hand-write in C ourselves.
// For now, on non-x64 platforms, if we can compile 128-bit vector code, we can
// also execute it; this is true of: Z, Power, ARM8. In the future, if we consider
// cross-compilation scenarios, we'll have to refine this predicate; it could be the case,
// for instance, that we want our code to run on old revisions of a system without
// vector instructions, in which case we'll have to do run-time feature detection
// in addition to compile-time detection.

#include <stdbool.h>

static inline bool has_vec128_not_avx () {
#if (TARGET_ARCHITECTURE != TARGET_ARCHITECTURE_NAME_X64) && COMPILE_128
  return true;
#else
  return false;
#endif
}

static inline bool has_vec256_not_avx2 () {
#if (TARGET_ARCHITECTURE != TARGET_ARCHITECTURE_NAME_X64) && COMPILE_256
  return true;
#else
  return false;
#endif
}

#endif
