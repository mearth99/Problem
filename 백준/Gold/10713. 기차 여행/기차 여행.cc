
/*
입력
첫 번째 줄에서는 정수 N, M이 주어진다.
두 번째 줄에는 M개의 정수 P1,P2,...PM이 주어진다. j일째 (1 ≦ j ≦ M − 1) 에 도시 Pj에서 Pj+1로 이동하는 것을 의미한다.
3번째 줄부터 N-1개의 줄에는 (1 ≦ i ≦ N − 1) 3개의 정수 Ai, Bi, Ci가 주어진다. 각각 철도 i의 티켓을 구입하는 가격, 철도 i를 카드를 사용했을 때 통과하는 가격, IC카드를 구매하는 가격을 의미한다.
출력
여행에 드는 최저 비용을 첫째 줄에 출력하시오.
*/
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

void go(vector<long long> &sum, int start, int end){
  if(start>end){
    sum[end]++;
    sum[start]--;
  }else{
    sum[start]++;
    sum[end]--;
  }
  return;
}

int main()
{
  // ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int n,m;
  int start,end;
  int ticket, ic, buyic;
  long long result=0; 
  cin >> n >> m;
  vector<long long> Sum(n+1);
  cin >> start;
  for(int i=0;i<m-1;i++){
    cin >> end;
    go(Sum,start,end);
    start = end;
  }
  for(int i=1;i<=n;i++)
      Sum[i] += Sum[i-1]; 
  for(int i=1;i<n;i++){
    cin >> ticket >> ic >> buyic;
    result += min(ticket*Sum[i],ic*Sum[i]+buyic);
  }
  cout << result;
  return 0;
}