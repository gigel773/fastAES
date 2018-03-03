#include "owns.h"

void ownCopy_8s(const signed char *pSrc, signed char *pDst, int len) {
#pragma GCC ivdep
    for (int i = 0; i < len; i++) {
        pDst[i] = pSrc[i];
    }
}

