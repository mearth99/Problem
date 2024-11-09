#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int count = 0;
int max(int a, int b)
{
	int x;
	a > b ? x = a, count = 1 : x = b, count = 2;
	return x;
}

int main()
{
	int input;
	int list[301] = { 0 };
	int D[301] = { 0 };

	scanf("%d", &input);
	
	for (int i = 1; i <= input; i++)
			scanf("%d", &list[i]);
	for (int i = 1; i <= input; i++)
	{
		if (count < 2)
		{
			D[i] = D[i - 1] + list[i];
			count++;
		}
		else
		{
			D[i] = max(list[i] + D[i - 2],list[i]+list[i-1]+D[i-3]);
			
		}
	}
	printf("%d", D[input]);
	return 0;
}
