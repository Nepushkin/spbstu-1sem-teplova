#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<locale.h>
#include<math.h>

int main()
{
	setlocale(LC_ALL, "Russian");
	int n, k;
	printf("������� ���������� ������ � ������: ");
	scanf("%d", &n);
	printf("������� ����������� ����: ");
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
			printf("%d ���. ������� ������ ��� � %2d �����. ��� �� ��������.\n", steps, end);
			start = end + 1;
			end += i;
		}
		else if (lifes == 2 && end >= k)
		{
			printf("%d ���. ������� ������ ��� � %2d �����. ������ ��� ��������.\n", steps, end);
			lifes--;
			if (start == 0)
			{
				start = 1;
				end--;
			}
		}
		else if (lifes == 1 && start < k)
		{
			printf("%d ���. ������� ������ ��� � %2d �����. ��� �� ��������.\n", steps, start);
			start++;
		}
		else if (lifes == 1 && start >= k)
		{
			printf("%d ���. ������� ������ ��� � %2d �����. ������ ��� ��������.\n", steps, start);
			lifes--;
		}
	}
	printf("��������������� ����� ����� = %d\n", steps - 1);
	printf("������������ ����� ����� = %d\n", maxsteps);
	if (lifes == 2)
	{
		printf("����������� ����, �� ������� ��� ���������� ������ ������ ������\n");
	}
	else
	{
		printf("����������� ����, �� ������� ��� ���������� = %d\n", start);
	}

	return 0;
}