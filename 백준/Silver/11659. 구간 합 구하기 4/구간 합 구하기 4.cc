/*
    구간합 구하기
    수 N개가 주어졌을 때, i번째 수부터 j번째 수까지 합을 구하는 프로그램을 작성하시오.
    첫째 줄에 수의 개수 N과 합을 구해야 하는 횟수 M이 주어진다. 둘째 줄에는 N개의 수가 주어진다. 
    수는 1,000보다 작거나 같은 자연수이다. 셋째 줄부터 M개의 줄에는 합을 구해야 하는 구간 i와 j가 주어진다.
    총 M개의 줄에 입력으로 주어진 i번째 수부터 j번째 수까지 합을 출력한다.
*/
/*
    첫번째 줄: 구간 총 개수, 두번째 줄: 구간 값들, 3번쨰부터 이후 M번 : 구간 합 구하기 (i번째부터 j번쨰까지)
*/
#include <stdio.h>

int main()
{
    //선언
    int N,M,output;
    int range[100001];
    int sum[100001];
    //입력
    scanf("%d%d",&N,&M);
    range[0] = sum[0] =0;
    for(int i=1;i<=N;i++)
    {
        scanf("%d",&range[i]);
        sum[i] = sum[i-1] + range[i];
    }
    //계산
    for(int k=0;k<M;k++)
    {
        int i,j;
        scanf("%d%d",&i,&j);
        output = sum[j] - sum[i-1];
        printf("%d\n",output);
    }
    return 0;
}