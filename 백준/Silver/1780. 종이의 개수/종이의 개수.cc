//1780 종이의 개수
 /* 입력
첫째 줄에 N(1 ≤ N ≤ 37, N은 3k 꼴)이 주어진다. 다음 N개의 줄에는 N개의 정수로 행렬이 주어진다.
*/
 /*
첫째 줄에 -1로만 채워진 종이의 개수를, 둘째 줄에 0으로만 채워진 종이의 개수를, 셋째 줄에 1로만 채워진 종이의 개수를 출력한다.
 */
/*
   9개로 자르고, -1 0 1을 구하면 된다.
*/
/*
    전 문제를 풀었다면 쉬운 문제. 다만, 문자열 입력을 생각했어야 했다.
*/
#include <stdio.h>
#include <string.h>

int minus = 0, zero = 0, plus=0;
int array[2188][2188];
void DivideConquer(int N,int col,int row,int array[][2188]);
int main()
{
    int N;
    
    scanf("%d",&N);
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            scanf("%d",&array[i][j]);
        }
    }
    // 시작
    DivideConquer(N,0,0,array);
    printf("%d\n%d\n%d",minus,zero,plus);
}
void DivideConquer(int N,int row,int col,int array[][2188])
{
    // 1. 탐색을 진행한다.
    int _minus=0,_zero=0,_plus=0;
    for(int i=row;i<row+N;i++)
    {
        for(int j=col;j<col+N;j++)
        {
            if(array[i][j]==-1)
                _minus++;
            else if (array[i][j]==0)
                _zero++;
            else if(array[i][j]==1)
                _plus++;
        }
    }
    // 2. 조건을 검토한다.
    if(_minus==N*N)
    {
        minus++;
        return;
    }
    
    if(_zero==N*N)
    {
        zero++;
        return;
    }
    if(_plus==N*N)
    {
        plus++;
        return;
    }
    // 3. 완료 조건이 없는 경우 분할 한다. 4조각으로.
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
            DivideConquer(N/3,N*i/3+row,N*j/3+col,array);
    }
    return;
}