#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#pragma warning(disable:4996)

double fun0(double a, double b, double c, double d){
    a = (a + b + c + d) / 4;
    return a;
}

double fun1(double a, double b, double c, double d){
    a = min(a, b);
    a = min(a, c);
    a = min(a, d);
    return a;
}

double fun2(double a, double b, double c, double d){
    a = max(a, b);
    a = max(a, c);
    a = max(a, d);
    return a;
}

double (*func_ptr[3])(double, double, double, double) = { fun0, fun1, fun2 };


int main()
{
    int int1, int2 = 0;
    double d1, d2, d3, d4,d5 = 0;
    FILE* file;
    FILE* file2;
    char line[100];
    errno_t err = fopen_s(&file, "pomiary.txt", "r");
    if (err != 0) {
        printf("Failed to open file");
        return;
    }
    err = fopen_s(&file2, "wyniki.txt", "w");
    if (err != 0) {
        printf("Failed to open file");
        return;
    }
    while (fscanf(file, "%d %lf %lf %lf %lf %d", &int1, &d1, &d2, &d3, &d4, &int2) != EOF) {
        if (int2 >= 0 && int2 <= 2) {
            d5 = (*func_ptr[int2])(d1,d2,d3,d4);
            fprintf(file2, "%d %lf %d\n", int1, d5, int2);
        }
    }
    fclose(file);
    return;
}