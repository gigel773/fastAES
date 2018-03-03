#include <owns.h>

void ownPadWithZeros_8s(const signed char *pSrc, signed char *pDst, srcDstLength lengths) {
    register int i;
#pragma GCC ivdep
    for (i = 0; i < lengths.srcLen; i++) {
        pDst[i] = pSrc[i];
    }
#pragma GCC ivdep
    for (i; i < lengths.dstLen; i++) {
        pDst[i] = 0;
    }
}
