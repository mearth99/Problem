#include <stdio.h>

struct body
{
	int cm;
	int kg;
	int rank;
};

int main() {

	struct body A[50] = { 0 };
	int input;
	scanf("%d", &input);
	for (int i = 0; i < input; i++)
	{
		scanf("%d%d", &A[i].kg, &A[i].cm);
		A[i].rank = 1;
	}
	for (int i = 0; i < input; i++)
	{
		for (int j = 0; j < input; j++)
		{
			if (i == j)
				continue;
			if (A[i].cm < A[j].cm && A[i].kg < A[j].kg) // 자기보다 큰 덩치의 수를 센다!
			{
				A[i].rank++;
			}
		}
	}

	
	for (int i = 0; i < input-1; i++)
		printf("%d ", A[i].rank);
	printf("%d ", A[input-1].rank);

	return 0;
}