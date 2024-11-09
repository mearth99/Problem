#include<stdio.h>

int main(void) 
{
	int input;
	scanf("%d", &input);
	int a = 1;
	while (a<input+1)
	{
		for (int k = 0; k < a; k++)
		{
			printf("*");
		}
		printf("\n");
		a++;
	}
	
	
	return 0;
}