#ifndef FASTAESMODULE_OWNAES_H
#define FASTAESMODULE_OWNAES_H

#include <emmintrin.h>
#include <wmmintrin.h>

/**
 *
 * @param initialKey
 * @param encryptionKeys
 */
void ownGenerateEncryptionKeys(signed char *initialKey, __m128i *encryptionKeys);

/**
 *
 * @param encryptionKeys
 * @param decryptionKeys
 */
void ownGenerateDecryptionKeys(__m128i *encryptionKeys, __m128i *decryptionKeys);

#endif //FASTAESMODULE_OWNAES_H
