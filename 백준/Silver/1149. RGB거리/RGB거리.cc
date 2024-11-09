#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int min(int a, int b)
{
	int x;
	a > b ? x=b : x=a;
	return x;
}

int main()
{
	int input;
	int list[1001][3] = { 0 };
	int cacu[1001][3] = { 0 };

	scanf("%d", &input);
	for (int i = 1; i <= input; i++)
		for (int j = 0; j < 3; j++)
			scanf("%d", &list[i][j]);
	for (int i = 1; i <= input; i++)
	{
		cacu[i][0] = min(cacu[i - 1][1], cacu[i - 1][2]) + list[i][0];
		cacu[i][1] = min(cacu[i - 1][0], cacu[i - 1][2]) + list[i][1];
		cacu[i][2] = min(cacu[i - 1][0], cacu[i - 1][1]) + list[i][2];
	}
	printf("%d", min(min(cacu[input][0], cacu[input][1]), min(cacu[input][1], cacu[input][2])));
	return 0;
}
