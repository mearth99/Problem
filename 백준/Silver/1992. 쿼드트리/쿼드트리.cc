//1992 쿼드트리
 /* 입력
첫째 줄에는 영상의 크기를 나타내는 숫자 N 이 주어진다. N 은 언제나 2의 제곱수로 주어지며, 1 ≤ N ≤ 64의 범위를 가진다. 
두 번째 줄부터는 길이 N의 문자열이 N개 들어온다. 각 문자열은 0 또는 1의 숫자로 이루어져 있으며, 영상의 각 점들을 나타낸다..*/

 /*
영상을 압축한 결과를 출력한다.
 */
/*
   영상을 압축하기 위해 탐색을 해야한다. 새로운 함수가 불리면 ( 가 종료되면 )가 더해지는 형식으로 출력하면 되겠다. 
*/
/*
    
*/
#include <stdio.h>
#include <string.h>

void DivideConquer(int N,int col,int row,int array[][128]);
int main()
{
    int N;
    int array[128][128];
    char buffer[65];
    scanf("%d",&N);
    for(int i=0;i<N;i++)
    {
        scanf("%s",buffer);
        for(int j=0;j<N;j++)
        {
            array[i][j] = buffer[j]-'0';
        }
    }
    // 시작
    DivideConquer(N,0,0,array);
}
void DivideConquer(int N,int row,int col,int array[][128])
{
    // 1. 탐색을 진행한다.
    int zero=0,one=0;
    // N이 4 
    // i=4(0) i<4 
    for(int i=row;i<row+N;i++)
    {
        for(int j=col;j<col+N;j++)
        {
            array[i][j]==1 ? one++ : zero++;
        }
    }
    // 2. 조건을 검토한다.
    if(one==N*N)
    {
        printf("1");
        return;
    }
    if(zero==N*N)
    {
        printf("0");
        return;
    }
    // 3. 완료 조건이 없는 경우 분할 한다. 4조각으로.
    printf("(");
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++)
            DivideConquer(N/2,N*i/2+row,N*j/2+col,array);
    }
    printf(")");
    return;
}