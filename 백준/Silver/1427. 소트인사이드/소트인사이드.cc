#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int main() {
	char str[10] = { 0 };
	int number[10] = { 0 };
	scanf("%s", &str);
	
	int length = strlen(str);
	for (int i = 0; i < length; i++)
	{
		number[str[i] - '0']++;
	}
	for (int i = 9; i >= 0; i--)
	{
		for (int j = 0; j < number[i]; j++)
		{
			printf("%d", i);
		}
	}

	return 0;
}