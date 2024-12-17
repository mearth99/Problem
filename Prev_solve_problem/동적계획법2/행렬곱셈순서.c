//11049 행렬곱셈순서
 /* 입력
첫째 줄에 행렬의 개수 N(1 ≤ N ≤ 500)이 주어진다.
둘째 줄부터 N개 줄에는 행렬의 크기 r과 c가 주어진다. (1 ≤ r, c ≤ 500)
항상 순서대로 곱셈을 할 수 있는 크기만 입력으로 주어진다.
 */

 /* 출력
첫째 줄에 입력으로 주어진 행렬을 곱하는데 필요한 곱셈 연산의 최솟값을 출력한다. 정답은 231-1 보다 작거나 같은 자연수이다. 또한, 최악의 순서로 연산해도 연산 횟수가 231-1보다 작거나 같다.
 */

/* 예상
곱셈 연산의 최솟값을 출력해야하는 문제다. 순서에 따라 행렬 곱셈 연산의 수가 달라지기 때문에 모든 값을 찾아봐야한다. 순서 대로 곱셈이 가능하지만, 분배법칙에 의거해 잘 곱하면 연산이 적어진다.
DP를 설계하기 어려워 구조체로도 생각해보고 있다. 구조체로 A[i][0] A[i][1]를 구조체 A[i]로 변경하면 구조가 Easy해 보이기도 한다. 
정의를 먼저 찾아야 DP문제를 풀기 쉬워진다. ABC -> (AB) * C로 볼 수 있는 것 처럼 DP[i][j]는 i~J까지의 곱 연산 횟수의 최소값 이다.
DP[i][i] = 0, DP[i][i+1] = A[i][0]* A[i][1] * A[i+1][1]가 된다.
DP[i][j] = min(DP[i][j],DP[i][k]+DP[k+1][j]+sum) 
*/
/* 결과
파일합치기와 매우 유사한 문제다. 자꾸 DP sum에서 착각해서 틀리는게 아쉽다. 몇번 더 해보면 눈에 들어올 것 같은데...!

*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define min(a,b) (a>b ? b:a)
#define max 2147483647
int A[501][2],DP[501][501];

void Recursion(int start, int end){

  for(int K=start;K<end;K++){
    int sum=A[start][0]*A[K][1]*A[end][1];
    DP[start][end] = min(DP[start][end],DP[start][K]+DP[K+1][end]+sum);
  }
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
  int T;
  scanf("%d",&T);

  //함수 시작
  for(int U=1;U<=T;U++)
    scanf("%d %d",&A[U][0],&A[U][1]);

    File_Combine(T);
    printf("%d\n",DP[1][T]);
  
  return 0;
}
