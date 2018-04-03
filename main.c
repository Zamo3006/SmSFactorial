#include <stdio.h>
#include <math.h>

#define SMALL uint32_t
#define BIG uint64_t
#define SMALL_LENGTH 31
#define ARRAY_LENGTH 49000

int main() {
    SMALL i = 100000;
    SMALL counter = 0;
    BIG full = pow(2, SMALL_LENGTH) - 1;
    BIG rest = 0;
    BIG results[ARRAY_LENGTH] = {1};
    for (BIG mult = 1; mult <= i; mult++) {
        for (SMALL current = 0; current <= counter; current++) {
            results[current] *= mult;
            results[current] += rest;
            rest = results[current] >> SMALL_LENGTH;
            results[current] = results[current] & full;
            if (rest != 0 && current == counter) {
                ++counter;
            }
        }
    }

    printf("Number of entries: %d,", counter+1);

    printf("\nResults: ");
    printf("%u \n", results[0]);
    BIG printBit;
    BIG andBits;
    do  {
        for (SMALL x = SMALL_LENGTH ; x > 0; x--) {
            printBit = results[counter] >> x;
            andBits = pow(2,x);
            results[counter] &= ~andBits;
         //   printf("%u", printBit);
        }
        if(counter != 0)
        --counter;
    }while(counter > 0);

    return 0;
}