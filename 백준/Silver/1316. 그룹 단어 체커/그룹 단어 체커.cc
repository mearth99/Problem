#include<stdio.h>
#include<string.h>
int main()
{
	int count,length,result;
	char string[101];
	
	result = 0;

	scanf("%d", &count);
	while (count)
	{
		char alpa[26] = { 0 };
		scanf("%s", string);
		length = strlen(string);

		for (int i = 0; i<length; i++)
		{
			if (alpa[string[i] - 'a'] == 0)
			{
				alpa[string[i] - 'a']++;
				if (string[i + 1] - 'a' == string[i] - 'a')
					while (string[i + 1] == string[i])
						i++;
			}
			else
			{
				result--;
				break;
			}
		}
		result++;
		count--;
	}
	printf("%d", result);
	return 0;
}