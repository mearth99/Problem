#include<stdio.h>
#include<string.h>

int main()
{
	int number, num;
	scanf("%d%d", &number, &num);

	number = (number / 100) + (number % 10) * 100 + (number / 10) % 10 * 10;
	num = (num / 100) + (num % 10) * 100 + (num / 10) % 10 * 10;
	if (number > num)
		printf("%d", number);
	else
		printf("%d", num);
	return 0;
}