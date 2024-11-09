/*
  1. 프림알고리즘은 최초 출발 노드와 연결되어 있는 간선중 가장 가중치가 낮은걸 선택한다.
  이후, 출발노드 집합에 연결된 간선 중 가중치가 최소인 것을 선택하되 방문하지 않은걸 추가한다.
  N-1개 간선이 선택될 때 까지 반복한다.
  프림 알고리즘의 경우 그래프가 양방향일 때 제대로 활용할 수 있다.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define MAX 10001
using namespace std;
vector<pair<int,int>> graph[MAX];
int visited[MAX];
long long costs = 0;
void Prim(int start){
  priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
  q.push({0,start});
  while(!q.empty()){
    int cost = q.top().first;
    int target = q.top().second;
    q.pop();
    if(!visited[target]){
      visited[target] = true;
      costs += cost;
      for(auto i : graph[target]){
        if(!visited[i.first])
          q.push({i.second,i.first});
      }
    }
  }
}


int main(){
  int n,m;
  cin >> n >> m;
  for(int i=0;i<m;i++){
    int from, to, cost;
    cin >> from >> to >> cost;
    graph[from].push_back({to,cost});
    graph[to].push_back({from,cost});
  }
  Prim(1);
  cout << costs;
  return 0;
}