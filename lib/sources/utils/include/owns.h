#ifndef FASTAESMODULE_OWNS_H
#define FASTAESMODULE_OWNS_H

typedef struct {
    int srcLen;
    int dstLen;
} srcDstLength;

/**
 *
 * @param pSrc
 * @param pDst
 * @param len
 */
void ownCopy_8s(const signed char *pSrc, signed char *pDst, int len);

/**
 *
 * @param pSrc
 * @param pDst
 * @param len
 */
void ownPadWithZeros_8s(const signed char *pSrc, signed char *pDst, srcDstLength lengths);

#endif //FASTAESMODULE_OWNS_H
