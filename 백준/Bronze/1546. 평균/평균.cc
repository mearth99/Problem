#include<stdio.h>
#include<stdlib.h>

int main()
{
	int n,max=-1,sum=0;
	int* pa;
	double b;
	scanf("%d", &n);
	pa = (int*)malloc(sizeof(int)*n);
	for (int k = 0; k < n; k++)
	{
		scanf("%d", &pa[k]);
	}
	for (int k = 0; k < n; k++)
	{
		sum = sum + pa[k];
		if (pa[k] > max)
		{
			max = pa[k]; //max 값 찾기.
		}
	}
	b=(((double)(sum * 100 )/(double)(max*n)));

	printf("%lf", b);
	return 0;
}