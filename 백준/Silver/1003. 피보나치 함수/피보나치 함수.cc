#include<stdio.h>
#pragma warning(disable: 4996)
int main()
{
	int N = 0, count = 0;
	int testcase = 0;
	int sum = 0;
	int fibonacci_zero[41] = { 0 };
	int fibonacci_one[41] = { 0 };
	fibonacci_zero[0] = 1;
	fibonacci_one[1] = 1;
	for (int i = 0; i <= 38; i++)
	{
		fibonacci_zero[i + 2] = fibonacci_zero[i + 1] + fibonacci_zero[i];
		fibonacci_one[i + 2] = fibonacci_one[i + 1] + fibonacci_one[i];
	}
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &testcase);
		printf("%d %d\n", fibonacci_zero[testcase],fibonacci_one[testcase]);
	}

	

	return 0;
}