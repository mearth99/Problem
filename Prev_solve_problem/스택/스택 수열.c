/*
    1874 스택수열

    스택 (stack)은 기본적인 자료구조 중 하나로, 컴퓨터 프로그램을 작성할 때 자주 이용되는 개념이다. 
    스택은 자료를 넣는 (push) 입구와 자료를 뽑는 (pop) 입구가 같아 제일 나중에 들어간 자료가 제일 먼저 나오는 (LIFO, Last in First out) 특성을 가지고 있다.
    1부터 n까지의 수를 스택에 넣었다가 뽑아 늘어놓음으로써, 하나의 수열을 만들 수 있다. 
    이때, 스택에 push하는 순서는 반드시 오름차순을 지키도록 한다고 하자. 
    임의의 수열이 주어졌을 때 스택을 이용해 그 수열을 만들 수 있는지 없는지, 있다면 어떤 순서로 push와 pop 연산을 수행해야 하는지를 알아낼 수 있다. 
    이를 계산하는 프로그램을 작성하라.
*/
/*
    작을때, 같을때, 클때 3가지로 분리하여 코드를 만들었다. 유일한 값으로 존재하는 수이기에, 한번 엇갈려가면 추가로 엇갈릴 수 가 없다. 그래서
    저 조건들을 만족하지 않으면 else로 바로 NO가 된다.
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
    //선언
    int N,index=0,top=-1;
    int seq[100001];
    int stack[100001];
    char pr[200001];
    int num=1,pr_index=0;
    //입력
    scanf("%d",&N);

    //실행
    for(int i=0;i<N;i++)
        scanf("%d",&seq[i]);
    
    while(1)
    {
        if(index==-1 || stack[top]<seq[index])
        {
            stack[++top] = num++;
            pr[pr_index++] = '+';
        }
        else if(stack[top--]==seq[index])
        {
            pr[pr_index++] = '-';
            index++;
        }
        else
        {
            printf("NO");
            return 0;
        }
        if(pr_index==N*2) 
            break;
    }
    for(int i=0;i<pr_index;i++)
        printf("%c\n",pr[i]);
    return 0;
}