#include <stdio.h>
#include <stdlib.h>

int sumuj(int a) {
	if (a < 10) {
		return a;
	}
	int b = 1;
	int c = a;
	int d = 0;
	while (c >= 10) {
		c = c / 10;
		b = b * 10;
	}
	d = c + sumuj(a - (c * b));
	return d;
}



int main()
{
	int m = 0;
	int n = 0;
	printf("Podaj liczbe\n");
	scanf_s("%d", &n);
	n = sumuj(n);
	printf("%d", n);
}