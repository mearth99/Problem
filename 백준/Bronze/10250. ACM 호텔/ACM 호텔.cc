#include<stdio.h>
#include<string.h>
int main()
{
	
	int H, W, N,T;
	scanf("%d", &T);
	while (T)
	{
		scanf("%d%d%d", &H, &W, &N);
		if(N%H==0)
			if(N/H<10)
				printf("%d0%d\n", H, N / H);
			else 
				printf("%d%d\n", H, N / H );
		else
			if (N / H+1 < 10)
				printf("%d0%d\n", N%H, N / H +1);
			else
				printf("%d%d\n", N%H, N / H +1);
		T--;
	}
	
	return 0;

}