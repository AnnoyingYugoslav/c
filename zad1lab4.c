#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
	char ch;
	int counter = 0;
	char what;
	printf("Jaki znak liczyc?");
	scanf_s("%c", &what);
	FILE* filePointer;
	errno_t error = fopen_s(&filePointer, "example.txt", "r");
	if (error != 0) {
		printf("Plik niedostepny \n");
		return 0;
	}
	else{
		while ((ch = fgetc(filePointer)) != EOF){
			printf("%c", ch);
			if (ch == what) {
				counter++;
			}
		}
	}
	fclose(filePointer);
	printf("\nZnaleziono %d znakow %c.", counter, what);
	return;
}