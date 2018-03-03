#include <ownAES.h>

static inline __m128i aes_128_key_expansion(__m128i key, __m128i keyGenerated) {
    keyGenerated = _mm_shuffle_epi32(keyGenerated, _MM_SHUFFLE(3, 3, 3, 3));
    key = _mm_xor_si128(key, _mm_slli_si128(key, 4));
    key = _mm_xor_si128(key, _mm_slli_si128(key, 4));
    key = _mm_xor_si128(key, _mm_slli_si128(key, 4));

    return _mm_xor_si128(key, keyGenerated);
}

void ownGenerateEncryptionKeys(signed char *initialKey, __m128i *encryptionKeys) {
    __m128i key = _mm_loadu_si128((const __m128i *) initialKey);

    encryptionKeys[0] = key;
    encryptionKeys[1] = aes_128_key_expansion(encryptionKeys[0], _mm_aeskeygenassist_si128(encryptionKeys[0], 0x01));
    encryptionKeys[2] = aes_128_key_expansion(encryptionKeys[1], _mm_aeskeygenassist_si128(encryptionKeys[1], 0x02));
    encryptionKeys[3] = aes_128_key_expansion(encryptionKeys[2], _mm_aeskeygenassist_si128(encryptionKeys[2], 0x04));
    encryptionKeys[4] = aes_128_key_expansion(encryptionKeys[3], _mm_aeskeygenassist_si128(encryptionKeys[3], 0x08));
    encryptionKeys[5] = aes_128_key_expansion(encryptionKeys[4], _mm_aeskeygenassist_si128(encryptionKeys[4], 0x10));
    encryptionKeys[6] = aes_128_key_expansion(encryptionKeys[5], _mm_aeskeygenassist_si128(encryptionKeys[5], 0x20));
    encryptionKeys[7] = aes_128_key_expansion(encryptionKeys[6], _mm_aeskeygenassist_si128(encryptionKeys[6], 0x40));
    encryptionKeys[8] = aes_128_key_expansion(encryptionKeys[7], _mm_aeskeygenassist_si128(encryptionKeys[7], 0x80));
    encryptionKeys[9] = aes_128_key_expansion(encryptionKeys[8], _mm_aeskeygenassist_si128(encryptionKeys[8], 0x1B));
    encryptionKeys[10] = aes_128_key_expansion(encryptionKeys[9], _mm_aeskeygenassist_si128(encryptionKeys[9], 0x36));
}

void ownGenerateDecryptionKeys(__m128i *encryptionKeys, __m128i *decryptionKeys) {
    decryptionKeys[0] = encryptionKeys[10];
    decryptionKeys[1] = _mm_aesimc_si128(encryptionKeys[9]);
    decryptionKeys[2] = _mm_aesimc_si128(encryptionKeys[8]);
    decryptionKeys[3] = _mm_aesimc_si128(encryptionKeys[7]);
    decryptionKeys[4] = _mm_aesimc_si128(encryptionKeys[6]);
    decryptionKeys[5] = _mm_aesimc_si128(encryptionKeys[5]);
    decryptionKeys[6] = _mm_aesimc_si128(encryptionKeys[4]);
    decryptionKeys[7] = _mm_aesimc_si128(encryptionKeys[3]);
    decryptionKeys[8] = _mm_aesimc_si128(encryptionKeys[2]);
    decryptionKeys[9] = _mm_aesimc_si128(encryptionKeys[1]);
}

