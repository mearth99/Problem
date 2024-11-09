//1645 랜선자르기
 /* 입력
첫째 줄에는 오영식이 이미 가지고 있는 랜선의 개수 K, 그리고 필요한 랜선의 개수 N이 입력된다. 
K는 1이상 10,000이하의 정수이고, N은 1이상 1,000,000이하의 정수이다. 그리고 항상 K ≦ N 이다. 
그 후 K줄에 걸쳐 이미 가지고 있는 각 랜선의 길이가 센티미터 단위의 정수로 입력된다. 랜선의 길이는 231-1보다 작거나 같은 자연수이다.
 */

 /* 출력
첫째 줄에 N개를 만들 수 있는 랜선의 최대 길이를 센티미터 단위의 정수로 출력한다.
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
      temp += array[i]/middle;  
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
