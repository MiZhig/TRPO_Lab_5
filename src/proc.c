#include "proc.h"
#include <math.h>
#include <stdio.h>

int process (float a, float b, float c, float *d, float *x1, float *x2, int *CountRoots) {

if(a == 0) {
        if(b == 0) {
            if(c == 0) {
                printf("x - Luboe chislo");
                *CountRoots = -1;
            }
            else {
                printf("Korney net");
                *CountRoots = 0;
            }
        }
        else {
            *x1 = ( -1 ) * ( c / b );
            *x2 = *x1;
            *CountRoots = 1;
        }
    }
    else {

        *d = b * b - 4 * a * c;

        if(*d < 0) {
            printf("Korney net");
            *CountRoots = 0;
        }
        else {
            if(d == 0) {
                *x1 = ( -1 ) * ( c / b );
                *x2 = *x1;
                *CountRoots = 1;
            }
            else {
                *x1 = ( -b + sqrt(*d) ) / ( 2 * a );
                *x2 = ( -b - sqrt(*d) ) / ( 2 * a );
                printf ( " x1 = %f, x2 = %f\n", *x1, *x2 );
                *CountRoots = 2;
            }
        }
    }
return 0;
}
