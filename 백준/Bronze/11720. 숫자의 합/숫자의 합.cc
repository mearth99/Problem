#include<stdio.h>
#include<string.h>

int main()
{
	int count;
	int sum = 0;
	char temp[100] = { 0 };

	scanf("%d", &count);
	scanf("%s", temp);
	for (int i = 0; i < count; i++)
	{
		sum += temp[i] - '0';
		
	}
	printf("%d", sum);

	return 0;
}