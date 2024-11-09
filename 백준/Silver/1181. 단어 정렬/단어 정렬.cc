#include <stdio.h>
#include <stdlib.h>
#include<string.h>



int compare(const void *first, const void *second)
{
	char *A = *(char**)first;
	char *B = *(char**)second;

	int a = strlen(A);
	int b = strlen(B);

	if (a < b)
		return -1;
	else if (a > b)
		return 1;
	else
	{
		if (strcmp(A, B) >0)
			return 1;
		else if (strcmp(A, B) < 0)
			return -1;
		else
			return 0;
	}
	
}
int main() {
	char **list;
	int N;
	
	scanf("%d", &N);
	list = (char**)malloc(sizeof(char*)*N);
	for (int i = 0; i < N; i++)
	{
		*(list + i) = (char*)malloc(sizeof(char) * 51);
	}
	for (int i = 0; i < N; i++)
	{
		scanf("%s", *(list+i));
	}
	qsort(list, N, sizeof(list[0]), compare);
	
	printf("%s", *(list + 0));
	for (int i = 1; i < N; i++)
	{
		if (strcmp(*(list + i - 1), *(list + i)) == 0)
			continue;
		printf("\n%s", *(list + i));
	}

	return 0;
}
