/*
    18258 큐

    정수를 저장하는 큐를 구현한 다음, 입력으로 주어지는 명령을 처리하는 프로그램을 작성하시오.
    명령은 총 여섯 가지이다.
    push X: 정수 X를 큐에 넣는 연산이다.
    pop: 큐에서 가장 앞에 있는 정수를 빼고, 그 수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
    size: 큐에 들어있는 정수의 개수를 출력한다.
    empty: 큐가 비어있으면 1, 아니면 0을 출력한다.
    front: 큐의 가장 앞에 있는 정수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
    back: 큐의 가장 뒤에 있는 정수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.

    첫째 줄에 주어지는 명령의 수 N (1 ≤ N ≤ 2,000,000)이 주어진다. 둘째 줄부터 N개의 줄에는 명령이 하나씩 주어진다. 
    주어지는 정수는 1보다 크거나 같고, 100,000보다 작거나 같다. 문제에 나와있지 않은 명령이 주어지는 경우는 없다.
*/
/*
    queue 기본.
*/
#include <stdio.h>
#include <string.h>

#define maxsize 20000001

int queue[maxsize];
int front = -1;
int back = -1;

void push(int queue[],int temp)
{
    if((back+1)%maxsize == front)
    {
        printf("full");
        return;
    } 
    queue[++back % maxsize] = temp;
}
int pop(int queue[])
{
    if(front == back)
        return -1;
    return queue[++front%maxsize];
}
int size()
{
    return back - front;
}
int empty()
{
    return back == front ? 1 : 0;
}
int first()
{
    if(front == back)
        return -1;
    return queue[front+1];
}
int least()
{
    if(front == back)
        return -1;
    return queue[back];
}

int main()
{
    char str[10];
    int N;
    scanf("%d",&N);
    for(int i=0;i<N;i++)
    {
        scanf("%s",str);
        if(strcmp(str,"push")==0)
        {
            int temp;
            scanf("%d",&temp);
            push(queue,temp);
        }
        else if(strcmp(str,"pop")==0)
        {
            printf("%d\n",pop(queue));
        }
        else if(strcmp(str,"size")==0)
        {
            printf("%d\n",size());
        }
        else if(strcmp(str,"empty")==0)
        {
            printf("%d\n",empty());
        }
        else if(strcmp(str,"front")==0)
        {
            printf("%d\n",first());
        }
        else if(strcmp(str,"back")==0)
        {

            printf("%d\n",least());
        }
    }
    return 0;
}