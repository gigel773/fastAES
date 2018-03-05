package com.nntu.aes;

public class AesJavaWrapper {
    static {
        System.loadLibrary("libjavaWrapper");
    }

    /**
     * Performs encrypting of income message according to AES algorithm
     *
     * @param key     {@link String}initial key
     * @param message {@link String}incoming message
     * @return {@link String} ciphered message
     */
    public static native String encrypt(String key, String message);

    /**
     * Performs decrypting of ciphered message according to AES algorithm
     *
     * @param key    {@link String} initial key used for encrypting
     * @param cipher {@link String} ciphered message
     * @return {@link String} decrypted message
     */
    public static native String decrypt(String key, String cipher);

    /**
     * Performs padding with zeros until specified length
     *
     * @param source {@link String} pointer to source data
     * @return string {@link String} padded with zeros with nearest length divisible by 16
     */
    public static native String padWithZeros(String source);
}