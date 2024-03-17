#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
double atob(double i) {
	if (i <= -1) {
		return 3.31;
	}
	double kwadrat = sin(i) * sin(i);
	double a = kwadrat - 3;
	double b = sqrt(i + 1);
	return a / b;
}


int main()
{
	int n = 0;
	int m = 0;
	double w = 0;
	printf("Podaj m: ");
	scanf_s("%d", &m);
	while (getchar() != '\n') {}
	printf("Podaj n: ");
	scanf_s("%d", &n);
	while (getchar() != '\n') {}
	double** arr = (double**)malloc(m * sizeof(double*));
	for (int i = 0; i < m; i++)
		arr[i] = (double*)malloc(n * sizeof(double));
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			printf("Podaj wartosc pola %d, %d: ", i+1, j+1);
			scanf_s("%lf", &w);
			arr[i][j] = w;
			while (getchar() != '\n') {}
		}
	}
	printf("Wynik: \n");
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			printf("%lf ", atob(arr[i][j]));
		}
		printf("\n");
	}
}