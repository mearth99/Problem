#include<stdio.h>
#include<string.h>

int main()
{
	char alpa[101];
	int sum = 0;
	int length = 0;
	scanf("%s", alpa);

	length = strlen(alpa);
	for (int i = 0; i < length; i++)
	{
		if ((alpa[i] == 'c' || alpa[i] == 's') && alpa[i + 1] == '=')
			sum--;
		else if ((alpa[i] == 'c' || alpa[i] == 'd') && alpa[i + 1] == '-')
			sum--;
		else if ((alpa[i] == 'l' || alpa[i] == 'n') && alpa[i + 1] == 'j')
			sum--;
		if ((alpa[i - 1] == 'd' && alpa[i] == 'z' && alpa[i + 1] == '='))
			sum = sum - 2;
		else if (alpa[i] == 'z' && alpa[i + 1] == '=')
			sum--;
		sum++;
	}
	printf("%d", sum);
	
	return 0;
}