#include <fastAES.h>
#include <stdlib.h>

status padWithZeros(const signed char *pSrc, signed char *pDst, srcDstLength lengths) {
    /* Validating parameters */
    CHECK_PTR_RET(pSrc);
    CHECK_PTR_RET(pDst);

    /* Variables */
    register int i;

    /* Main loop */
#pragma GCC ivdep
    for (i = 0; i < lengths.srcLen; i++) {
        pDst[i] = pSrc[i];
    }
#pragma GCC ivdep
    for (i; i < lengths.dstLen; i++) {
        pDst[i] = 0;
    }

    return SUCCESS;
}
