#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int main()
{
	int input;
	long list[101][11] = { 0 };
	
	scanf("%d", &input);
	
	for (int i = 1; i <= 9; i++)
	{
		list[1][i] = 1;
	}

	for (int i = 2; i <= input; i++)
	{
		list[i][0] = list[i - 1][1];
		for (int j = 1; j <= 9; j++)
			list[i][j] = (list[i - 1][j - 1] + list[i - 1][j + 1]) % 1000000000;
	}
	long sum = 0;
	for (int i = 0; i < 10; i++)
		sum += list[input][i];

	printf("%ld", sum%1000000000);
	return 0;
}
