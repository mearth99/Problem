//2805 나무자르기
 /* 입력
첫째 줄에 나무의 수 N과 상근이가 집으로 가져가려고 하는 나무의 길이 M이 주어진다. (1 ≤ N ≤ 1,000,000, 1 ≤ M ≤ 2,000,000,000)
둘째 줄에는 나무의 높이가 주어진다. 나무의 높이의 합은 항상 M보다 크거나 같기 때문에, 상근이는 집에 필요한 나무를 항상 가져갈 수 있다. 
높이는 1,000,000,000보다 작거나 같은 양의 정수 또는 0이다.
 */

 /* 출력
적어도 M미터의 나무를 집에 가져가기 위해서 절단기에 설정할 수 있는 높이의 최댓값을 출력한다.
 */

/* 예상

*/
/* 결과
    
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int array[1000001];

int main()
{
  int N,M;
  long long int start=1,end=0,middle,output=0,temp=0;
  scanf("%d %d",&N,&M);
  for(int i=0;i<N;i++){
    scanf("%d",&array[i]);
    end = array[i]>end ? array[i] : end;
  }
  while (start <= end) {
    temp=0;
    middle = (start + end) / 2;
    for(int i=0;i<N;i++){
      if(array[i]>middle)
        temp += array[i]-middle;  
    }
    if(temp>=M){
      start = middle+1;
      if(middle>output)
        output = middle;
    }
    else
      end = middle-1;
    
  }
  printf("%lld",output);
  // 시작
}
