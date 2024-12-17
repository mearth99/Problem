//1654 랜선자르기
 /* 입력
 첫째 줄에는 오영식이 이미 가지고 있는 랜선의 개수 K, 그리고 필요한 랜선의 개수 N이 입력된다. 
 K는 1이상 10,000이하의 정수이고, N은 1이상 1,000,000이하의 정수이다. 그리고 항상 K ≦ N 이다. 
 그 후 K줄에 걸쳐 이미 가지고 있는 각 랜선의 길이가 센티미터 단위의 정수로 입력된다. 랜선의 길이는 231-1보다 작거나 같은 자연수이다.
 */

 /* 출력
첫째 줄에 N개를 만들 수 있는 랜선의 최대 길이를 센티미터 단위의 정수로 출력한다.
 */

/* 예상
퀵정렬을 이용해 정렬해서 이분탐색하면 될 것 같다. X라는 정수가 존재하는지 찾기 위해서 전체 크기의 가운데 값을 끄집어낸다.
가운데 값이 X라는 정수보다 크다면, 첫번째와 가운데를 사이로 다시 가운데 값을 찾아 반복한다.
만일, 가운데 값이 X라는 정수 보다 작다면 가운데에서 끝값을 사이로 다시 가운데 값을 찾아 반복한다.
*/
/* 결과
    
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int array[100001];

int static compare (const void* first, const void* second)
{
    if (*(int*)first > *(int*)second)
        return 1;
    else if (*(int*)first < *(int*)second)
        return -1;
    else
        return 0;
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
      end=N;
      output=0;
      while (start < end) { 
        int middle = (start + end) / 2;
        if (array[middle]<temp) 
          start = middle+1;
        else if(array[middle]>temp)
          end = middle-1;
        else{
          output=1;
          break;
        }
      }
      printf("%d\n",output);
    }
    // 시작
}
