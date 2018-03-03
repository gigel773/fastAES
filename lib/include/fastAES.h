#ifndef ENCRYPTOR_INTERNAL_H
#define ENCRYPTOR_INTERNAL_H

#include "definitions.h"

/**
 * Performs encrypting of income message according to AES algorithm
 *
 * @param key initial key
 * @param message incoming message
 * @param pDst pointer to results of encrypting
 * @param size size of message (must be divisible by 16)
 * @returns SUCCESS if encrypting was successful
 *          BAD_PARAMETERS if some of parameters were bad
 */
status encrypt(const signed char *key, signed char *message, signed char *pDst, int size);

/**
 * Performs decrypting of ciphered message according to AES algorithm
 *
 * @param key initial key used for encrypting
 * @param message ciphered message
 * @param pDst pointer to result
 * @param size size of message (must be divisible by 16)
 * @returns SUCCESS if encrypting was successful
 *          BAD_PARAMETERS if some of parameters were bad
 */
status decrypt(const signed char *key, signed char *message, signed char *pDst, int size);

/**
 * Performs padding with zeros until specified length
 *
 * @param pSrc pointer to source data
 * @param pDst pointer to destination data
 * @returns SUCCESS if encrypting was successful
 *          BAD_PARAMETERS if some of parameters were bad
 */
status padWithZeros(const signed char *pSrc, signed char *pDst, srcDstLength lengths);

#endif //ENCRYPTOR_INTERNAL_H
