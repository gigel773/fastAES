#include <stdio.h>
#include <malloc.h>
#include <limits.h>
#include <x86intrin.h>
#include "fastAES.h"

#define SIZE 100000
#define MESSAGE_SIZE 1048576

int main() {
    signed char *message = (signed char *) malloc(sizeof(char) * MESSAGE_SIZE);
    signed char *cipher = (signed char *) malloc(sizeof(char) * MESSAGE_SIZE);
    signed char key[] = {'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a'};
    unsigned long long starttick = 0, endtick = 0, min = ULONG_MAX, minimal = ULONG_MAX;
    unsigned int stub;

    printf("Start...\n");
    printf("Minimal difference %llu, minimal clocks %llu\n", min, minimal);

    for (int i = 0; i < MESSAGE_SIZE; i++) {
        message[i] = 'b';
    }

    for (int i = 0; i < SIZE; i++) {
        starttick = __rdtscp(&stub);
        endtick = __rdtscp(&stub);
        min = min > (endtick - starttick) ? endtick - starttick : min;
    }

    printf("Ended collecting minimal difference %llu\n", min);

    for (int i = 0; i < SIZE; i++) {
        starttick = __rdtscp(&stub);
        encrypt(key, message, cipher, MESSAGE_SIZE);
        endtick = __rdtscp(&stub);
        minimal = minimal > (endtick - starttick - min) ? (endtick - starttick - min) : minimal;
    }

    printf("End encryption with %f CPE...\n", (double) minimal / (double) MESSAGE_SIZE);

    minimal = ULONG_MAX;
    for (int i = 0; i < SIZE; i++) {
        starttick = __rdtscp(&stub);
        decrypt(key, cipher, message, MESSAGE_SIZE);
        endtick = __rdtscp(&stub);
        minimal = minimal > (endtick - starttick - min) ? (endtick - starttick - min) : minimal;
    }
    printf("End decryption with %f CPE...\n", (double) minimal / (double) MESSAGE_SIZE);

    free(message);
    free(cipher);
    return 0;
}