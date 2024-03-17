#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct towary {
	char nazwa[16];
	int ile;
	float cena;
} towar;

void add(int current, towar* point) {
	if (current >= 50) {
		printf("Osiągnieto limit");
		return;
	}
	char name[16];
	int amount = 0;
	float price = 0;
	printf("Podaj nazwe: ");
	scanf_s("%15s", name, sizeof(name));
	while (getchar() != '\n') {}
	printf("Podaj ilosc: ");
	scanf_s(" %d", &amount);
	while (getchar() != '\n') {}
	printf("Podaj cene per sztke: ");
	scanf_s(" %f", &price);
	while (getchar() != '\n') {}
	strcpy(point->nazwa, name);
	point->ile = amount;
	point->cena = price;
}


int main()
{
	int current = 0;
	bool isend = true;
	char t = "a";
	struct towary *list[50];
	float total = 0;
	while (isend) {
		total = 0;
		printf("Podaj polecenie\n");
		scanf_s(" %c", &t);
		while (getchar() != '\n') {}
		switch (t) {
		case 'N':
			if (current >= 50) { printf("Error: full"); break; }
			list[current] = malloc(sizeof(struct towary));
			add(current, list[current]);
			current = current + 1;
			break;
		case 'n':
			if (current >= 50) { printf("Error: full"); break; }
			list[current] = malloc(sizeof(struct towary));
			add(current, list[current]);
			current = current + 1;
			break;
		case 'W':
			if (current == 0) { printf("Puste\n"); break; }
			for (int i = 0; i < current; i++) {
				printf("Object:%d, %s\n", i+1, list[i]->nazwa);
			}
			break;
		case 'w':
			if (current == 0) { printf("Puste\n"); break; }
			for (int i = 0; i < current; i++) {
				printf("Object:%d, %s\n", i + 1, list[i]->nazwa);
			}
			break;
		case 'R':
			if (current == 0) { printf("Puste\n"); break; }
			for (int i = 0; i < current; i++) {
				total = total + (list[i]->cena * list[i]->ile);
			}
			printf("Cena laczna: %f\n", total);
			break;
		case 'r':
			if (current == 0) { printf("Puste\n"); break; }
			for (int i = 0; i < current; i++) {
				total = total + (list[i]->cena * list[i]->ile);
			}
			printf("Cena laczna: %f\n", total);
			break;
		case 'Q':
			isend = false;
			printf("Koniec");
		case 'q':
			isend = false;
			printf("Koniec");
		default:
			printf("Nie dostepna komenda");
		}
	}
}