#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#pragma warning(disable:4996)
int main()
{
    FILE* file;
    char line[100];
    int number[5] = {0};
    int numbers[100] = {0};
    int numbers2[100] = {0};
    float numbers3[100] = { 0 };
    errno_t err = fopen_s(&file, "example.txt", "r+");
    if (err != 0) {
        printf("Failed to open file");
        return;
    }
    if (fseek(file, 0L, SEEK_SET) != 0) {
        printf("Failed to reset file pointer");
        return;
    }
    while (fgets(line, sizeof(line), file) != NULL) {
        char* token = strtok(line, " ");
        int i = 0;
        while (token != NULL && i < 100) {
            numbers[i] += atoi(token);
            numbers2[i]++;
            token = strtok(NULL, " ");
            i++;
        }
    }
    int n = 0;
    int p = 0;
    printf("Suma: ");
    while(numbers[n] != 0) {
        printf("%d ", numbers[n]);
        if (numbers2[n] != 0) {
            numbers3[n] = (float)numbers[n] / numbers2[n];
        }
        n++;
    }
    printf("Srednia: ");
    while (p <= n) {
        printf("%f ", numbers3[p]);
        p++;
    }
    fclose(file);
    return;
}