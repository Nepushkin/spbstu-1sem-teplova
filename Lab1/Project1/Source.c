#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
int main()
{
	setlocale(LC_ALL, "Russian");
	int r; // r-���-�� �����
	int n; // n-���-�� ���� � ����
	int p; // p-���-�� ��������
	int k; // k-����� ���-�� ����
	int i;
	printf("������� ���������� �����, ���������� ���� � ���� � ���������� �������� ����� ������: ");
	scanf("%d %d %d", &r, &n, &p);
	k = n * r;
	if (k < p)
	{
		printf("\n", (p - k));
	}
	for (i = 0; i < p; i++)
	{
		printf("������ %d ������� �� %d ��� �� %d �����", i + 1, i / n + 1, i % n + 1);
		if (k <= i)
		{
			printf(" �� �������������� ����");
		}
		printf("\n");
	}
	return 0;
}