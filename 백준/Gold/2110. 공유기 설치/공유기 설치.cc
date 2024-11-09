//2110 공유기 설치
 /* 입력
첫째 줄에 집의 개수 N (2 ≤ N ≤ 200,000)과 공유기의 개수 C (2 ≤ C ≤ N)이 하나 이상의 빈 칸을 사이에 두고 주어진다.
 둘째 줄부터 N개의 줄에는 집의 좌표를 나타내는 xi (0 ≤ xi ≤ 1,000,000,000)가 한 줄에 하나씩 주어진다.
 */

 /* 출력
첫째 줄에 가장 인접한 두 공유기 사이의 최대 거리를 출력한다.
 */

/* 예상

*/
/* 결과
    
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int array[1000001];

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
  int N,M;
  int start=1,end=0,middle,output=0,count=0,temp=0;
  scanf("%d %d",&N,&M);
  for(int i=0;i<N;i++){
    scanf("%d",&array[i]);
  }
  qsort(array, N, sizeof(int), compare);
  
  end = array[N-1] - array[0];
  
  while (start <= end){
    temp = array[0];
    middle = (start + end) / 2;
    count = 1;
    for(int i=1;i<N;i++){
      int distance = array[i] - temp;
      if(middle<=distance){
        temp = array[i];
        count++;  
      }
    }
    if(count>=M){
      output = middle;
      start = middle+1;
    }
    else
      end = middle-1;
    
  }
  printf("%d",output);
  // 시작
}
