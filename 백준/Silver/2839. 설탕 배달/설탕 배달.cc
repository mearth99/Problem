#include<stdio.h>
#include<string.h>
int main()
{
	int N;
	scanf("%d", &N);
	if (N == 4 || N == 7)
	{
		printf("-1");
		return 0;
	}
	if (N % 5 != 0 && N % 3 != 0 && (N - 3) % 5 != 0 && (N - 6) % 5 != 0 && (N - 9) % 5 != 0 && (N - 12) % 5 != 0)
		printf("-1");
	else
		if (N % 5 == 0)
			printf("%d", N / 5);
		else if ((N - 3) % 5 == 0)
			printf("%d", (N - 3) / 5 + 1);
		else if ((N - 6) % 5 == 0)
			printf("%d", (N - 6) / 5 + 2);
		else if ((N - 9) % 5 == 0)
			printf("%d", (N - 9) / 5 + 3);
		else if ((N - 12) % 5 == 0)
			printf("%d", (N - 12) / 5 + 4);
		else
			printf("%d", N / 3);

	return 0;

}