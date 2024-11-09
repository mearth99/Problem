#include <stdio.h>
#include <stdlib.h>
#include<string.h>

struct borad
{
	int row;
	int column;
};
void backtracking(int sudoqu[9][9], int index, int checkindex,borad checkpoint[],int TF) //checkindex:max-index
{
   //가로,세로,3*3에 이미 있는 숫자를 제외한 숫자를 골라 back_tracking를 실행한다.
	//index을 조정하여 backtracking을 실행한다.
	
	if (TF == 1)
		return;
	int row = checkpoint[index].row;
	int colum = checkpoint[index].column;
	int list[10];
	for (int i = 0; i < 10; i++)
		list[i] = 0;
	for (int i = 0; i < 9; i++) //가로/세로 숫자 테스트
	{
		list[sudoqu[row][i]]++; //가로
		list[sudoqu[i][colum]]++; //세로
	}
	for (int i = (row / 3)*3; i < ((row / 3)+1) * 3; i++) //3*3 숫자 테스트
	{
		for (int j = (colum / 3)*3; j < ((colum / 3)+1) * 3; j++)
		{
			i = i;
			list[sudoqu[i][j]]++;
		}
	}
	//이 단계를 지나면 list[1]~list[9]에 값이 있는데, 값이 0이라면 그 index를 테스트 해야한다.


	for (int i = 1; i < 10; i++)
	{
		if (TF == 1)
			break;
		
		if (list[i] == 0) //sudoqu에 이 값을 넣고 다음 checkpoint로 이동한다. 재귀함수를 실행한다.
		{
			
			sudoqu[row][colum] = i;
			if (index == checkindex - 1) // 조건을 전부 만족한 경우다. 이 경우 stack에 쌓여있는 재귀를 다 종료해야한다.
			{
				TF = 1;
				for (int i = 0; i < 8; i++)
				{
					for (int j = 0; j < 9; j++)
					{
						printf("%d ", sudoqu[i][j]);
					}
					printf("\n");
				}
				for (int j = 0; j < 8; j++)
				{
					printf("%d ", sudoqu[8][j]);
				}
				printf("%d", sudoqu[8][8]);
			}
			backtracking(sudoqu, index + 1, checkindex, checkpoint, TF);
			if (TF == 1)
				break;
			sudoqu[row][colum] = 0;
		}
	}
	
}


int main()
{
	borad checkpoint[100] = { 0 }; //checkpoint의 특성상, 왼쪽-오른쪽 이후 아래로 이동하면서 0의 위치를 저장한다.
	int checkindex = 0;
	int sudoqu[9][9] = { 0 };
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			scanf("%d", &sudoqu[i][j]);
		}
	}
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (sudoqu[i][j] == 0)
			{
				checkindex = checkindex;
				checkpoint[checkindex].row = i;
				checkpoint[checkindex].column = j;
				checkindex++;
			}
		}
	}
	
	backtracking(sudoqu, 0, checkindex,checkpoint,0);

	return 0;
}
