#include <stdio.h>

int main()
{
    int y = 1; /* used for detecting number of loops needed, dont change */
    int i = 0; /* same as above */
    int z = 7; /* height you want*/
    printf("Give height of traingle you want:");
    scanf("%d", &z);
    while(y < (z+1)){
        for(i = 0; i < (z-y); ++i){
            printf(" ");
            }
        for(i = 0; i < (2*y - 1); ++i){
            printf("X");
        }
        y = y + 1;
        printf("\n");
        }
    }
