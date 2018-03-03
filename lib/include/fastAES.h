#ifndef ENCRYPTOR_INTERNAL_H
#define ENCRYPTOR_INTERNAL_H

#include "definitions.h"

/**
 *
 * @param key
 * @param message
 * @param pDst
 * @param size
 */
status encrypt(const signed char *key, signed char *message, signed char *pDst, int size);

/**
 *
 * @param key
 * @param message
 * @param pDst
 * @param size
 */
status decrypt(const signed char *key, signed char *message, signed char *pDst, int size);

/**
 *
 * @param pSrc
 * @param pDst
 * @return
 */
status padWithZeros(const signed char *pSrc, signed char *pDst, srcDstLength lengths);

#endif //ENCRYPTOR_INTERNAL_H
