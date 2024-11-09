#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
	
	int K, N, T;
	scanf("%d", &T);
	while (T)
	{
		int apart[1000][14] = { 0 };
		for (int i = 0; i < 14; i++) //초기화
		{
			apart[0][i] = i + 1;
		}
		scanf("%d%d", &K, &N); //K는 층 N은 호 .. K층 N호에 살려면 (k-1)층 1~N까지 인원수 합이 필요함.
		for (int i = 1; i <= K; i++)
		{
			for (int j = 0; j < 14; j++)
			{
				for (int a = 0; a <= j; a++)
				{
					apart[i][j] += apart[i-1][a];
				}
			}
		}
		printf("%d\n", apart[K][N - 1]);

		T--;
	}
	
	return 0;

}