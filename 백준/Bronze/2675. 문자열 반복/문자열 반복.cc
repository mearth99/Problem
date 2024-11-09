#include<stdio.h>
#include<string.h>
int main(void) {
	int testcase;
	int input,length;
	char arr[20] = { 0 };
	
	scanf("%d", &testcase);
	

	
	while (testcase > 0)
	{
		scanf("%d", &input); //몇번 반복이냐
		scanf("%s", arr); // 글자를 입력받음
		length = strlen(arr); //arr의 길이 측정
		for (int a = 0; a < length; a++)
		{
			int repeat = input;
			while (repeat > 0)
			{
				printf("%c", *(arr + a));
				repeat--;
			}
		}
		testcase--;
		printf("\n");
	}
	return 0;
}