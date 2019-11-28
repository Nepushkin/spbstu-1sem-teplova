#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#include <time.h>

int nod(int n, int m)
{
	while (n*m != 0)
	{
		if (n < m) m = m % n;
		else n = n % m;
	}
	return n + m;
}

int fibRec(int n)
{
	if (n < 3) return 1;
	return fibRec(n - 1) + fibRec(n - 2);
}

int fibCycle(int n)
{
	if (n < 3) return 1;
	int n1 = 0, n2 = 1;
	for (int i = 1; i < n; i++)
	{
		n2 = n1 + n2;
		n1 = n2 - n1;
	}
	return n2;
}

int isSimple(int n)
{
	int top = sqrt(n) + 1;
	for (int i = 2; i <= top; i++)
	{
		if ((n%i) == 0)
		{
			return 0;
		}
	}
	return 1;
}

int fibAprox(int n)
{
	double res = 0;
	res = (pow(((1 + sqrt(5)) / 2), n) - pow(((1 - sqrt(5)) / 2), n)) / sqrt(5);
	return (int)res;
}
double fibNumber(int n)
{
	double res = 0;

	return res;
}

//1 1 2 3 5 8 13 21
int main()
{
	srand(time(0));
	setlocale(LC_ALL, "Russian");
	int k;
	printf("Введите сколько месяцев прошло: ");
	scanf("%d", &k);
	printf("Cycle\n");
	printf("Номер месяца | Количество пар кроликов | Приближенное значение | F(n + 1) / F(n) | Асимптотика  |\n");
	unsigned int start_time;
	start_time = clock();
	for (int i = 1; i <= k; i++)
	{
		long fib = fibCycle(i);
		long fib1 = fibCycle(i + 1);
		printf(
			"%13d| %24d| %22d| %16.6lf| %13.2lf|\n",
			i,
			fib,
			fibAprox(i),
			(double)fib1 / fib,
			(double)pow((1 + sqrt(5)), i) / (sqrt(5) * pow(2, i))
		);
	}
	double algtime = (double)(clock() - start_time) / CLOCKS_PER_SEC;
	printf("Время работы цикла: %lf сек\n", algtime);
	
	printf("\nRecoursive\n");
	printf("Номер месяца | Количество пар кроликов | Приближенное значение | F(n + 1) / F(n) | Асимптотика  |\n");
	start_time = clock();
	for (int i = 1; i <= k; i++)
	{
		long fib = fibRec(i);
		long fib1 = fibRec(i + 1);
		printf(
			"%13d| %24d| %22d| %16.6lf| %13.2lf|\n",
			i,
			fib,
			fibAprox(i),
			(double)fib1 / fib,
			(double)pow((1 + sqrt(5)), i) / (sqrt(5) * pow(2, i))
		);
	}
	algtime = (double)(clock() - start_time) / CLOCKS_PER_SEC;
	printf("Время работы рекурсии: %lf сек\n", algtime);
	

	printf("Fn = n: \n");
	for (int i = 1; i <= k; i++)
	{
		if (i == fibCycle(i))
		{
			printf("%d \n", i);
		}
	}
	printf("\n");

	printf("Fn = n^2: \n");
	for (int i = 1; i <= k; i++)
	{
		if (i * i == fibCycle(i))
		{
			printf("%d \n", i);
		}
	}
	printf("\n");

	printf("Fn - простое число: \n");
	for (int i = 1; i <= k; i++)
	{
		int fib = fibCycle(i);
		if (isSimple(fib))
		{
			printf("%d \n", fib);
		}
	}
	printf("\n");

	int n = rand() % 42 + 1;
	int m = rand() % 42 + 1;
	printf(
		"NOD(%d; %d) = %d = %d = F(NOD(%d; %d))\n",
		fibCycle(n), fibCycle(m),
		nod(fibCycle(n), fibCycle(m)),
		fibCycle(nod(n, m)),
		n, m);
	return 0;
}