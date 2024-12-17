/*
    1931 회의실배정

    한 개의 회의실이 있는데 이를 사용하고자 하는 N개의 회의에 대하여 회의실 사용표를 만들려고 한다. 
    각 회의 I에 대해 시작시간과 끝나는 시간이 주어져 있고, 각 회의가 겹치지 않게 하면서 회의실을 사용할 수 있는 회의의 최대 개수를 찾아보자.
    단, 회의는 한번 시작하면 중간에 중단될 수 없으며 한 회의가 끝나는 것과 동시에 다음 회의가 시작될 수 있다. 
    회의의 시작시간과 끝나는 시간이 같을 수도 있다. 이 경우에는 시작하자마자 끝나는 것으로 생각하면 된다.

    첫째 줄에 회의의 수 N(1 ≤ N ≤ 100,000)이 주어진다. 
    둘째 줄부터 N+1 줄까지 각 회의의 정보가 주어지는데 이것은 공백을 사이에 두고 회의의 시작시간과 끝나는 시간이 주어진다. 
    시작 시간과 끝나는 시간은 231-1보다 작거나 같은 자연수 또는 0이다.
    첫째 줄에 최대 사용할 수 있는 회의의 최대 개수를 출력한다.
*/
/*
    우리는 사용가능한 회의의 최대 개수를 구해야한다. 무작위로 들어오는 회의 시간을 오른쪽(종료 시간)으로 정렬한다면, 
    종료 시간에 따라 언제 끝나는지 알 수 있게 된다. 
    
    이 문제는 구조체 qsort 함수를 이용하여 정렬했는데, 이를 통해 정렬한 결과, end 시간이 동일한 경우 start 시간에 대해 따로 정렬을 했었어야했다.
    start에 대해 정렬을 하지 않으므로써 그리디 알고리즘을 사용할 수 없게 되어 실패헀었지만, 이를 수정하여 성공할 수 있었다.
*/
#include <stdio.h>
#include <stdlib.h>
typedef struct st
{
    long int start;
    long int end;
}data;

    data cal[100000];
int compare(const void* a,const void * b)
{

    if(((data*)a)->end<((data*)b)->end)
        return -1;
    else if(((data*)a)->end == ((data*)b)->end)
    {
        //end가 동일할 시 start 정렬부분
        if(((data*)a)->start < ((data*)b)->start)
            return -1;        
        else if(((data*)a)->start == ((data*)b)->start)
            return 0;
        else if(((data*)a)->start > ((data*)b)->start)
            return 1;
    }
        
    else if(((data*)a)->end > ((data*)b)->end)
        return 1;
}

int main()
{
    //선언
    int N;
    long int temp,count=1; //정렬된 처음 시간은 반드시 넣기 때문에 1로 넣었다.
    //입력
    scanf("%d",&N);
    for(int i=0;i<N;i++)
        scanf("%ld %ld",&cal[i].start,&cal[i].end);
    //정렬
    qsort(cal,N,sizeof(cal[0]),compare);
    temp = cal[0].end;
    //계산(그리디) 탐욕스럽게 눈앞에 보이는 정답을 먹어간다. 종료시간과 다음 시작시간을 비교할 때 종료시간이 작다면 회의에 추가하는 식이다.
    for(int i=1;i<N;i++)
    {
        if(temp>cal[i].start)
            continue;
        else
        {
            temp = cal[i].end;
            count++;
        }
    }
    printf("%d",count);
    return 0;
}