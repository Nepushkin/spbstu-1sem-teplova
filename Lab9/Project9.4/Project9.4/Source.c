#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<locale.h>

int main()
{
	setlocale(LC_ALL, "Russian");
	int n, k, min, max, delta, i, lifes;
	int match = 1;
	printf("������� ���������� ������ � ������: ");
	scanf("%d", &n);
	printf("������� ����������� ����: ");
	scanf("%d", &k);
	delta = n / 2;
	min = 1;
	max = delta;
	lifes = 2;
	for (i = 1; min <= max && lifes > 0; i++)
	{
		if (lifes == 2)
		{
			printf("��� %d: ������� � %d �����.", i, max);
			if (max >= k)
			{
				lifes--;
				printf(" ������ ��� ��������");
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
					printf("\nK ������ ��������� ������\n");
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
			printf("��� %d: ������� � %d �����.", i, min);
			if (min == max - 1)
			{
				min++;
				printf("\n");
				break;
			}
			if (min == k) {
				lifes--;
				printf(" ������ ��� ��������");
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

	printf("����������� ���������� ����� ��� ��������� N: %d", n / 2);
	
	return 0;
}