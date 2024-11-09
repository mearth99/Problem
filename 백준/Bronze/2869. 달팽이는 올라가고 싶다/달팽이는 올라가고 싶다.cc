#include<stdio.h>
#include<string.h>
int main()
{
	
	int A, B, V;
	scanf("%d%d%d", &A, &B, &V);
	if((V - A) % (A - B) !=0) // 나머지가 존재할 경우
		printf("%d", (V-A) / (A - B) +2);
	else
		printf("%d", (V - A) / (A - B) + 1);
	
	return 0;

}