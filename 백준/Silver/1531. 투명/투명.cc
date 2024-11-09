#include<stdio.h>
#pragma warning(disable: 4996)
int main()
{
	int N=0,M=0;
	
	int test[101][101] = { 0 };
	int count = 0;
	scanf("%d%d", &N, &M);
	
	for (int i = 0; i < N; i++)
	{
		//총 N번 실행한다.
		int start_x=0;
		int start_y = 0;
		int end_x = 0;
		int end_y = 0;

		scanf("%d%d%d%d", &start_x, &start_y, &end_x, &end_y);
		for (int a = start_x; a <= end_x; a++)
			for (int b = start_y; b <= end_y; b++)
				test[a][b]++;
	}
	for (int i = 0; i <= 100; i++)
		for (int j = 0; j <= 100; j++)
			if (test[i][j] > M)
				count++;
	printf("%d", count);

	return 0;
}