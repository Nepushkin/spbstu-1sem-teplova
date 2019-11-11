#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
	double a, b, c, d, x1, x2, x, h, n;
	FILE *in;
	FILE *out1;
	FILE *out2;
	in = fopen("in.txt", "r");
	out1 = fopen("out1.txt", "w");
	out2 = fopen("out2.txt", "w");
	fscanf(in, "%lf", &a);
	fscanf(in, "%lf", &b);
	fscanf(in, "%lf", &c);
	d = b * b - 4 * a * c;
	if (a == 0)
	{
		if (b == 0 && c != 0)
		{
			fprintf(out1, "NET KORNEY");
			fprintf(out2, "NET KORNEY");
		}	
		if (b == 0 && c == 0)
		{
			fprintf(out1, "x - LUBOE CHISLO");
			fprintf(out2, "x - LUBOE CHISLO");
		}
		if(b != 0 && c != 0)
		{
			x = -c / b;
			fprintf(out2, "|____x____|____y____|\n");
			fprintf(out2, "|%9.2lf|    0    |\n", x);
			fprintf(out2, "|_________|_________|\n");
			fprintf(out1, "x = %lf", -c/b);
		}
		if (b != 0 && c == 0)
		{
			fprintf(out2, "|____x____|____y____|\n");
			fprintf(out2, "|    0    |    0    |\n", x);
			fprintf(out2, "|_________|_________|\n");
			fprintf(out1, "x = 0");
		}
	}
	else
	{
		if (d == 0)
		{
			x = b / (2 * a);
			fprintf(out2, "|____x____|____y____|\n");
			fprintf(out2, "|%9.2lf|    0    |\n", x);
			fprintf(out2, "|_________|_________|\n");
			fprintf(out1, "x = %lf", b/(2 * a));
		}
		if (d < 0)
		{
			fprintf(out1, "NET KORNEY");
		}
		if (d > 0)
		{
			x1 = (-b + sqrt(d)) / (2 * a);
			x2 = (-b - sqrt(d)) / (2 * a);
			if (x2 > x1)
			{
				h = x2 - x1;
				x = x1 - h;
			}
			else
			{
				h = x1 - x2;
				x = x2 - h;
			}
			n = h / 20;
			fprintf(out2, "|____x____|____y____|\n");
			for (int i = 0; i < 60; i++)
			{
				fprintf(out2, "|%9.2lf|%9.2lf|\n", x + i * n, a * (x + i * n) * (x + i * n) + b * (x + i * n) + c);
			}
			fprintf(out2, "|_________|_________|\n");
			fprintf(out1, " x1 = %lf \n x2 = %lf", (-b + sqrt(d)) / (2 * a), (-b - sqrt(d)) / (2 * a));
		}
	}
	fclose(out1);
	fclose(in);
	return 0;
}