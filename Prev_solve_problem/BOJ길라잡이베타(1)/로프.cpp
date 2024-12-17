//2217 로프

/* 문제

 */
/* 입력
첫째 줄에 정수 N이 주어진다. 다음 N개의 줄에는 각 로프가 버틸 수 있는 최대 중량이 주어진다. 이 값은 10,000을 넘지 않는 자연수이다.
*/
/* 출력
첫째 줄에 답을 출력한다.
*/
/* 예상
K개의 로프를 사용하여 W인 중량을 들어올릴 때,   W/K만큼의 중량이 걸리게 된다. 이때, 각 로프를 이용하여 물체를 들 수 있는 최대 중량을 구해야한다.
예를 들어 1, 30, 50, 10 으로 로프가 들어온다고 하자. 최댓값을 기준으로, 50을 선택하면 하중은 50이되고, 50과 30을 선택한다면 40까지 가능하다.
즉, 최댓값으로 정렬하고, 차례대로 값을 받으면서 물체의 최대 중량을 구하면 된다. 이 중 최대 중량을 선택하면 된다.
*/
/* 결과
결과는 항상 정수로 나온다는 것만 생각했어도! 처음에 소숫점이 있을까걱정하여 해멨는데
잘 생각해보니 내림차순으로 정렬하고, 현재 값 * 분담한 갯수 = 분담 가능한 최대 중량이 되기 때문에
내림차순을 탐색하면서 모든 분담 가능한 최대 중량을 구해서 쉽게 계산하였다. 굿!  
*/


#include <iostream>
#include <cstdlib>
#include <limits.h>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int arr[100001] = {0};

bool desc(int a, int b){ 
  return a > b; 
} 

int main()
{
  int N,output = 0;
  cin >> N;
  for(int i=0;i<N;i++){
    cin >> arr[i];
  }
  sort(arr,arr+N,desc);
  for(int i=0;i<=N;i++){
    output = max(output,arr[i]*(i+1)); 
  }
  cout << output;
}