#include<stdio.h>
#include<string.h>
int main()
{
	int N = 0;
	int count = 1;
	scanf("%d", &N);
	
	while (1)
	{
		if ((count*(count + 1) / 2) >= N) //몇번쨰?
			break;
		count++;
	}

	if (count % 2 == 0) //짝수번째 -분자가 커짐
	{
		printf("%d/%d", (N - (count*(count - 1) / 2)),count + 1 - (N - (count*(count - 1) / 2)));
	}
	else				//홀수번째 -분모가 커짐
	{
		printf("%d/%d", count + 1 - (N - (count*(count - 1) / 2)), (N - (count*(count - 1) / 2)));
	}


	return 0;

}