#include<stdio.h>
#include<stdlib.h>

int main()
{
	int num,jud;
	int count=0;
	scanf("%d", &num);
	jud = num;
	while (1)
	{
		if (num >= 10)
		{
			
			num = (num % 10) * 10 + (num / 10 + num % 10)%10;
		
		}
		else
		{
			num = num * 11;

			
		}
		if (num == jud)
		{
			count++;
			break;
		}
		count++;
	}
	printf("%d", count);
	
	return 0;
}