#include <stdio.h>
#include <stdlib.h>

int main() {
	//에라노스의 체를 이용하여 소수 구하기

	int n=10000, test;
	int *pnum;
	scanf("%d", &test);

	pnum = (int *)malloc(sizeof(int)*(10001)); //0~n까지 메모리 할당함.

	*(pnum + 0) = 0;
	*(pnum + 1) = 0;

	for (int i = 2; i <= n; i++)
	{
		*(pnum + i) = i;
	}

	for (int i = 2; i <= n; i++)
	{
		if (*(pnum + i) == 0)
			continue;
		if (*(pnum + i) % i == 0)
		{
			for (int j = 2; i*j <= n; j++)
			{
				*(pnum + i * j) = 0;
			}
		}

	}

	while (test)
	{
		int True=1;
		scanf("%d", &n);
		int big = n/2;
		if (*(pnum + n / 2) != 0)
		{
			printf("%d %d\n", n / 2, n / 2);
			test--;
			continue;
		}
		while (True)
		{
			for (int i = 0; i < n / 2; i++)
			{
				if (*(pnum + i) + *(pnum+big) == n)
				{
					printf("%d %d\n",i,big);
					True = 0;
				}
			}
			big++;
		}

		test--;
	}
	return 0;
}