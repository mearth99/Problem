/*
입력
첫째 줄에 도시의 개수 N (1 ≤ N ≤ 500), 버스 노선의 개수 M (1 ≤ M ≤ 6,000)이 주어진다. 
둘째 줄부터 M개의 줄에는 버스 노선의 정보 A, B, C (1 ≤ A, B ≤ N, -10,000 ≤ C ≤ 10,000)가 주어진다. 

출력
만약 1번 도시에서 출발해 어떤 도시로 가는 과정에서 시간을 무한히 오래 전으로 되돌릴 수 있다면 첫째 줄에 -1을 출력한다. 
그렇지 않다면 N-1개 줄에 걸쳐 각 줄에 1번 도시에서 출발해 2번 도시, 3번 도시, ..., N번 도시로 가는 가장 빠른 시간을 순서대로 출력한다. 
만약 해당 도시로 가는 경로가 없다면 대신 -1을 출력한다.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define INF 2100000000
using namespace std;

struct codes
{
  int from;
  int to;
  int cost;
};
codes make_codes(int from, int to, int cost){
  codes temp;
  temp.cost = cost;
  temp.from = from;
  temp.to = to;
  return temp;
}

int n,m;
long long node[501];
vector<codes> city;

bool bellmanford(int start){
  node[start] = 0;
  for(int i=1;i<=n;i++){
    for(int j=0;j<city.size();j++){
      int from = city[j].from;
      int to = city[j].to;
      int cost = city[j].cost;
      
      if(node[from]==INF) continue;

      if(node[to] > node[from]+cost){
        node[to] = node[from] + cost;
        if(i==n) return true;
      }
    }
  }
  return false;
}

int main(){
  ios_base::sync_with_stdio(0);
	cin.tie(0);
  cin >> n >> m;
  for(int i=0;i<501;i++) node[i] = INF;
  for(int i=0;i<m;i++){
    int from, to, cost;
    cin >> from >> to >> cost;
    city.push_back(make_codes(from,to,cost));
  }
  if(bellmanford(1)){
    cout << -1;
  }
  else{
    for(int i=2;i<=n;i++)
      if(node[i]==INF)
        cout << -1 << '\n';
      else
        cout << node[i] <<'\n';
  }
  return 0;
}