#include <stdio.h>
#include <stdlib.h>
#include "digit_freq.h"

int main(int64_t argc, char *argv[]) {

    // convert command-line argument to an integer
    int64_t number = atoll(argv[1]);

    // array to hold digit frequencies
    int64_t freq[10];

    // calculate digit frequencies
    digit_freq(number, freq);

    // print the table
    printf("Digit    Frequency\n");
    printf("-----    ---------\n");
    for (int i = 0; i < 10; ++i) {
        printf("%d        %lld\n", i, freq[i]);
    }
    return 1;
}
