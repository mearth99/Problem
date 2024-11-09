#include<stdio.h>
#include<string.h>

int main()
{
	int temp = 0, jud = 0;
	int temp_add = 0;
	int length = 0;
	char list[1000000] = { 0 };
	int alpa[26] = { 0 }; 
	
	scanf("%s", list);
	length = strlen(list);
	for (int i = 0; i < length; i++)
	{
		if (list[i] < 91)
			alpa[list[i] - 'A']++; 
		else 
			alpa[list[i] - 'a']++;
		
	}
	for (int i = 0; i < 26; i++)
	{
		if (temp<alpa[i]) 
		{
			temp = alpa[i];
			temp_add = i;
		}
		else if (temp == alpa[i])
		{
			temp_add = -1;
		}
	}
	if (temp_add == -1)
	{
		printf("?");
	}
	else
	{
		printf("%c", 'A'+temp_add);
	}
	return 0;
}