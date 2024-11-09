//1182 부분수열의 합

/* 문제
첫째 줄에 정수의 개수를 나타내는 N과 정수 S가 주어진다. (1 ≤ N ≤ 20, |S| ≤ 1,000,000) 둘째 줄에 N개의 정수가 빈 칸을 사이에 두고 주어진다. 주어지는 정수의 절댓값은 100,000을 넘지 않는다.
 */
/* 입력
*/
/* 출력
첫째 줄에 합이 S가 되는 부분수열의 개수를 출력한다.
*/
/* 예상
시간제한은 2초(약 2억번) n=20개고, 선택하거나 선택하지 않는 방법의 수 = 2^20 = 1048576 이므로 충분히 하나하나 계산해도 된다.
재귀적인 방법으로 값이 커지는지 안커지는지 비교하면 될 것 같다. (for문을 돌리며)
*/
/* 결과
*/
#include <iostream>
#include <cstdlib>
#include <limits.h>
#include <vector>
using namespace std;

int val = 0;
int lists[21]={0};

// 1, 2, 3, 4, 5  
void checks(int N,int S, int sum, int idx){
  if(idx==N)
    return;
  if(S==(sum+lists[idx])){
    val++;
  }
    checks(N,S,sum,idx+1);
    checks(N,S,sum+lists[idx],idx+1);
}

int main()
{  
  int N,S;
  cin >> N >> S;
  for(int i=0;i<N;i++){
    cin >> lists[i];
  }
  checks(N,S,0,0);
  cout << val;
}
