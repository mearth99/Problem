//1920 수찾기
 /* 입력
 N개의 정수 A[1], A[2], …, A[N]이 주어져 있을 때, 이 안에 X라는 정수가 존재하는지 알아내는 프로그램을 작성하시오.
 */

 /* 출력
첫째 줄에 자연수 N(1 ≤ N ≤ 100,000)이 주어진다. 다음 줄에는 N개의 정수 A[1], A[2], …, A[N]이 주어진다. 
다음 줄에는 M(1 ≤ M ≤ 100,000)이 주어진다. 다음 줄에는 M개의 수들이 주어지는데, 이 수들이 A안에 존재하는지 알아내면 된다. 
모든 정수의 범위는 -231 보다 크거나 같고 231보다 작다.
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
