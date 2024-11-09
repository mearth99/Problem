
/*
입력
첫 번째 줄에는 과수원의 크기 N이 주어진다. (1 ≤ N ≤ 300)
두 번째 줄부터 N + 1번째 줄까지, 해당 나무를 수확했을 때 얻을 수 있는 총이익을 표시한다.
총이익은 -1,000보다 크거나 같고, 1,000보다 작거나 같은 정수이다.
출력
첫 번째 줄에 최댓값을 출력한다.
*/
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
  // ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int n,result=-999999999;
  cin >> n;
  vector<vector<int>> A(n+1,vector<int>(n+1));
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++)
      cin >> A[i][j];
  }
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++)
      A[i][j] += A[i-1][j] + A[i][j-1] - A[i-1][j-1];
  }
  for(int k=1;k<=n;k++){
    for(int i=k;i<=n;i++){
      for(int j=k;j<=n;j++)
        result = max(result, A[i][j]-A[i-k][j]-A[i][j-k]+A[i-k][j-k]);
    }
  }
  cout << result;
  return 0;
}