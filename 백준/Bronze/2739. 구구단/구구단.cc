#include <stdio.h>

//Convert Fahrenheit to Celsius
int main() {

	int N, a = 1;
	scanf("%d", &N);
	for (a; a <=9; a++)
	{
		printf("%d * %d = %d\n", N, a, N*a);
	}


	return 0;
}