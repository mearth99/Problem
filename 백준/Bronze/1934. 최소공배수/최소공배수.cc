#include<stdio.h>

int main() {
	int a, b, tmp,c,d;
	int tc;
	scanf("%d", &tc);
	while (tc > 0)
	{

		scanf("%d %d", &a, &b);
		c = a;
		d = b;
		while (b != 0)
		{

			tmp = b;
			b = a % b;
			a = tmp;
		}
		printf("%d\n",(d*c / a));
		tc--;
	}
}