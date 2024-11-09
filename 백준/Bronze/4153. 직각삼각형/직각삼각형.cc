#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
	int x, y, l;
	while (1)
	{
		scanf("%d%d%d", &x, &y, &l);
		if (x == 0 && y == 0 && l == 0)
			break;
		if (x*x + y * y == l * l || y * y + l * l == x * x || x * x + l * l == y * y)
			printf("right\n");
		else
			printf("wrong\n");

	}

	return 0;

}