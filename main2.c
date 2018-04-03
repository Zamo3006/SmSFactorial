#include <stdio.h>
#include <math.h>


//
// Created by Budig on 03.04.2018.
int main2() {
    int a = 4;
    int b = 31;
    for (b; b > 0; b--) {
        int c = a >> b;
        int d = pow(2, b);
        a  &= ~d;
        printf("%d", c);
    }
}
//

