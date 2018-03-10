package com.nntu.aes;

import com.oracle.tools.packager.IOUtils;

import java.io.File;
import java.io.FileOutputStream;
import java.io.InputStream;
import java.io.OutputStream;

public class AesJavaWrapper {
    static {
        try {
            String name = System.mapLibraryName("libjavaWrapper");
            InputStream in = AesJavaWrapper.class.getResourceAsStream("/" + name);
            File fileOut = new File(name);
            OutputStream out = new FileOutputStream(fileOut);
            byte[] buffer = new byte[1024];
            while (true) {
                int bytesRead = in.read(buffer);
                if (bytesRead == -1)
                    break;
                out.write(buffer, 0, bytesRead);
            }
            in.close();
            out.close();
            System.loadLibrary("libjavaWrapper");
        } catch (Exception e) {
            e.printStackTrace();
        }
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