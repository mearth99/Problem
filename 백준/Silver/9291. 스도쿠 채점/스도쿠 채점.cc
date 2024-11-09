#include<stdio.h>
#include<string.h>
#include<stdlib.h>



int main()
{
	int count = 0;
	int textcase = 0;
	int sudoqo[9][9] = { 0 };
	int dalti[9] = { 0 };
	scanf("%d", &count);
	for(textcase;textcase<count;textcase++)
	{
		int i, j = 0;
		int jud = 0;
		for (i=0; i < 9; i++) //값 입력
		{
			for (j=0; j < 9; j++)
			{
				scanf("%d", &sudoqo[i][j]);
			}
		}

		for (i=0; i < 9; i++) //값 분석
		{
			
			for (j=0; j < 9; j++) //열의 합 분석
			{
				dalti[sudoqo[i][j] - 1] += 1;
			}
			for (int u = 0; u < 9; u++)
			{
				if (dalti[u] > 1)
				{
					jud = -1;
					break;
				}
			}
			for (int u = 0; u < 9; u++)
			{
				dalti[u] = 0;
			}
		}
		for (j=0; j < 9; j++) 
		{
			for (i=0; i < 9; i++) //행의 합 분석
			{
				dalti[sudoqo[i][j] - 1] += 1;
			}
			for (int u = 0; u < 9; u++)
			{
				if (dalti[u] > 1)
				{
					jud = -1;
					break;
				}
			}
			for (int u = 0; u < 9; u++)
			{
				dalti[u] = 0;
			}
		}
		for (int a = 0; a <= 6; a = a + 3)
		{
			for (int n = 0; n <= 6; n = n + 3)
			{
				
				for (i = a; i < a+3; i++)
				{
					for (j = n; j <n+3; j++)
						dalti[sudoqo[i][j] - 1] += 1;
				}
				for (int u = 0; u < 9; u++)
				{
					if (dalti[u] > 1)
					{
						jud = -1;
						break;
					}
				}
				for (int u = 0; u < 9; u++)
				{
					dalti[u] = 0;
				}
			}
		}
		if(jud==-1)
			printf("Case %d: INCORRECT\n", textcase+1);
		else
			printf("Case %d: CORRECT\n", textcase+1);
	}
	return 0;
}


