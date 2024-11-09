
/*
문제
N개의 수 A1, A2, ..., AN이 입력으로 주어진다. 총 M개의 구간 i, j가 주어졌을 때, i번째 수부터 j번째 수까지 합을 구하는 프로그램을 작성하시오.

입력
첫째 줄에 수의 개수 N이 주어진다. (1 ≤ N ≤ 100,000) 둘째 줄에는 A1, A2, ..., AN이 주어진다. (-1,000 ≤ Ai ≤ 1,000) 셋째 줄에는 구간의 개수 M이 주어진다. 
(1 ≤ M ≤ 100,000) 넷째 줄부터 M개의 줄에는 각 구간을 나타내는 i와 j가 주어진다. (1 ≤ i ≤ j ≤ N)

출력
총 M개의 줄에 걸쳐 입력으로 주어진 구간의 합을 출력한다.
*/
#include <vector>
#include <iostream>
#include <map>
using namespace std;

int main()
{
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  
  int n,m;
  cin >> n;
  vector<int> sum(n+1);
  for(int i=1;i<=n;i++){
      cin >> sum[i];
      sum[i] += sum[i-1]; 
  }
  cin >> m;
  for(int i=0;i<m;i++){
    int x1,x2;
    cin >> x1 >> x2;
    cout << sum[x2]-sum[x1-1]<< '\n';
  }
  return 0;
}