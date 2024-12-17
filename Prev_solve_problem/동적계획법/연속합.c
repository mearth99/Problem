/*
#n개의 정수로 이루어진 임의의 수열이 주어진다. 우리는 이 중 연속된 몇 개의 수를 선택해서 구할 수 있는 합 중 가장 큰 합을 구하려고 한다. 
# 단, 수는 한 개 이상 선택해야 한다.
#예를 들어서 10, -4, 3, 1, 5, 6, -35, 12, 21, -1 이라는 수열이 주어졌다고 하자. 여기서 정답은 12+21인 33이 정답이 된다.
#첫째 줄에 정수 n(1 ≤ n ≤ 100,000)이 주어지고 둘째 줄에는 n개의 정수로 이루어진 수열이 주어진다. 수는 -1,000보다 크거나 같고, 1,000보다 작거나 같은 정수이다.
*/
#include <stdio.h>
int max(int a,int b)
{
    return a>b ? a : b;
}
int main()
{
    //선언부
    int list[100000]={0};
    int optial[100000]={0};
    int num,end;
    scanf("%d",&num);
    for(int i=0;i<num;i++)
    {
        scanf("%d",&list[i]);
    }
    optial[0] = list[0];
    end = list[0];
    //실행부
    /* 연속합이라는 건 하나의 숫자를 선택하고 나서는 앞으로 계속 쭉 더해야한다. 지금까지 더 한 합보다 지금 부터 시작하는 값이 크다면 다시 시작하면 된다.
    */
    for(int i=1;i<num;i++)
    {
        optial[i] = max(optial[i-1] + list[i],list[i]);
        end = max(optial[i],end);
    }
    printf("%d",end);
}