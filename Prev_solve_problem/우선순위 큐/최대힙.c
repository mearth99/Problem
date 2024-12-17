//11279 최대 힙
 /* 입력
첫째 줄에 연산의 개수 N(1 ≤ N ≤ 100,000)이 주어진다. 다음 N개의 줄에는 연산에 대한 정보를 나타내는 정수 x가 주어진다. 
만약 x가 자연수라면 배열에 x라는 값을 넣는(추가하는) 연산이고, x가 0이라면 배열에서 가장 큰 값을 출력하고 그 값을 배열에서 제거하는 경우이다.
입력되는 자연수는 2^31보다 작다.
 */

 /* 출력
입력에서 0이 주어진 회수만큼 답을 출력한다. 만약 배열이 비어 있는 경우인데 가장 큰 값을 출력하라고 한 경우에는 0을 출력하면 된다.
 */

/* 예상
최대 힙을 만들자. 최대 힙은, 배열을 토대로, 배열에서 계속 자식을 추가한다. 자식은 배열의 가장 마지막에 추가되며 이후 자식의 값에 따라 제 위치로 교환된다.
최대 힙의 삭제는 Root를 의미하며, 배열의 가장 오른쪽(leaf 자식)과 교체한 후 삭제하며 교체한 자식은 제 위치로 교환한다.
*/
/* 결과

*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int heap[100001];
int heap_index=0;
void addheap(int x){
    int i=++heap_index; //트리의 새 노드
    int temp; //임시 보관용
    while ((i!=1)&&(x>heap[i/2])) //root가 아니고 x가 부모보다 크면
        i/=2;
    temp = heap[i];
    heap[i] = x;
    heap[heap_index] = temp;
}

int removes(){
    if(heap_index==0){
        return 0;
    }
    int temp = heap[1];
    int i=1;
    heap[1] = heap[heap_index--]; //마지막 노드가 올라온 상태, 자식들과 비교해야함
    while((i<heap_index)&&(heap[i]<heap[i*2]||heap[i]<heap[i*2+1])){
        if(heap[i*2]<heap[i*2+1]){
            int change = heap[i];
            heap[i] = heap[i*2+1];
            heap[i*2+1] = change;
        }
        else{
            int change = heap[i];
            heap[i] = heap[i*2];
            heap[i*2] = change;
        }
        i*=2;
    }

    return temp;
}

int main()
{
    //선언 및 입력부
    int N,x;
    int test[100]={0};
    int test_idx=0;
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
    printf("\n");
    for(int i=0;i<test_idx;i++){
        printf("%d",test[i]);

    }
    return 0;
}
