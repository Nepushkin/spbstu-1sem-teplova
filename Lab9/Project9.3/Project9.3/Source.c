#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<locale.h>

int main()
{
	setlocale(LC_ALL, "Russian");
	int n, k, min, max, delta, i, lifes;
	int match = 1;
	printf("¬ведите количество этажей в здании: ");
	scanf("%d", &n);
	printf("¬ведите минимальный этаж: ");
	scanf("%d", &k);
	delta = n / 2;
	min = 1;
	max = delta;
	lifes = 2;
	for (i = 1; min <= max && lifes > 0; i++)
	{
		if (lifes == 2)
		{
			printf("Ўаг %d: бросаем с %d этажа.", i, max);
			if (max >= k)
			{
				lifes--;
				printf(" ѕервый шар разбилс€");
			}
			else
			{
				if (delta > 1) {
					delta /= 2;
				}
				min = max + 1;
				max = max + delta;
				if (min > n && lifes == 2)
				{
					printf("\nK больше количетва этажей\n");
					match = 0;
					break;
				}
			}
			printf("\n");
		}
		else
		{
			if (delta == 1)
			{
				min = max;
				break;
			}
			printf("Ўаг %d: бросаем с %d этажа.", i, min);
			if (min == max - 1)
			{
				min++;
				printf("\n");
				break;
			}
			if (min == k) {
				lifes--;
				printf(" ¬торой шар разбилс€");
			}
			else
			{
				min++;
			}
			printf("\n");
		}
	}
	if (match == 1)
	{
		printf("K = %d\n", min);
	}
	
	if (n % 2 == 0)
	{
		printf("ћаксиальное количество шагов дл€ заданного N: %d", n / 2);
	}
	else
	{
		printf("ћаксиальное количество шагов дл€ заданного N: %d", n / 2 + 1);
	}
	// разобратьс€ с максимальным количеством итераций дл€ нечетного количества этажей

	return 0;
}