#include<stdio.h>
#include<stdlib.h>

int main()
{
	int testcase = 0;
	int n,sum=0;
	int count = 0;
	int* pa;
	double b;
	scanf("%d", &testcase);
	while (testcase > 0)
	{
		n = sum = count = 0;
		scanf("%d", &n);
		pa = (int*)malloc(sizeof(int)*n);
		for (int k = 0; k < n; k++)
		{
			scanf("%d", &pa[k]);
		}
		for (int k = 0; k < n; k++)
		{
			sum = sum + pa[k];
		}
		b = (float)sum / (float)n;
		for (int k = 0; k < n; k++)
		{
			if (pa[k] > b)
				count++;
		}
		printf("%.3lf%%\n", (float)count * 100 / (float)n);
		testcase--;
	}
	return 0;
}