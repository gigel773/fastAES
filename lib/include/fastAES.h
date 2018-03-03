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
status encrypt(signed char *key, signed char *message, signed char *pDst, int size);

/**
 *
 * @param key
 * @param message
 * @param pDst
 * @param size
 */
status decrypt(signed char *key, signed char *message, signed char *pDst, int size);

#endif //ENCRYPTOR_INTERNAL_H
