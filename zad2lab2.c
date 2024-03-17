#include <stdio.h>

int main()
{
    char * x = "X"; /* what symbol to pring */
    int y = 1; /* used for detecting number of loops needed, dont change */
    int i = 1; /* same as above */
    int z = 5; /* number of rowes you want*/
    while(y < (z+1)){
        for(i = 0; i < y; ++i){
            printf("%s", x);
            }
        y = y + 1;
        printf("\n");
        }
    }