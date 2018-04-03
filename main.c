#include <stdio.h>
#include <math.h>
#include <time.h>

#define SMALL uint32_t
#define BIG uint64_t
#define SMALL_LENGTH 31
#define ARRAY_LENGTH 50000

int main() {
    SMALL i = 100000;
    SMALL counter = 0;
    BIG full = pow(2, SMALL_LENGTH) - 1;
    BIG rest = 0;
    BIG results[ARRAY_LENGTH] = {1};
    clock_t t;
    t = clock();
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
    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC;

    FILE *f = fopen("result.txt", "w");
    if (f == NULL)
    {
        printf("Error opening file!\n");
        return(1);
    }

    printf("Factorial took %f seconds to execute \n", time_taken);
    printf("Number of entries: %d,", ++counter);
    printf("\nResults: ");
    fprintf(f, "Factorial took %f seconds to execute \n", time_taken);
    fprintf(f, "Number of entries: %d,", counter);
    fprintf(f, "\nResults: ");
    BIG printBit;
    BIG andBits;
    do{
        --counter;
        for (SMALL x = SMALL_LENGTH ; x > 0; x--) {
            SMALL xx = x-1;
            printBit = results[counter] >> xx;
            andBits = pow(2,xx);
            results[counter] &= ~andBits;
            fprintf(f, "%u", printBit);
        }

    }while(counter > 0);
    fclose(f);
    return 0;
}