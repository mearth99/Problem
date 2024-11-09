//12015 가장 긴 증가하는 부분 수열 2
 /* 입력
첫째 줄에 수열 A의 크기 N (1 ≤ N ≤ 1,000,000)이 주어진다.

둘째 줄에는 수열 A를 이루고 있는 Ai가 주어진다. (1 ≤ Ai ≤ 1,000,000)
 */

 /* 출력
첫째 줄에 수열 A의 가장 긴 증가하는 부분 수열의 길이를 출력한다.
 */

/* 예상
수열의 가장 긴 증가하는 부분 수열의 길이를 출력하는 문제다. 동적계획법으로 푸는 방법은 알고 있으나, 이는 N^2의 수행이 걸리기 때문에, 사용하지 못했다.
NlogN으로 푸는 알고리즘을 참고하여 해결할 수 있었다.
*/
/* 결과
동적계획법으로 이 문제를 풀 수 있던 이유는, A[i]보다 작은 A[j] 중에 가장 큰 D[j]를 찾기 위함이였다. 그래서 이중 For을 사용하여 모든 [J]를 비교하여 가장 큰 Max를 비교했었다.
그런데, 모든 [J]를 비교하지 않고 이분 탐색을 사용하여 이 문제를 적용할 수 있었다. 이분탐색이 가진 특징은
Lower, Upper bound가 존재한다는 것이다. 따라서, 특정 D[j]를 가지는 값 중, Lower (같거나, 큰 값이 가장 처음 나오는 값)을 찾아 변경함으로써 문제를 해결할 수 있다는 것이다.

왜 Lower가 필요한지 예시를 통해 탐구해보자. 10, 15 , 40 , 20 이 존재하면, 경우의 수는 다음과 같다. 10 15 40 / 10 15,20 만일 다음 값이 왔을 때 더 긴 수열이 될 가능성은 어느 쪽일까?
오른쪽이다. 그래서 마지막 수가 작을 수 록 유리하고 이는 Lower의 특징을 가지고 있다. 따라서 들어오는 값을 계속 비교해 따로 배열을 마련해주면 가장 긴 부분 수열의 길이를 구할 수 있다.

**** 그러나 주의할 점은, 가장 긴 부분 수열의 길이를 구할 수 있을 뿐 새롭게 배열을 만들기 때문에 기존 수열 값을 추적하긴 어렵다는 것이다. (새로운 배열은 순서를 무시함!)
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
long long int A[1000001];
long long int D[1000001];

long long int lower_change(int key, int start, int end){
  int mid;
  while(start < end){
    mid = (start + end) / 2;
    if(D[mid]<key)
      start = mid +1;
    else
      end = mid;
  }
  return end;
}

int main()
{
  // 선언 및 입력부
  long long int N,D_index=0;
  scanf("%d",&N);
  for(int i=0;i<N;i++)
  {
    scanf("%lld",&A[i]);
  }
  D[0]=A[0];
  for(int i=0;i<N;i++)
  {
    if(A[i]>D[D_index]){
      D[++D_index] = A[i];
    }
    else{
      long long int index = lower_change(A[i],0,D_index);
      D[index] = A[i];  
    }
  }
  printf("%lld",D_index+1);
  return 0;
}
