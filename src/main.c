#include <stdio.h>
#include <math.h>
#include <proc.h>

int main () {
    float a, b, c, d, x1, x2;
    int CountRoots;
    printf( "Vvedite a, b, c cherez probel: " );
    scanf( "%f %f %f", &a, &b, &c );
    process( a, b, c, &d, &x1, &x2, &CountRoots );
    return 0;
}
