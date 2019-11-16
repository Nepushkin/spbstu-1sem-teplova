#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<locale.h>

int main()
{
	setlocale(LC_ALL, "Russian");
	int n, k, min, max, delta, i, lifes;
	printf("Введите количество этажей в здании: ");
	scanf("%d", &n);
	printf("Введите минимальный этаж: ");
	scanf("%d", &k);
	delta = n / 2;
	min = 1;
	max = delta;
	lifes = 2;
	for (i = 1; min <= max && lifes > 0; i++)
	{
		if (lifes == 2)
		{
			printf("Шаг %d: бросаем с %d этажа.", i, max);
			if (max >= k)
			{
				lifes--;
				printf(" Первый шар разбился");
			}
			else
			{
				if (delta > 1) {
					delta /= 2;
				}
				min = max + 1;
				max = max + delta;
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
			printf("Шаг %d: бросаем с %d этажа.", i, min);
			if (min == k) {
				lifes--;
				printf(" Второй шар разбился");
			}
			else
			{
				min++;
			}
			printf("\n");
		}
	}
	printf("K = %d\n", min);
	//начало нового алгоритма
	int start = 0, sum = 0;
	lifes = 2;
	for (i = 0; sum < n; i++)
	{
		sum += i;
	}
	sum -= i;
	start = n - sum;
	for (i--; i > 0; i--)
	{
		printf("Бросаем с %d этажа.", start);
		//start += i;
		if (start >= k)
		{
			printf("Первый шар разбился на %d этаже.\n", start);
			lifes--;
			min = start - i;
			for (min; min < start; min++)
			{
				printf("Бросаем с %d этажа.", min);
				if (min == k)
				{
					printf("Второй шар разбился на %d этаже.\n", min);
					printf("K = %d", min);
					break;
				}
				printf("\n");
			}
			break;
		}
		start += i;
		printf("\n");
	}

	return 0;
}