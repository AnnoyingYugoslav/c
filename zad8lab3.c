#include <stdio.h>
#include<math.h>


int dlugosc(int a) {
	int licznik = 0;
	int setki = 1;
	while (a >= setki) {
		setki *= 10;
		licznik += 1;
	}
	return licznik;
}
int check(int a) {
	int i = 0;
	int square = a * a;
	for (int b = 0; b < dlugosc(a); b++) {
		i += ((square % 10) * pow(10,b));
		square /= 10;
	}
	if (i == a) {
		return(1);
	}
	else {
		return(0);
	}
}
int main()
{
	int a, b;
	printf("Podaj start\n");// podaj liczbe start
	scanf_s("%d",&a);
	printf("Podaj koniec\n"); //podaj liczbe koniec
	scanf_s("%d", &b);
	for (int i = a; i <= b; i++) {
		if (check(i) == 1) { printf("%d\n", i);}
	}
}