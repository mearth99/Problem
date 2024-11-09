#include<stdio.h>
#include<string.h>
int main()
{
	int count, input,seq=0;

	scanf("%d", &count);

	while (count)
	{
		scanf("%d", &input);
		if (input == 1)
		{
			count--;
			continue;
		}
		if (input == 2 || input == 3)
		{
			seq++;
			count--;
			continue;
		}
		if (input % 2 == 0 || input % 3 == 0)
		{
			count--;
			continue;
		}
		for (int i = 5; i < input; i=i+2)
		{
			if (input%i == 0)
			{
				seq--;
				break;
			}
		}
		seq++;
		count--;
	}
	printf("%d", seq);

	return 0;

}