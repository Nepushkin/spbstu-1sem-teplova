#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
#include<locale.h>

int charToDigitNumber(char c)
{
	if (c >= '0' && c <= '9')
	{
		return c - '0';
	}
	if (c >= 'A' && c <= 'Z')
	{
		return c - 'A' + 10;
	}
	if (c >= 'a' && c <= 'z')
	{
		return c - 'a' + 10;
	}
	return -1;
}
char numberToCharDigit(int number)
{
	if (number < 10)
	{
		return (char)('0' + number);
	}
	return (char)('A' + (number - 10));
}
int isNumber(char c)
{
	if (c >= '0' && c <= '9')
	{
		return 1;
	}
	return 0;
}
int isLetter(char c)
{
	if (c >= 'A' && c <= 'Z')
	{
		return 1;
	}
	if (c >= 'a' && c <= 'z')
	{
		return 1;
	}
	return 0;
}
int isDot(char c)
{
	if (c == '.' || c == ',')
	{
		return 1;
	}
	return 0;
}
double inputNumber(int syst)
{
	double result = 0;
	int negPower = 0;
	char c = getchar();
	while ((c = getchar()) != '\n')
	{
		if (isDot(c))
		{
			if (negPower > 0)
			{
				return -1;
			}
			negPower = 1;
			continue;
		}
		if (!(isNumber(c) || isLetter(c)) || charToDigitNumber(c) >= syst)
		{
			return -1;
		}
		result = result * syst + charToDigitNumber(c);
		if (negPower > 0)
		{
			negPower++;
		}
	}
	for (int i = 1; i < negPower; i++)
	{
		result = result / syst;
	}
	return result;
}
void outputNumber(double number, int syst)
{
	int numInt = floor(number);
	int digitscount = 0;
	int digits[100];
	while (numInt != 0)
	{
		digits[digitscount] = numInt % syst;
		digitscount++;
		numInt /= syst;
	}
	for (int i = digitscount - 1; i >= 0; i--)
	{
		printf("%c", numberToCharDigit(digits[i]));
	}
	number -= floor(number);
	if (number > 0)
	{
		printf(",");
		while (number > 0)
		{
			number = number * syst;
			printf("%c", numberToCharDigit(floor(number)));
			number -= floor(number);
		}
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int q, p;
	printf("Введите основание исходной системы счисления: ");
	scanf("%d", &q);
	printf("Введите число: ");
	double num = inputNumber(q);
	if (num == -1)
	{
		printf("Некорректный ввод числа\n");
		return 0;
	}
	printf("Введенное число в десятичной: %lf\n", num);
	printf("Введите основание целевой системы счисления: ");
	scanf("%d", &p);
	outputNumber(num, p);
	return 0;
}