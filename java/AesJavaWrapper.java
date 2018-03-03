package com.nntu.aes;

public class AesJavaWrapper {
   static {
      System.loadLibrary("libfastAES");
   }

   native String encrypt(String key, String message);
   native String decrypt(String key, String cipher);
   native String padWithZeros(String source);
}