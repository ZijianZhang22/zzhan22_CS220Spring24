#include "digit_freq.h"

void digit_freq(int64_t n, int64_t freq[]) {
    //aovid something bad happens
    for (int i = 0; i < 10; ++i) {
        freq[i] = 0;
    }
    // Process each digit in the number
    while (n != 0) {
        int digit = n % 10;  // get the last digit
        freq[digit]++;       // add 1 to the corresponding location
        n /= 10;             // remove the last digit
    }
}
