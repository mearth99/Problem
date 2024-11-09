#include<stdio.h>

/*
int fibo(int a)
{
	if (a == 1)
	{
		return 1;
	}

	if (a == 0) 
	{
		return 0;
	}
	return fibo(a - 1) + fibo(a - 2);
}*/

int main(void) 
{
	
	int n, Fn1 = 1, Fn = 1;
	int tmp;
	scanf("%d", &n);

	for (int k = 2; k <= n-1; k++)
	{
		tmp = Fn;
		Fn = Fn + Fn1;
		Fn1 = tmp;
	}
	printf("%d", Fn);
	return 0;
}