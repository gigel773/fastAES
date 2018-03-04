package com.nntu.aes;

public class AesJavaWrapper {
   static {
      System.loadLibrary("libjavaWrapper");
   }

   native static String encrypt(String key, String message);
   native static String decrypt(String key, String cipher);
   native static String padWithZeros(String source);

   public static void main(String[] args) {
        String key = "aaaaaaaaaaaaaaaa";
        String message = "bbbbbbbbbbbbbbbb";
        String cipher = AesJavaWrapper.encrypt(key, message);
        System.out.println(cipher.length());
        message = AesJavaWrapper.decrypt(key, cipher);
        System.out.println(message.length());
   }
}