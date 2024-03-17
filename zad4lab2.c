#include <stdio.h>
int dividers(int a) {
	int sum = 0;
	for (int i = 1; i < a; i++) {
		if ((a % i) == 0) {
			sum += i;
		}
	}
	return sum;
}
int main()
{
	int a = 0; /*[1 to a]*/
	int b = 0;
	int c = 0;
	printf("Give the max number: ");
	scanf_s("%d", &a);
	for (int i = 0; i < a; i++) {
		b = dividers(i);
		c = dividers(b);
		if (i == c) {
			printf("%d, %d \n", i, b);
		}
		b = 0;
		c = 0;
	}
}