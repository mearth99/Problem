#include<stdio.h>
#include<stdlib.h>

int main()
{
	int n,u;
	int* pa;
	scanf("%d%d", &n,&u);
	pa = (int*)malloc(sizeof(int)*n);
	for (int k = 0; k < n; k++)
	{
		scanf("%d", &pa[k]);
	}
	for (int k = 0; k < n; k++)
	{
		if (pa[k] < u)
		{
			printf("%d ", pa[k]);
		}
	}
	return 0;
}