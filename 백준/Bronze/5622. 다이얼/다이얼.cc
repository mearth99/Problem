#include<stdio.h>
#include<string.h>

int main()
{
	char alpa[16];
	int length,sum=0;
	scanf("%s", alpa);
	length = strlen(alpa); //NULL 제외.
	for (int i = 0; i < length; i++)
	{
		if (alpa[i] - 'A' < 3)
			sum = sum + 2;
		else if (alpa[i] - 'A' < 6)
			sum = sum + 3;
		else if (alpa[i] - 'A' < 9)
			sum = sum + 4;
		else if (alpa[i] - 'A' < 12)
			sum = sum + 5;
		else if (alpa[i] - 'A' < 15)
			sum = sum + 6;
		else if (alpa[i] - 'A' < 19)
			sum = sum + 7;
		else if (alpa[i] - 'A' < 22)
			sum = sum + 8;
		else if (alpa[i] - 'A' < 26)
			sum = sum + 9;
	}
	sum = sum + length;
	printf("%d", sum);
	return 0;
}