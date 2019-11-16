#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<locale.h>

int main()
{
	setlocale(LC_ALL, "Russian");
	int n, k, min, max, delta, i, lifes;
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
	printf("K = %d\n", min);
	//������ ������ ���������
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
		printf("������� � %d �����.", start);
		//start += i;
		if (start >= k)
		{
			printf("������ ��� �������� �� %d �����.\n", start);
			lifes--;
			min = start - i;
			for (min; min < start; min++)
			{
				printf("������� � %d �����.", min);
				if (min == k)
				{
					printf("������ ��� �������� �� %d �����.\n", min);
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