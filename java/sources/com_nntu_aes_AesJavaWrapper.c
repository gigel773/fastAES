#include <com_nntu_aes_AesJavaWrapper.h>
#include <fastAES.h>
#include <stdlib.h>

JNIEXPORT jstring JNICALL
Java_com_nntu_aes_AesJavaWrapper_encrypt(JNIEnv *env, jobject obj, jstring key, jstring message) {
    /* Extracting data */
    const signed char *nativeKey = (const signed char *) (*env)->GetStringUTFChars(env, key, 0);
    const signed char *nativeMessage = (const signed char *) (*env)->GetStringUTFChars(env, message, 0);
    const long messageLength = (*env)->GetStringUTFLength(env, message);
    const long keyLength = (*env)->GetStringLength(env, key);
    jstring result;

    /* Variables */
    signed char *cipher = (signed char *) malloc(sizeof(signed char) * messageLength);

    /* Processing data */
    encrypt(nativeKey, nativeMessage, cipher, messageLength);

    /* Turning result back */
    result = (*env)->NewStringUTF(env, (const char *) cipher);
    free(cipher);

    return result;
}

JNIEXPORT jstring JNICALL
Java_com_nntu_aes_AesJavaWrapper_decrypt(JNIEnv *env, jobject obj, jstring key, jstring cipher) {
    /* Extracting data */
    const signed char *nativeKey = (const signed char *) (*env)->GetStringUTFChars(env, key, 0);
    const signed char *nativeCipher = (const signed char *) (*env)->GetStringUTFChars(env, cipher, 0);
    const long messageLength = (*env)->GetStringUTFLength(env, cipher);
    const long keyLength = (*env)->GetStringLength(env, key);
    jstring result;

    /* Variables */
    signed char *decryptedMessage = (signed char *) malloc(sizeof(signed char) * messageLength);

    /* Processing data */
    decrypt(nativeKey, nativeCipher, decryptedMessage, messageLength);

    /* Turning result back */
    result = (*env)->NewStringUTF(env, (const char *) decryptedMessage);
    free(decryptedMessage);

    return result;
}

JNIEXPORT jstring JNICALL Java_com_nntu_aes_AesJavaWrapper_padWithZeros(JNIEnv *env, jobject obj, jstring source) {

}
