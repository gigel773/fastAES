#include <fastAES.h>
#include <stdlib.h>
#include <emmintrin.h>
#include <wmmintrin.h>
#include <ownAES.h>

status encrypt(const signed char *key, const signed char *message, signed char *pDst, int size) {
    /* Validating parameters */
    CHECK_PTR_RET(key);
    CHECK_PTR_RET(message);
    CHECK_PTR_RET(pDst);
    CHECK_MULTIPLICITY_BY(size, 16);

    /* Variables */
    int messageSize = size;
    __m128i chunk;
    __m128i encryptionKeys[11];

    /* Initializing memory */
    signed char *dst = pDst;
    const signed char *src = message;

    ownGenerateEncryptionKeys(key, encryptionKeys);

    /* Encrypting data */
    for (int i = messageSize >> 4; i != 0; i--, src += 16, dst += 16) {
        /* Loading data */
        chunk = _mm_loadu_si128((const __m128i *) src);
        chunk = _mm_xor_si128(chunk, encryptionKeys[0]);
        for (int j = 1; j < 10; j++) {
            chunk = _mm_aesenc_si128(chunk, encryptionKeys[j]);
        }
        chunk = _mm_aesenclast_si128(chunk, encryptionKeys[10]);
        _mm_storeu_si128((__m128i *) dst, chunk);
    }

    return SUCCESS;
}
