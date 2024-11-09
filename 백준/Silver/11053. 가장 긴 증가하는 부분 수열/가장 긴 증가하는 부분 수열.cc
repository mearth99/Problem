#include <stdio.h>
#include <stdlib.h>
#include<string.h>


int max(int a, int b)
{
	int x;
	a > b ? x = a : x = b;
	return x;
}

int main()
{
	int input;
	int* list,*D;
	
	scanf("%d", &input);
	
	list = (int*)malloc(sizeof(int) * (input+1));
	D = (int*)malloc(sizeof(int) * (input+1));

	for (int i = 0; i < input; i++)
	{
		scanf("%d", &list[i]);
	}
	
	for (int i = 0; i<input; i++)
	{
		D[i] = 1;
		for (int j = 0; j < input; j++)
		{
			if (list[i] > list[j] && D[i] < (D[j] + 1))
				D[i] = D[j] + 1;
		}
	}
	int maxa = -1;
	for (int i = 0; i < input; i++)
	{
		maxa = max(D[i], maxa);
	}
	printf("%d", maxa);

	return 0;
}
