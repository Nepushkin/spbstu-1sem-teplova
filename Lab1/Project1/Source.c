#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
int main()
{
	setlocale(LC_ALL, "Russian");
	int r; // r-кол-во рядов
	int n; // n-кол-во мест в ряду
	int p; // p-кол-во учеников
	int k; // k-общее кол-во мест
	int i;
	printf("Введите количество рядов, количество мест в ряду и количество учеников через пробел: ");
	scanf("%d %d %d", &r, &n, &p);
	k = n * r;
	if (k < p)
	{
		printf("\n", (p - k));
	}
	for (i = 0; i < p; i++)
	{
		printf("Ученик %d садится на %d ряд на %d место", i + 1, i / n + 1, i % n + 1);
		if (k <= i)
		{
			printf(" на дополнительный стул");
		}
		printf("\n");
	}
	return 0;
}