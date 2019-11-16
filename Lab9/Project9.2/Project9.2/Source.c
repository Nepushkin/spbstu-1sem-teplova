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
	int start = 1, end = 0, sum = 0;
	int steps = 0;
	lifes = 2;
	for (i = 0; sum < n; i++)
	{
		sum += i;
		printf("sum = %d, i = %d\n", sum, i);
	}
	i--;
	sum -= i;
	end = n - sum;
	i--;
	printf("sum = %d, i = %d\n", sum, i);
	for (steps = 1; i > 0 && lifes > 0 && start != end; i--, steps++)
	{
		if (lifes == 2 && end < k)
		{
			printf("%d ���. ������� ������ ��� � %d �����.\n", steps, end);
			start = end + 1;
			end += i;
		}
		else if (lifes == 2 && end >= k)
		{
			printf("%d ���. ������ ��� �������� �� %d �����.\n", steps, end);
			lifes--;
			end--;
		}
		else if (lifes == 1 && start < k)
		{
			printf("%d ���. ������� ������ ��� � %d �����.\n", steps, start);
			start++;
		}
		else if (lifes == 1 && start >= k)
		{
			printf("%d ���. ������ ��� �������� �� %d �����.\n", steps, start);
			lifes--;
		}
	}
	printf("������������ %d �����\n", steps);
	if (lifes == 2) {
		printf("K = %d\n", end);
	}
	else
	{
		printf("K = %d\n", start);

	}
	//���������� ��������� ��� (20; 14)
	//������, ��� k ����� ���� > n

	return 0;
}