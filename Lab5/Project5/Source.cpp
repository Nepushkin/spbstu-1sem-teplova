#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
using namespace std;
int main()
{
	int a;
	int b;
	int x = 0;
	int y = 0;
	int iter = 0;
	int nod = 0;
	int sumIters = 0;
	scanf("%d %d", &a, &b);

	for (a = 1; a <= b; a++)
	{
		iter = 0;
		y = b;
		x = a;
		while (x * y > 0)
		{
			if (x > y)
			{
				x = x % y;
			}
			else
			{
				y = y % x;
			}
			iter++;
		}
		nod = x > y ? x : y;
		printf("iterations : %d\n", iter);
		printf("NOD(%d; %d) = %d\n", a, b, nod);
		printf("NOK(%d; %d) = %d\n", a, b, a * b / nod);
		sumIters += iter;
	}
	printf("Avg iterations : %5.3f\n", (float)sumIters / b);

	return 0;
}