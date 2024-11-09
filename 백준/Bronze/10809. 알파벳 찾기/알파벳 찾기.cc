#include<stdio.h>
#include<string.h>


int main()
{
	int alpa[26];
	for (int u = 0; u < 26; u++)
	{
		alpa[u] = -1;
	}

	char a[100];
	int alength;
	scanf("%s", &a);
	alength = strlen(a);
	for (int b = 0; b < alength; b++)
	{
		if (alpa[a[b] - 'a'] == -1)
		{
			alpa[a[b] - 'a'] = b;
		}
	}
	printf("%d", alpa[0]);
	for (int c = 1; c < 26; c++)
	{
		printf(" %d", alpa[c]);
	}
	return 0;
}

