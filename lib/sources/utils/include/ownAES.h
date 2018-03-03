#ifndef FASTAESMODULE_OWNAES_H
#define FASTAESMODULE_OWNAES_H

#include <emmintrin.h>
#include <wmmintrin.h>

/**
 * Generates encryption keys according to AES algorithm
 *
 * @param initialKey
 * @param encryptionKeys pointer to array where result keys should be stored (must be 11 elements long)
 */
void ownGenerateEncryptionKeys(const signed char *initialKey, __m128i *encryptionKeys);

/**
 * Generates decryption keys according to AES algorithm
 *
 * @param encryptionKeys pointer to existing encryption keys (must be 11 elements long)
 * @param decryptionKeys pointer to array where result keys should be stored (must be 10 elements long)
 */
void ownGenerateDecryptionKeys(__m128i *encryptionKeys, __m128i *decryptionKeys);

#endif //FASTAESMODULE_OWNAES_H
