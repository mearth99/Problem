#include <stdio.h>
#include <stdlib.h>
#include<string.h>

struct xy
{
	int x;
	int y;
};
int compare(const void *first,  const void *second)
{
	struct xy* A = (struct xy*)first;
	struct xy* B = (struct xy*)second;

	if (A->y < B->y)
		return -1;
	else if (A->y > B->y)
		return 1;
	else
	{
		if (A->x < B->x)
			return -1;
		else if (A->x > B->x)
			return 1;
		else
			return 0;
	}
}



int main() {
	struct xy *list;
	int N;

	scanf("%d", &N);
	list = (xy*)malloc(sizeof(xy)*N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &(list+i)->x);
		scanf("%d", &(list+i)->y);
	}
	qsort(list, N, sizeof(list[0]), compare);
	
	for (int i = 0; i < N; i++)
	{
		printf("%d ", (list + i)->x);
		printf("%d\n", (list + i)->y);
	}

	return 0;
}