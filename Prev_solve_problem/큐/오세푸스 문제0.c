/*
    11866 오세푸스 문제0

    요세푸스 문제는 다음과 같다.
    1번부터 N번까지 N명의 사람이 원을 이루면서 앉아있고, 양의 정수 K(≤ N)가 주어진다. 
    이제 순서대로 K번째 사람을 제거한다. 한 사람이 제거되면 남은 사람들로 이루어진 원을 따라 이 과정을 계속해 나간다. 
    이 과정은 N명의 사람이 모두 제거될 때까지 계속된다. 원에서 사람들이 제거되는 순서를 (N, K)-요세푸스 순열이라고 한다.
     예를 들어 (7, 3)-요세푸스 순열은 <3, 6, 2, 7, 5, 1, 4>이다.
    N과 K가 주어지면 (N, K)-요세푸스 순열을 구하는 프로그램을 작성하시오.
/*
    큐를 구현하지 않고 배열을 통해 해결했다. count로 K번 탐색했는지 횟수를 파악하는데, 이미 탐색했던 곳은 횟수로 치지 않았다.
    따라서 count로 K번 탐색한 경우 그 배열을 출력하게 했다. N번 출력한 경우 종료시켰다.
*/
#include <stdio.h>
#include <string.h>

int main()
{
    int que[1001]={0};
    int N,K,index=0,count=0,end=0;
    scanf("%d%d",&N,&K);
    printf("<");
    while(end!=N)
    {
        if(index>N)
                index = index%N;
        if(que[index]==0 && count==K)
        {
            que[index] = 1;
            if(end!=N-1)
                printf("%d, ",index);
            else
                printf("%d>",index);
            count = 1;
            end++;
        }
        else if(que[index]==0)
            count++;
        index++;
    }
    return 0;
}