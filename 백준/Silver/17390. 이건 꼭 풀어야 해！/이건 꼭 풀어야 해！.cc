
/*
입력
첫 번째 줄에 수열 A의 길이 N과 질문의 개수 Q가 공백으로 구분되어 주어진다. (1 ≤ N, Q ≤ 300,000)
두 번째 줄에 N개의 정수 A1, A2, ..., AN 이 공백으로 구분되어 주어진다. Ai 는 수열 A의 i 번째 수이다. (1 ≤ Ai ≤ 1,000)
세번째 줄부터 Q개의 줄에 걸쳐 욱제의 질문을 의미하는 두 수 L, R이 공백으로 구분되어 주어진다. (1 ≤ L ≤ R ≤ N)
주어지는 모든 입력은 자연수이다.

출력
Q개의 줄에 걸쳐, 질문의 답을 순서대로 각각 출력한다.
*/
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int n,q,l,r;
  cin >> n >> q;
  vector<int> sum(n+1);
  for(int i=1;i<=n;i++){
    cin >> sum[i];
  }
  sort(sum.begin(),sum.end());
  for(int i=1;i<=n;i++){
    sum[i]+=sum[i-1];
  }
  for(int i=0;i<q;i++){
    cin >> l >> r;
    cout << sum[r] - sum[l-1] << '\n'; 
  }
  return 0;
}