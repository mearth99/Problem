//11066번 파일 합치기
 /* 입력
프로그램은 표준 입력에서 입력 데이터를 받는다. 프로그램의 입력은 T개의 테스트 데이터로 이루어져 있는데, 
T는 입력의 맨 첫 줄에 주어진다.각 테스트 데이터는 두 개의 행으로 주어지는데, 첫 행에는 소설을 구성하는 장의 수를 나타내는 양의 정수 K (3 ≤ K ≤ 500)가 주어진다.
 두 번째 행에는 1장부터 K장까지 수록한 파일의 크기를 나타내는 양의 정수 K개가 주어진다. 파일의 크기는 10,000을 초과하지 않는다.
 */

 /* 출력
프로그램은 표준 출력에 출력한다. 각 테스트 데이터마다 정확히 한 행에 출력하는데, 모든 장을 합치는데 필요한 최소비용을 출력한다.
 */

/* 예상
동적계획법 표를 만들어서 모든 경우의 수를 탐색해봐야한다. 최소비용은 결과를 보면 될 것같은데 수식을 어떻게 만들어볼까.
먼저 수식에 대한 정의부터 시작하자. 정답을 보고 수식을 작성하여 좀 아쉽다. DP[i][j]는 A[i][j]사이의 최소비용이라고 생각해보자. 그러면 다음과 같은 식이 나온다.
DP[i][i] = A[i], DP[i][i+1] = A[i][i]+A[i+1];
DP[i][j] 는 경우가 다른데, 파일합치기의 경우, 결국 선택한 것과 선택하지 않은 것을 골라야 하는데, 이때 [i][k]와 [k+1][j]의 합으로 생각할 수 있다.
DP[i][j]는 결국 이전 DP의 합을 의미할 탠대 그러면 i ~ j 중에 선택해야하고 i~k 중에 선택한 것과, k+1~j 사이에 선택한 합의 최소비용이기 때문이다.
DP[i][i] = A[i]
DP[i][j] = min(DP[i][k]+DP[k+1][j]+sum[i][j])
*/
/* 결과
동적계획법에서 많은 어려움을 겪었는데 그걸 탈출하고도 많은 어려움을 겪었다. 정의를 세우긴 세웠는데, 제대로 된 설계를 하지 못해서 아쉽다. 동적계획법은 계속 연습해봐야겠다.

*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define min(a,b) (a>b ? b:a)
#define max 100010000
int A[501],DP[501][501];

void Recursion(int start, int end){
  int sum=0;
  for(int i=start;i<=end;i++){
    sum+=A[i];
  }
  for(int K=start;K<end;K++)
    DP[start][end] = min(DP[start][end],DP[start][K]+DP[K+1][end]+sum);
}

void File_Combine(int length){
  for(int gap=1;gap<length;gap++){
    for(int i=1;i+gap<=length;i++){
      int j=i+gap;
      DP[i][j]=max;
      Recursion(i,j);
    }
  }
  return;
}

int main()
{
  // 선언 및 입력부
  int T,K;
  scanf("%d",&T);

  //함수 시작
  for(int U=0;U<T;U++){
    scanf("%d",&K);
    for(int R=1;R<=K;R++){
      scanf("%d",&A[R]);
    }
    File_Combine(K);
    printf("%d\n",DP[1][K]);
  }
  
  return 0;
}
