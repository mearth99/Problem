#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int global_gap = 9999;

void check(int** list, int* choice, int index, int end, int sum)
{

}

void backtracking(int** list, int* choice, int index, int end,int sum)
{
	if (index > end)
		return;
	if(sum==end/2)
	{

		int link = 0, start = 0, gap = 0;
		for (int i = 0; i < end; i++)
		{
			if (*(choice + i) == 0) //link 팀이면 0과 묶는다.
			{
				for (int j = 0; j < end; j++)
				{
					if (*(choice + j) == 0)
					{
						link += list[i][j];
					}
				}
			}
			if (*(choice + i) == 1) //start 팀이면 1과 묶는다.
			{
				for (int j = 0; j < end; j++)
				{
					if (*(choice + j) == 1)
					{
						start += list[i][j];
					}
				}
			}
		}
		if (link >= start)
		{
			gap = link - start;
		}
		else
		{
			gap = start - link;
		}


		if (global_gap >= gap)
		{
			global_gap = gap;
		}
		return;
	}

	//take number
	for (int i = 1; i >=0; i--)
	{
		*(choice + index) = i; //start:1 link:0
		sum +=i;
		backtracking(list, choice, index + 1, end,sum);
		*(choice + index) = 0;
		sum-=i;
		
	}

	


}

int main()
{
	// 입력부분
	int N;
	int** list;
	int* choice;

	scanf("%d", &N);

	list = (int**)malloc(sizeof(int*) * N);
	choice = (int*)malloc(sizeof(int) * N);
	for (int i = 0; i < N; i++)
	{
		*(list + i) = (int*)malloc(sizeof(int) * N);
		*(choice + i) = 0;
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			scanf("%d", &list[i][j]);
		}
	}
	// 입력부분 종료

	backtracking(list, choice, 0, N,0);

	//backtracking을 어떻게 설계할 것인가?

	printf("%d", global_gap);
	return 0;
}
