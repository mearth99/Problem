#include <stdio.h>
#include <stdlib.h>
#include<string.h>


int min=1000000001, max=-1000000001; //최종 출력

void backtracking(int list[], int operate[], int index,int end)
{
	if (index == end-1)
	{
		if (list[end-1] > max)
			max = list[end-1];
		if (list[end-1] < min)
			min = list[end-1];
		return;
	}
	//index의 위치에 따라 계산한다. 즉 index가 새로운 i가 되며, index+1==11이면 더이상 backtracking을 실행하지 않는다.
	for (int i = 0; i < 4; i++)
	{
		int temp = list[index + 1];
		if (operate[i] == 0) //0이면 생략
			continue;
		else
		{
			if (i == 0)
			{
				operate[i]--;
				list[index + 1] = list[index] + list[index + 1];
				backtracking(list, operate, index + 1,end);
				list[index + 1] = temp;
				operate[i]++;
			}
			else if (i == 1)
			{
				operate[i]--;
				list[index + 1] = list[index] - list[index + 1];
				backtracking(list, operate, index + 1,end);
				list[index + 1] = temp;
				operate[i]++;
			}
			else if (i == 2)
			{
				operate[i]--;
				list[index + 1] = list[index] * list[index + 1];
				backtracking(list, operate, index + 1,end);
				list[index + 1] = temp;
				operate[i]++;
			}
			else if (i == 3)
			{
				int check = 0;
				if (list[index + 1] < 0 &&list[index]>0)
				{
					check = 1;
					list[index + 1] *= -1;
				}
				if (list[index] < 0 && list[index+1]>0)
				{
					check = 1;
					list[index] *= -1;
				}
				operate[i]--;
				list[index + 1] = list[index] / list[index + 1];
				if (check == 1)
					list[index + 1] *= -1;
				backtracking(list, operate, index + 1,end);
				list[index + 1] = temp;
				operate[i]++;
			}
		}

	}
}

int main()
{
	int list[11] = { 0 };
	int operate[4]; //0:덧셈 1:뺄셈 2:곱셈 3:나눗셈

	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &list[i]);
	}
	for (int i = 0; i < 4; i++)
	{
		scanf("%d", &operate[i]);
	}

	backtracking(list, operate, 0,N);

	printf("%d\n%d", max, min);

	return 0;
}
