#include "fastAES.h"
#include "wmmintrin.h"

static __m128i encryptionKeys[11];
static __m128i decryptionKeys[10];

#define AES_128_key_exp(k, rcon) aes_128_key_expansion(k, _mm_aeskeygenassist_si128(k, rcon))

static __m128i aes_128_key_expansion(__m128i key, __m128i keyGenerated) {
    keyGenerated = _mm_shuffle_epi32(keyGenerated, _MM_SHUFFLE(3, 3, 3, 3));
    key = _mm_xor_si128(key, _mm_slli_si128(key, 4));
    key = _mm_xor_si128(key, _mm_slli_si128(key, 4));
    key = _mm_xor_si128(key, _mm_slli_si128(key, 4));
    return _mm_xor_si128(key, keyGenerated);
}

static inline void ownGenerateEncryptionKeys(signed char *initialKey) {
    __m128i key = _mm_loadu_si128((const __m128i_u *) initialKey);

    encryptionKeys[0] = key;
    encryptionKeys[1] = AES_128_key_exp(encryptionKeys[0], 0x01);
    encryptionKeys[2] = AES_128_key_exp(encryptionKeys[1], 0x02);
    encryptionKeys[3] = AES_128_key_exp(encryptionKeys[2], 0x04);
    encryptionKeys[4] = AES_128_key_exp(encryptionKeys[3], 0x08);
    encryptionKeys[5] = AES_128_key_exp(encryptionKeys[4], 0x10);
    encryptionKeys[6] = AES_128_key_exp(encryptionKeys[5], 0x20);
    encryptionKeys[7] = AES_128_key_exp(encryptionKeys[6], 0x40);
    encryptionKeys[8] = AES_128_key_exp(encryptionKeys[7], 0x80);
    encryptionKeys[9] = AES_128_key_exp(encryptionKeys[8], 0x1B);
    encryptionKeys[10] = AES_128_key_exp(encryptionKeys[9], 0x36);
}

static inline void ownGenerateDecryptionKeys() {
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

static inline void ownShift(__m128i *chunk, int shiftValue) {
    __m128i tmp = *chunk;

    switch (shiftValue) {
        case 15:
            tmp = _mm_srli_si128(tmp, 15);
            break;
        case 14:
            tmp = _mm_srli_si128(tmp, 14);
            break;
        case 13:
            tmp = _mm_srli_si128(tmp, 13);
            break;
        case 12:
            tmp = _mm_srli_si128(tmp, 12);
            break;
        case 11:
            tmp = _mm_srli_si128(tmp, 11);
            break;
        case 10:
            tmp = _mm_srli_si128(tmp, 10);
            break;
        case 9:
            tmp = _mm_srli_si128(tmp, 9);
            break;
        case 8:
            tmp = _mm_srli_si128(tmp, 8);
            break;
        case 7:
            tmp = _mm_srli_si128(tmp, 7);
            break;
        case 6:
            tmp = _mm_srli_si128(tmp, 6);
            break;
        case 5:
            tmp = _mm_srli_si128(tmp, 5);
            break;
        case 4:
            tmp = _mm_srli_si128(tmp, 4);
            break;
        case 3:
            tmp = _mm_srli_si128(tmp, 3);
            break;
        case 2:
            tmp = _mm_srli_si128(tmp, 2);
            break;
        default:
            tmp = _mm_srli_si128(tmp, 1);
            break;
    }

    chunk = &tmp;
}

void encrypt(signed char *key, signed char *message, signed char *pDst, int size) {

    /* Variables */
    int messageSize = size;
    int rem = messageSize % 16;
    __m128i chunk;

    /* Initializing memory */
    signed char *cKey = key;
    signed char *cMessage = message;
    signed char *dst = pDst;
    signed char *src = cMessage;

    ownGenerateEncryptionKeys(cKey);

    /* Encrypting data */
    for (int i = messageSize >> 4; i != 0; i--) {
        /* Loading data */
        chunk = _mm_loadu_si128((const __m128i_u *) src);
        chunk = _mm_xor_si128(chunk, encryptionKeys[0]);
        for (int j = 1; j < 10; j++) {
            chunk = _mm_aesenc_si128(chunk, encryptionKeys[j]);
        }
        chunk = _mm_aesenclast_si128(chunk, encryptionKeys[10]);
        _mm_storeu_si128((__m128i_u *) dst, chunk);

        /* Switching pointers */
        dst += 16;
        src += 16;
    }

    /* Processing tail */
    if (rem) {
        chunk = _mm_loadu_si128((const __m128i_u *) (src - 16 + rem));
        ownShift(&chunk, 16 - rem);
        chunk = _mm_xor_si128(chunk, encryptionKeys[0]);
        for (int j = 1; j < 10; j++) {
            chunk = _mm_aesenc_si128(chunk, encryptionKeys[j]);
        }
        chunk = _mm_aesenclast_si128(chunk, encryptionKeys[10]);
        _mm_storeu_si128((__m128i_u *) dst, chunk);
    }
}

void decrypt(signed char *key, signed char *message, signed char *pDst, int size) {
    /* Variables */
    int messageSize = size;
    int rem = messageSize % 16;
    __m128i chunk;

    /* Initializing memory */
    signed char *cKey = key;
    signed char *cMessage = message;
    signed char *dst = pDst;
    signed char *src = cMessage;

    ownGenerateEncryptionKeys(cKey);
    ownGenerateDecryptionKeys();

    /* Decrypting data */
    for (int i = messageSize >> 4; i != 0; i--) {
        /* Loading data */
        chunk = _mm_loadu_si128((const __m128i_u *) src);
        chunk = _mm_xor_si128(chunk, decryptionKeys[0]);
        for (int j = 1; j < 10; j++) {
            chunk = _mm_aesdec_si128(chunk, decryptionKeys[j]);
        }
        chunk = _mm_aesdeclast_si128(chunk, encryptionKeys[0]);
        _mm_storeu_si128((__m128i_u *) dst, chunk);

        /* Switching pointers */
        dst += 16;
        src += 16;
    }

    /* Processing tail */
    if (rem) {
        chunk = _mm_loadu_si128((const __m128i_u *) (src - 16 + rem));
        ownShift(&chunk, 16 - rem);
        chunk = _mm_xor_si128(chunk, decryptionKeys[0]);
        for (int j = 1; j < 10; j++) {
            chunk = _mm_aesdec_si128(chunk, decryptionKeys[j]);
        }
        chunk = _mm_aesdeclast_si128(chunk, encryptionKeys[0]);
        _mm_storeu_si128((__m128i_u *) dst, chunk);
    }
}
