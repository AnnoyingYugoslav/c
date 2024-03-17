#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#pragma warning(disable:4996)
int main()
{
    char what = "g";
    bool end = true;
    while (end) {
        printf("Numery(a) czy litery(b)\n");
        scanf_s("%c", &what);
        if (what == 'a' || what == 'b') {
            end = false;
        }
    }
    FILE* file;
    char line[100];
    int number[5] = { 0 };
    errno_t err = fopen_s(&file, "example.txt", "r+");
    if (err != 0) {
        printf("Failed to open file");
        return;
    }
    while (fgets(line, sizeof(line), file) != NULL) {
        printf("%s", line);
        int gwi = 0;
        char output[150] = { 0 };
        while (line[gwi] == '*') {
            gwi++;
        }
        if (gwi > 5) { printf("Wrong file format"); return; }
        if (gwi > 0) {
            number[gwi - 1]++;
            for (int n = 4; n >= gwi; n--) {
                number[n] = 0;
            }
        }
        if (what == 'a') {
            for (int n = 0; n < gwi; n++) {
                char num_str[13] = { 0 };
                sprintf(num_str, "%d", number[n]);
                strcat(output, num_str);
                strcat(output, ".");
            }
        }
        else if(what == 'b'){
            for (int n = 0; n < gwi; n++) {
                char num_str[13] = { 0 };
                if (n == 0) {
                    char letter[2] = { 0,'\0'};
                    letter[0] = number[n] + 'A' - 1;
                    strcat(output, letter);
                    strcat(output, ".");
                }
                else if (n == 1) {
                    sprintf(num_str, "%d", number[n]);
                    strcat(output, num_str);
                    strcat(output, ".");
                }
                else if (n == 2) {
                    char letter[2] = { 0,'\0' };
                    letter[0] = number[n] + 'a' - 1;
                    strcat(output, letter);
                    strcat(output, ".");
                }
                else {
                    strcat(output, "(");
                    sprintf(num_str, "%d", number[n]);
                    strcat(output, num_str);
                    strcat(output, ")");
                }
            }

        }
        strncat(output, line + gwi, strlen(line) - gwi);
        printf("%s", output);
        fseek(file, -strlen(output), SEEK_CUR); 
        fputs(output, file);
    }
    fclose(file);
    return 0;
}