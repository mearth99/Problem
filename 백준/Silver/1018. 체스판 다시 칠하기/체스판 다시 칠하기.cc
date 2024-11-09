#include <stdio.h>

int main() {
	char chess[50][50] = { 0 };
	char one_check[2] = { 'W','B' };
	char two_check[2] = { 'B','W' };
	int N, M,re=0,re2=0,min=999;
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			scanf("%c", &chess[i][j]);
			if (chess[i][j] == '\n')
				j--;
		}
	}
	for (int i = 0; i < N - 7; i++)
	{
		for (int j = 0; j < M - 7; j++)
		{
		
			for (int u = i; u < i + 8; u++)
			{
				if (u % 2 == 0) //짝수번째 줄(0번째도 짝수로 취급)
				{
					for (int w = j; w < j + 8; w++)
					{
						if (chess[u][w] != one_check[w % 2])
							re++;
					}
				}
				else //홀수번째 줄
				{
					for (int w = j; w < j + 8; w++)
					{
						if (chess[u][w] != two_check[w % 2])
							re++;
					}
				}
			}
			for (int u = i; u < i + 8; u++)
			{
				if (u % 2 == 0) //짝수번째 줄(0번째도 짝수로 취급)
				{
					for (int w = j; w < j + 8; w++)
					{
						if (chess[u][w] != two_check[w % 2])
							re2++;
					}
				}
				else //홀수번째 줄
				{
					for (int w = j; w < j + 8; w++)
					{
						if (chess[u][w] != one_check[w % 2])
							re2++;
					}
				}
			}
			
			if (re < min)
				min = re;
			if (re2 < min)
				min = re2;
			re = 0;
			re2 = 0;
		}
	}
	printf("%d", min);

	return 0;
}