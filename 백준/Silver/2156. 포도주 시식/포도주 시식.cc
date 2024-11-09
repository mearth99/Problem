#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int count = 0;
int max(int a, int b)
{
	int x;
	a > b ? x = a,count=1 : x = b,count=2;
	return x;
}
int max2(int a, int b)
{
	int x;
	a > b ? x = a: x = b, count = 0;
	return x;
}

int main()
{
	int input;
	int* list,*D;
	
	scanf("%d", &input);
	
	list = (int*)malloc(sizeof(int) * (input+1));
	D = (int*)malloc(sizeof(int) * (input+1));
	D[0] = 0;
	for (int i = 1; i <= input; i++)
	{
		scanf("%d", &list[i]);
		D[i] = 0;
	}
	D[1] = list[1];
	D[2] = list[1] + list[2];
	for (int i = 3; i<= input; i++)
	{
		
		D[i] = max2(max(D[i - 2] + list[i],D[i - 3] + list[i] + list[i - 1]),D[i-1]);
		
		
	}
	printf("%d", D[input]);

	return 0;
}
