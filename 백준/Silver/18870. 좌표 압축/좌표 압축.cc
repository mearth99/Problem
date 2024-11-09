#include <stdio.h>
#include <stdlib.h>
#include<string.h>

struct locate
{
	int cost;
	int index;
};
int compare(const void *first, const void *second)
{
	struct locate* A = (struct locate*)first;
	struct locate* B = (struct locate*)second;

	if (A->cost <= B->cost)
		return -1;
	else if (A->cost > B->cost)
		return 1;
}


int main()
{
	int input;
	int *end_list;
	locate *list;
	int cost = 0;
	scanf("%d", &input); //input값을 저장함 N값이 됨.
	
	list = (locate*)malloc(input * sizeof(locate)); //N값만큼 동적할당이 이루어짐
	end_list = (int*)malloc(input * sizeof(int));

	for (int i = 0; i < input; i++) //배열에다가 값을 저장할 것임.
	{
		scanf("%d", &list[i].cost);
		list[i].index = i;
	}
	qsort(list, input, sizeof(list[0]), compare); //nlogn으로 오름차순정렬됨
	end_list[list[0].index] = cost;
	for (int i = 1; i < input; i++)
	{
		if (list[i].cost == list[i - 1].cost)
		{
			end_list[list[i].index] = cost;
		}
		else
		{
			cost++;
			end_list[list[i].index] = cost;
		}
	}
	printf("%d", end_list[0]);
	for (int i = 1; i < input; i++)
	{
		printf(" %d", end_list[i]);
	}
}
