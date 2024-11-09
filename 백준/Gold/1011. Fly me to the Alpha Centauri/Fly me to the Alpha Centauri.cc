#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
	int repeat,x, y,root,point,count=0;
	long long length,i=0;
	scanf("%d", &repeat);

	while (repeat)
	{
		count = i = 0;
		scanf("%d%d", &x, &y);
		length = y - x;
		root = (int)sqrt(length);
		i = root - 1;
		point = length - (root*root + root) / 2;
		while (1)
		{
			if ((i*i + i) / 2 > point)
			{
				count++;
				i--;
				break;
			}
			if ((i*i + i) / 2 == point)
				break;
			i++;
		}
		count = count + root + i;
		printf("%d\n", count);
		repeat--;
	}

	return 0;

}