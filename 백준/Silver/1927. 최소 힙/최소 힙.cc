//1927 최소힙
 /* 입력
첫째 줄에 연산의 개수 N(1 ≤ N ≤ 100,000)이 주어진다. 다음 N개의 줄에는 연산에 대한 정보를 나타내는 정수 x가 주어진다. 
만약 x가 자연수라면 배열에 x라는 값을 넣는(추가하는) 연산이고, x가 0이라면 배열에서 가장 큰 값을 출력하고 그 값을 배열에서 제거하는 경우이다.
입력되는 자연수는 2^31보다 작다.
 */

 /* 출력
입력에서 0이 주어진 회수만큼 답을 출력한다. 만약 배열이 비어 있는 경우인데 가장 작은 값을 출력하라고 한 경우에는 0을 출력하면 된다.
 */

/* 예상

*/
/* 결과

*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int heap[100001];
int heap_index=0;
int test[100001];
int test_idx=0;

void change(int *x,int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

void addheap(int x){
    int me=++heap_index; //트리의 새 노드
    heap[me] = x;
    int parent=me/2;
    int temp; //임시 보관용
    while (parent){ //root가 아니고 x가 부모보다 크면
        if(heap[me]< heap[parent]){
            change(&heap[me],&heap[parent]);
            me = parent;
            parent = me/2;
        }
        else
            break;
    }
}

int removes(){
    if(heap_index==0){
        return 0;
    }
    int temp = heap[1];
    int me=1;
    int child = 2;
    heap[1] = heap[heap_index--]; //마지막 노드가 올라온 상태, 자식들과 비교해야함
    while(child<=heap_index){
        if((child + 1<=heap_index)&&heap[child]>heap[child +1]){
            child++;
        }
        if(heap[me]>heap[child]){
          change(&heap[me],&heap[child]);
          me = child;
          child = me*2;
        }
        else{
          break;
        }
        
    }

    return temp;
}

int main()
{
    //선언 및 입력부
    int N,x;
    scanf("%d",&N);

    //heap 값 추가 및 제거(최대 힙)
    for(int i=0;i<N;i++){
        scanf("%d",&x);
        if(x!=0){
            //go add heap
            addheap(x);
        }
        else{
            //go remove heap
            test[test_idx++]=removes();
        }
    }
    for(int i=0;i<test_idx-1;i++){
        printf("%d\n",test[i]);
    }
    printf("%d",test[test_idx-1]);
    return 0;
}