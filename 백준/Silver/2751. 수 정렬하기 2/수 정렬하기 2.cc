#include <stdio.h>
#include <stdlib.h>
#include<math.h>


int compare(const void *first, const void *second)
{
	if (*(int*)first > *(int*)second)
		return 1;
	else if (*(int*)first < *(int*)second)
		return -1;
	else
		return 0;
}

int main() {
	int* base;
	int check;
	int N;

	scanf("%d", &N);
	base = (int*)malloc(sizeof(int)*N);

	for (int i = 0; i < N; i++)
		scanf("%d", &base[i]);

	qsort(base, N, sizeof(int), compare);

	for (int i = 0; i < N; i++)
	{
		if(i>0 && base[i]==base[i-1])
			continue;
		else
			printf("%d\n",base[i]);
	}

	return 0;
}