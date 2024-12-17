//2630 색종이 만들기
 /* 입력
 첫째 줄에는 전체 종이의 한 변의 길이 N이 주어져 있다. N은 2, 4, 8, 16, 32, 64, 128 중 하나이다. 
 색종이의 각 가로줄의 정사각형칸들의 색이 윗줄부터 차례로 둘째 줄부터 마지막 줄까지 주어진다. 
 하얀색으로 칠해진 칸은 0, 파란색으로 칠해진 칸은 1로 주어지며, 각 숫자 사이에는 빈칸이 하나씩 있다.*/

 /*
 첫째 줄에는 잘라진 햐얀색 색종이의 개수를 출력하고, 둘째 줄에는 파란색 색종이의 개수를 출력한다.
 */
/*
    색종이들이 모여있는 개수를 구해야한다. 이를 위해서 탐색해야하는데 ,탐색과정이 정사각형으로 진행된다. 이를 수월하게 하기 위해 
    분할탐색을 해야한다. 또한, N값이 주어져 있기 때문에 탐색 합을 통해 N값과 다르다면 분리해야한다. 분리시 4조각이 나기 때문에 반복문이 필요하다.
    N값과 같다면, 하얀색인지, 파란색인지 파악해서 개수를 더해야한다.
*/
/*
    분할 정복 알고리즘을 통해서 정답을 맞췄다. 다만, 처음 알고리즘 설계시 DivideConquer(N/2,N*i/2+,N*j/2,array); 으로 대응하고자 했는데 이렇게 설계한다면
    모두 0,0에서 시작하게 되는 나쁜 점이 있었다. 이를 해결하기 위해 DivideConquer(N/2,N*i/2+row,N*j/2+col,array); 로 바꿔서 기존에 위치가 변경됨을 이용해서 해결할 수 있었다.
*/
#include <stdio.h>
#include <string.h>

int white = 0, blue = 0;
void DivideConquer(int N,int col,int row,int array[][128]);
int main()
{
    int N;
    int array[128][128];
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
    printf("%d %d",white,blue);
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
        blue++;
        return;
    }
    if(zero==N*N)
    {
        white++;
        return;
    }
    // 3. 완료 조건이 없는 경우 분할 한다. 4조각으로.
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++)
            DivideConquer(N/2,N*i/2+row,N*j/2+col,array);
    }
    return;
}