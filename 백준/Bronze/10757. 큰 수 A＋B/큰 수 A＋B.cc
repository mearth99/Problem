#include<stdio.h>
#include<string.h>
int main()
{
	int length_A, length_B,  temp = 0;
	char A[10002] = { 0 };
	char B[10002] = { 0 };
	scanf("%s%s", &A, &B);

	length_A = strlen(A);
	length_B = strlen(B);
	if (length_A > length_B)
	{
		for (int i = length_A - 1; i >= 0; i--)
		{
			if (i - (length_A - length_B) >= 0) //메모리 침범 오류 방지
			{
				if (A[i] + B[i - (length_A - length_B)] - 2 * '0' + temp < 10) //자리수의 합산이 10을 넘지 않으면
				{
					A[i] = A[i] + B[i - (length_A - length_B)] - '0' + temp;
					temp = 0;
				}
				else //자리수의 합산이 10을 넘은 경우
				{
					A[i] = (A[i] + B[i - (length_A - length_B)] - 2 * '0' + temp) % 10 + '0';
					temp = 1;
				}
			}
			else //B를 전부 더함 A와 temp값만 연산 ex A: 1999  temp : +1
			{
				if (A[i] - '0' + temp < 10) //자리수의 합산이 10을 넘지 않으면
				{
					A[i] = A[i] + temp;
					temp = 0;
				}
				else //자리수의 합산이 10을 넘은 경우
				{
					A[i] = (A[i] -'0' + temp) % 10 + '0';
					temp = 1;
				}
			}
		}
	}
	else if (length_A == length_B)
	{
		for (int i = length_A - 1; i >= 0; i--)
		{
			if (A[i] == '\n' || B[i] == '\n' || A[i] == NULL || B[i] == NULL)
			{
				temp = 0;
				continue;
			}
			if (A[i] + B[i] - 2 * '0' + temp < 10) //자리수의 합산이 10을 넘지 않으면
			{
				A[i] = A[i] + B[i] - '0' + temp;
				temp = 0;
			}
			else //자리수의 합산이 10을 넘은 경우
			{
				A[i] = (A[i] + B[i] - 2 * '0' + temp) % 10 + '0';
				temp = 1;
			}
		}
	}
	else
	{

		for (int i = length_B - 1; i >= 0; i--)
		{
			if (i - (length_B - length_A) >= 0) //메모리 침범 오류 방지
			{
				if (A[i - (length_B - length_A)] + B[i] - 2 * '0' + temp < 10) //자리수의 합산이 10을 넘지 않으면
				{
					B[i] = A[i - (length_B - length_A)] + B[i] - '0' + temp;
					temp = 0;
				}
				else //자리수의 합산이 10을 넘은 경우
				{
					B[i] = (A[i - (length_B - length_A)] + B[i] - 2 * '0' + temp) % 10 + '0';
					temp = 1;
				}
			}
			else
			{
				if (B[i] - '0' + temp < 10) //자리수의 합산이 10을 넘지 않으면
				{
					B[i] = B[i] + temp;
					temp = 0;
				}
				else //자리수의 합산이 10을 넘은 경우
				{
					B[i] = (B[i] - '0' + temp) % 10 + '0';
					temp = 1;
				}
			}

		}
	}
	if (length_A < length_B)
		if(temp)
			printf("%d%s",temp, B);
		else
			printf("%s", B);
	else
		if (temp)
			printf("%d%s", temp, A);
		else
			printf("%s", A);
	return 0;

}