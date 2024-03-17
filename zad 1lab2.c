#include <stdio.h>

int main()
{
    int m = 4; /* number of multiplications*/
    int n = 1; /* number of additions*/
    double i = 1;
    double j = 1;
    int z = 1;
    double r = 0;
    double k = 1;
    for(i = 1;i < (n+1); ++i){
        for(j = 1;j < (m+1); ++j){
            k = k * (((i*i) + (j*j) - 1)/((2 * i) + (3 * j) + 4));
        }
        r = r + k;
        k = 1; /*zmienic na 1*/
    }
printf("The result is: %f", r);
    }
