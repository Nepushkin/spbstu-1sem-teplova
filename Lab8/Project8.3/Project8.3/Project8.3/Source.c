#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
#include<locale.h>
double log10(double x, int k)
{
	double res = 0; //объ€вл€ем переменную, отвечающую за цифру перед зап€той
	double pow = 0.5;
	int n = 0;
	while (x > 10) //сокращаем наше число до 1 знака перед зап€той
	{
		x /= 10;
		n++;
	}
	while (x < 1) //если оно оч маленькое, то домнажаем до 1 знака перед зап€той
	{
		x *= 10;
		n--;
	}
	res = n;
	//printf("%d.", n);
	for (int i = 0; i < k; i++) //тут мы высчитываем точность логорифма нашего до k знаков поосле зап€той в двоичном коде 
	{
		if (x * x < 10)
		{
			//printf("0");
		}
		else
		{
			res += pow;
			//printf("1");
		}
		x = x * x;
		if (x > 10)
		{
			x /= 10;
		}
		pow /= 2;
	}
	return res;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	double x;
	double lgx;
	double log10x;
	double absLgLog;
	FILE *f = fopen("out.txt", "w");
	int k;
	printf("Input k : ");
	scanf("%d", &k);

	printf("  X   |     A     |   lg(x)   |   abs((lg(x)-A)/A)\n");
	for (x = 0.1; x < 10; x += 0.1)
	{
		lgx = log(x) / log(10);
		log10x = log10(x, k);
		absLgLog = 1 - lgx / log10x;
		if (absLgLog < 0) absLgLog *= -1;
		if (lgx == -0)
		{
			absLgLog = 0;
		}
		printf("%5.2lf | %9.5lf | %9.5lf | %9.5lf\n", x, log10x, lgx, absLgLog);
		fprintf(f, "%lf\t%lf\t%lf\t%lf\n", x, log10x, lgx, absLgLog);
	}
	fclose(f);

	return 0;
}