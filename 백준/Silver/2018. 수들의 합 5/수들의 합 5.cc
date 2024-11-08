#include<stdio.h>
#pragma warning(disable: 4996)
int main()
{
	int N = 0, count = 0;
	int sum = 0;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
	{
		for (int j = i; sum < N; j++)
		{
			sum += j;
			if (sum == N)
				count++;
		}
		sum = 0;
	}

	printf("%d", count);

	return 0;
}