#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
	int M, N, seq = 0, min = 10000;
	scanf("%d%d", &M,&N);

	
	for(int i=M;i<=N;i++)
	{
		int jud = 0;
		if (i == 2 || i == 3)
		{
			seq += i;
			if (min > i)
				min = i;
		}
		if (i % 2 == 0 || i % 3 == 0 ||i==1) //2의 배수와 3의 배수도 소수가 아니다.
			continue;
		for (int j = 5; j < i; j++)
		{
			if (i%j == 0) //소수가 아님을 판정함.
			{
				jud = -1;
				break;
			}
		}
		//소수라면
		if (jud != -1)
		{
			seq += i;
			if (min > i)
				min = i;
		}
		
	}
	if (seq == 0)
		printf("-1");
	else
		printf("%d\n%d", seq, min);

	return 0;

}