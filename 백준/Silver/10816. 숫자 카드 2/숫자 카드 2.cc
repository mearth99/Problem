//10816 숫자카드 2
 /* 입력
첫째 줄에 상근이가 가지고 있는 숫자 카드의 개수 N(1 ≤ N ≤ 500,000)이 주어진다. 둘째 줄에는 숫자 카드에 적혀있는 정수가 주어진다.
숫자 카드에 적혀있는 수는 -10,000,000보다 크거나 같고, 10,000,000보다 작거나 같다.
셋째 줄에는 M(1 ≤ M ≤ 500,000)이 주어진다. 넷째 줄에는 상근이가 몇 개 가지고 있는 숫자 카드인지 구해야 할 M개의 정수가 주어지며,
 이 수는 공백으로 구분되어져 있다. 이 수도 -10,000,000보다 크거나 같고, 10,000,000보다 작거나 같다.
 */

 /* 출력
첫째 줄에 입력으로 주어진 M개의 수에 대해서, 각 수가 적힌 숫자 카드를 상근이가 몇 개 가지고 있는지를 공백으로 구분해 출력한다.
 */

/* 예상

*/
/* 결과
    
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int array[500001];

int static compare (const void* first, const void* second)
{
    if (*(int*)first > *(int*)second)
        return 1;
    else if (*(int*)first < *(int*)second)
        return -1;
    else
        return 0;
}
int search(int middle,int end,int temp){
  int count = 0;
  for(int i=middle-1;i>=0&&array[i]==temp;i--){
    count++;
  }
  for(int i=middle;i<=end&&array[i]==temp;i++){
    count++;
  }
  return count;
}
int main()
{
    int N,M,temp;
    int start,end,middle,output;
    scanf("%d",&N);
    for(int i=0;i<N;i++)
    {
      scanf("%d",&array[i]);
    }
    scanf("%d",&M);
    qsort(array, N, sizeof(int), compare);
    for(int i=0;i<M;i++)
    {
      scanf("%d",&temp);
      start=0;
      end=N-1;
      output=0;
      while (start < end) { 
        int middle = (start + end) / 2;
        if (array[middle]>=temp) 
          end = middle;
        else
          start = middle+1;
      }
      output = end;
      start=0;
      end=N-1;
      while (start < end) { 
        int middle = (start + end) / 2;
        if (array[middle]>temp) 
          end = middle;
        else
          start = middle+1;
      }
      if(array[end]==temp)
        end++;
      output = end - output;
      printf("%d ",output);
    }
    // 시작
}
