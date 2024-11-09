#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int max(int a, int b)
{
	int x;
	a > b ? x=a : x=b;
	return x;
}

int main()
{
	int input,m=0;
	int list[501][501] = { 0 };
	int D[501][501] = { 0 };

	scanf("%d", &input);
	
	for (int i = 1; i <= input; i++)
		for (int j = 1; j <= i; j++)
			scanf("%d", &list[i][j]);
	for (int i = 1; i <= input; i++)
		for (int j = 1; j <= i; j++)
		{
			D[i][j] = max(D[i - 1][j],D[i-1][j-1]) + list[i][j];
		}

	for (int i = 1; i <= input; i++)
	{
		if (m < D[input][i])
			m = D[input][i];
	}
	printf("%d", m);
	return 0;
}
