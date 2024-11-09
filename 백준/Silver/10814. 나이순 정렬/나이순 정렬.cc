#include <stdio.h>
#include <stdlib.h>
#include<string.h>


struct xy
{
	int x;
	char y[101] = { 0 };
	int sequence;
};
int compare(const void *first,  const void *second)
{
	struct xy* A = (struct xy*)first;
	struct xy* B = (struct xy*)second;

	
	if (A->x < B->x)
		return -1;
	else if (A->x > B->x)
		return 1;
	else
	{
		if (A->sequence < B->sequence)
			return -1;
		else if (A->sequence > B->sequence)
			return 1;
		else
			return 0;
	}
	
}
int main() {
	struct xy *list;
	int N, age[201] = { 0 };
	
	scanf("%d", &N);
	list = (xy*)malloc(sizeof(xy)*N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &(list+i)->x);
		scanf("%s", &(list+i)->y);
		list[i].sequence = age[list[i].x];
		age[list[i].x]++;
	}
	qsort(list, N, sizeof(list[0]), compare);
	
	for (int i = 0; i < N; i++)
	{
		printf("%d ", (list + i)->x);
		printf("%s\n", (list + i)->y);
	}

	return 0;
}