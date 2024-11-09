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
#include <cmath>
#define MAX 1001
using namespace std;

double graph[MAX][MAX];
bool visited[MAX];
double costs = 0;
void Prim(int start,int n){
  priority_queue<pair<double,int>,vector<pair<double,int>>,greater<pair<double,int>>> q;
  q.push({0.0,start});
  while(!q.empty()){
    double cost = q.top().first;
    int target = q.top().second;
    q.pop();
    if(!visited[target]){
      visited[target] = true;
      costs += cost;
      for(int i=1;i<=n;i++){
        if(!visited[i]){
          double check = graph[target][i];
          q.push({graph[target][i],i});
        }
      }
    }
  }
}


int main(){
  int n,m;
  cin >> n >> m;
  pair<int,int> space[MAX];
  for(int i=1;i<=n;i++){
    cin >> space[i].first >> space[i].second;
  }
  for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++){
      double x = space[i].first - space[j].first;
      double y = space[i].second - space[j].second;
      graph[i][j] = sqrt(x*x + y*y);
    }
  for(int i=0;i<m;i++){
    int from, to;
    cin >> from >> to;
    graph[from][to] = 0;
    graph[to][from] = 0;
  }
  Prim(1,n);
  cout << fixed;
  cout.precision(2);
  cout << costs;
  return 0;
}