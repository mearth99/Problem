#include<stdio.h>


int main()
{
	int a,b,c;

	scanf("%d%d%d", &a,&b,&c);
	if (a >= b && c >= a)
	{
		printf("%d", a);
		return 0;
	}
	if (a >= c && b >= a)
	{
		printf("%d", a);
		return 0;
	}
	if (b >= a && c >= b)
	{
		printf("%d", b);
		return 0;
	}
	if (a >= b && b >= c)
	{
		printf("%d", b);
		return 0;
	}
	if (a >= c && c >= b)
	{
		printf("%d", c);
		return 0;
	}
	if (c >= a && b >= c)
	{
		printf("%d", c);
		return 0;
	}
	return 0;
}