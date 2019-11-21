#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<locale.h>
#include<math.h>

int main()
{
	setlocale(LC_ALL, "Russian");
	int n, k;
	printf("Введите количество этажей в здании: ");
	scanf("%d", &n);
	printf("Введите минимальный этаж: ");
	scanf("%d", &k);

	int i = ceil((sqrt(1 + 8 * n) - 1) / 2) - 1;
	int end = n - i * (i + 1) / 2;
	int start = 0;
	int steps = 1;
	int lifes = 2;
	int maxsteps = i + 1;

	for (; i >= 0 && lifes > 0 && start <= end; i--, steps++)
	{
		if (lifes == 2 && end < k)
		{
			printf("%d шаг. Бросаем первый шар с %2d этажа. Шар не разбился.\n", steps, end);
			start = end + 1;
			end += i;
		}
		else if (lifes == 2 && end >= k)
		{
			printf("%d шаг. Бросаем первый шар с %2d этажа. Первый шар разбился.\n", steps, end);
			lifes--;
			if (start == 0)
			{
				start = 1;
				end--;
			}
		}
		else if (lifes == 1 && start < k)
		{
			printf("%d шаг. Бросаем второй шар с %2d этажа. Шар не разбился.\n", steps, start);
			start++;
		}
		else if (lifes == 1 && start >= k)
		{
			printf("%d шаг. Бросаем второй шар с %2d этажа. Второй шар разбился.\n", steps, start);
			lifes--;
		}
	}
	printf("Потребовавшееся число шагов = %d\n", steps - 1);
	printf("Максимальное число шагов = %d\n", maxsteps);
	if (lifes == 2)
	{
		printf("Минимальный этаж, на котором шар разобьется больше высоты здания\n");
	}
	else
	{
		printf("Минимальный этаж, на котором шар разобьется = %d\n", start);
	}

	return 0;
}