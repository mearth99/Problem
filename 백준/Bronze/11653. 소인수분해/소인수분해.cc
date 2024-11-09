#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
	int N;
	scanf("%d", &N);

	//숫자가 가장 많은 2,3 점검
	while (N % 2 == 0)
	{
		N = N / 2;
		printf("%d\n", 2);
	}
	while (N % 3 == 0)
	{
		N = N / 3;
		printf("%d\n", 3);
	}
	for (int i = 2; i <= N; i++)
	{
		if (N%i == 0) //나누어떨어지면 
		{
			printf("%d\n", i);
			N = N / i;
			i = 2;
		}
	}
	return 0;

}