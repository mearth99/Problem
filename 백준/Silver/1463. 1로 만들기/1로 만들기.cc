#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int count = 0;
int min(int a, int b)
{
	int x;
	a > b ? x = b : x = a;
	return x;
}

int main()
{
	int input;
	int* list;

	scanf("%d", &input);
	
	list = (int*)malloc(sizeof(int) * (input+1));
	for (int i = 0; i <= input; i++)
	{
		list[i] = 0;
	}
	for (int i = 2; i <= input; i++)
	{
		list[i] = list[i-1] + 1;
		if (i % 2 == 0)
		{
			list[i] = min(list[i / 2] + 1, list[i]);
		}
		if (i % 3 == 0)
		{
			list[i] = min(list[i / 3] + 1, list[i]);
		}
	}
	printf("%d", list[input]);
	return 0;
}
