//1629 곱셈
 /* 입력
 자연수 A를 B번 곱한 수를 알고 싶다. 단 구하려는 수가 매우 커질 수 있으므로 이를 C로 나눈 나머지를 구하는 프로그램을 작성하시오.*/

 /*
첫째 줄에 A, B, C가 빈 칸을 사이에 두고 순서대로 주어진다. A, B, C는 모두 2,147,483,647 이하의 자연수이다..
 */
/*
    첫째 줄에 A를 B번 곱한 수를 C로 나눈 나머지를 출력한다.
*/
/*
    값이 long long int를 넘어서는 순간 일반적인 연산으로 계산할 수 없다. 
    A^B % C를 계산해야한다.
    A^B mod C = ( (A mod C)^B ) mod C 로 변형할 수 있기 때문에 이를 이용해 분할 정복을 시도하면 된다.
*/
#include <stdio.h>
#include <string.h>
long long int value=1;
long long int DivideConquer(int A,int B,int C);
int main()
{
    int A,B,C;
    scanf("%d%d%d",&A,&B,&C);
    printf("%lld",DivideConquer(A,B,C));
    // 시작
}
long long int DivideConquer(int A,int B,int C)
{
    if(B==1) 
        return A%C;
    value = DivideConquer(A,B/2,C);
    if(B%2==0)    
        return value*value%C;
    else
        return value*value%C*A%C;
}