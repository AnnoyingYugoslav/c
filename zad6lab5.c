#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

int rown(int a, int b) {
	if (a == b) {
		return 1;
	}
	else {
		return 0;
	}
}
int przew(int a, int b) {
	if (a <= b) {
		return 0;
	}
	else {
		return 1;
	}
}

int main()
{
	int n = 0;
	int m = 0;
	int w = 0;
	printf("Podaj m(max 15): ");
	scanf_s("%d", &m);
	while (getchar() != '\n') {}
	printf("Podaj n(max 15): ");
	scanf_s("%d", &n);
	if (n > 15 || m > 15) {
		printf("Bylo maks 15, jest wiecej, nie robie!");
		return;
	}
	while (getchar() != '\n') {}
	int** arr = (int**)malloc(m * sizeof(int*));
	int** arr2 = (int**)malloc(m * sizeof(int*));
	int** arr3 = (int**)malloc(m * sizeof(int*));
	for (int i = 0; i < m; i++) {
		arr[i] = (int*)malloc(n * sizeof(int));
		arr2[i] = (int*)malloc(n * sizeof(int));
		arr3[i] = (int*)malloc(n * sizeof(int));
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			arr3[i][j] = 0;
		}
	}
	printf("Macierz 1:\n ");
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			printf("Podaj wartosc pola %d, %d: ", i+1, j+1);
			scanf_s("%d", &w);
			arr[i][j] = w;
			while (getchar() != '\n') {}
		}
	}
	printf("Macierz 2:\n ");
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			printf("Podaj wartosc pola %d, %d: ", i + 1, j + 1);
			scanf_s("%d", &w);
			arr2[i][j] = w;
			while (getchar() != '\n') {}
		}
	}
	printf("Wynik, macierz rownosci: \n");
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			arr3[i][j] = rown(arr[i][j], arr2[i][j]);
			printf("%d ",arr3[i][j]);
		}
		printf("\n");
	}
	printf("Wynik, macierz przewagi: \n");
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			arr3[i][j] = przew(arr[i][j], arr2[i][j]);
			printf("%d ", arr3[i][j]);
		}
		printf("\n");
	}
}