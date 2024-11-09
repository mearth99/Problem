#include<stdio.h>

int main() {
	long long int a, b, tmp,c,d;
	long long int result;
	

		scanf("%lld %lld", &a, &b);
		c = a;
		d = b;
		while (b != 0)
		{

			tmp = b;
			b = a % b;
			a = tmp;
		}
		result = d * c / a;
		printf("%lld",result);
		
}