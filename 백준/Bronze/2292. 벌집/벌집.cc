#include<stdio.h>
#include<string.h>
int main()
{
	int N = 0;
	int count = 1;
	scanf("%d", &N);

	while (1)
	{
		if ((3 * count*count - 3 * count + 1) >= N)
			break;
		count++;
	}
	printf("%d", count);
	return 0;

}