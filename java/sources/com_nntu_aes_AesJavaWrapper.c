#include <com_nntu_aes_AesJavaWrapper.h>
#include <fastAES.h>
#include <stdlib.h>

JNIEXPORT jstring JNICALL
Java_com_nntu_aes_AesJavaWrapper_encrypt(JNIEnv *env, jobject obj, jstring key, jstring message) {
    /* Extracting data */
    const signed char *nativeKey = (const signed char *) (*env)->GetStringChars(env, key, 0);
    const signed char *nativeMessage = (const signed char *) (*env)->GetStringChars(env, message, 0);
    const long messageLength = (*env)->GetStringLength(env, message) * 2;
    jstring result;

    /* Variables */
    signed char *cipher = (signed char *) malloc(sizeof(signed char) * messageLength);

    /* Processing data */
    encrypt(nativeKey, nativeMessage, cipher, messageLength);

    /* Turning result back */
    result = (*env)->NewString(env, (const jchar *) cipher, messageLength >> 1);
    (*env)->ReleaseStringChars(env, message, (const jchar *) nativeMessage);
    (*env)->ReleaseStringChars(env, key, (const jchar *) nativeKey);
    free(cipher);

    return result;
}

JNIEXPORT jstring JNICALL
Java_com_nntu_aes_AesJavaWrapper_decrypt(JNIEnv *env, jobject obj, jstring key, jstring cipher) {
    /* Extracting data */
    const signed char *nativeKey = (const signed char *) (*env)->GetStringChars(env, key, 0);
    const signed char *nativeCipher = (const signed char *) (*env)->GetStringChars(env, cipher, 0);
    const long messageLength = (*env)->GetStringLength(env, cipher) * 2;
    jstring result;

    /* Variables */
    signed char *decryptedMessage = (signed char *) malloc(sizeof(signed char) * messageLength);

    /* Processing data */
    decrypt(nativeKey, nativeCipher, decryptedMessage, messageLength);

    /* Turning result back */
    result = (*env)->NewString(env, (const jchar *) decryptedMessage, messageLength >> 1);
    (*env)->ReleaseStringChars(env, cipher, (const jchar *) nativeCipher);
    (*env)->ReleaseStringChars(env, key, (const jchar *) nativeKey);
    free(decryptedMessage);

    return result;
}

JNIEXPORT jstring JNICALL Java_com_nntu_aes_AesJavaWrapper_padWithZeros(JNIEnv *env, jobject obj, jstring source) {

}
