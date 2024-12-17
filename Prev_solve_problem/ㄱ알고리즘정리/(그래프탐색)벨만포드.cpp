/*
  벨만포드 알고리즘은 최소 신장트리를 구성하되 비용에 음수가 있는 경우 사용하게 된다.
  크루스칼 알고리즘을 사용하지 못하는 이유는 크루스칼 알고리즘은 방문한 곳에서 가장 작은 값을 선택하게 되는데.
  마지막에 방문한 곳에서 갈 수 있는 곳이 음수라면, 이를 이용하지 못하기 때문에 사용할 수 가 없게 된다.
  
  따라서 벨만포드 알고리즘을 사용하거나, 프림 알고리즘을 사용한다면, 음수 가중치가 존재하는 환경에서도 최소 신장 트리를 구할 수 있다.

  알고리즘은 다음과 같다.
  (정점-1)번의 매 단계마다 모든 간선을 확인하는데, "방문한 적이 없는 모든 노드는 무시한다."
  이후 방문한 적이 있는 노드를 방문 시, 기존 비용과 현재 방문한 거리를 비교하여 더 작은 값으로 갱신한다.

  *맨 처음에는 시작 지점의 노드만 방문했기 때문에, 시작 지점에서 갈 수 있는 모든 노드를 방문한다.
  이후, N-1번의 반복을 통해 모든 노드를 탐색할 수 있다. 

  그리고 사이클이 존재하는지도 파악할 수 있는데, N-1번 이후 추가로 1번 더 돌리게 되었을 때 
  만약 비용이 갱신된다면 => 사이클이 존재한다.
  갱신이 안된다면 => 사이클이 존재하지 않는다라고 파악할 수 있는 것이다.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define INF 2100000000
#define MAX 10001
using namespace std;

struct codes
{
  int from; 
  int to; 
  int cost;
};


int n,m;
long long node[MAX];
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
  for(int i=1;i<=n;i++) node[i] = INF;
  for(int i=0;i<m;i++){
    int from, to, cost;
    cin >> from >> to >> cost;
    city.push_back({from,to,cost});
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