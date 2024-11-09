#include <stdio.h>
#include <stdlib.h>


int main() {
	int base[10001] = { 0 };
	int N;
	int temp;

	scanf("%d", &N);
	
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &temp);
		base[temp]++;
	}
	for (int i = 1; i <= 10000; i++)
	{
		for (int j = 0; j < base[i]; j++)
		{
			printf("%d\n", i);
		}
	}

	return 0;
}