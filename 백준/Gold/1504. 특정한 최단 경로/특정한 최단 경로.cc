/*
입력
첫째 줄에 정점의 개수 N과 간선의 개수 E가 주어진다. (2 ≤ N ≤ 800, 0 ≤ E ≤ 200,000) 둘째 줄부터 E개의 줄에 걸쳐서 세 개의 정수 a, b, c가 주어지는데, 
a번 정점에서 b번 정점까지 양방향 길이 존재하며, 그 거리가 c라는 뜻이다. (1 ≤ c ≤ 1,000) 다음 줄에는 반드시 거쳐야 하는 두 개의 서로 다른 정점 번호 v1과 v2가 주어진다. 
(v1 ≠ v2, v1 ≠ N, v2 ≠ 1) 임의의 두 정점 u와 v사이에는 간선이 최대 1개 존재한다.

출력
첫째 줄에 두 개의 정점을 지나는 최단 경로의 길이를 출력한다. 그러한 경로가 없을 때에는 -1을 출력한다.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define INF 200000000
using namespace std;
vector<int> node(801,INF);
vector<pair<int,int>> graph[801];
void D(int start){
  for(int i=0;i<801;i++) node[i] = INF;
  priority_queue<pair<int, int>,vector<pair<int, int>>,greater<pair<int,int>>> q;
  
  q.push({0,start});
  while(!q.empty()){
    int cost = q.top().first;
    int target = q.top().second; 
    q.pop();
    if(node[target]==INF){
      //한번도 접근하지 않은 곳. 탐색해야한다.
      node[target] = cost;
      for(auto i : graph[target]){
        if(node[i.second]==INF)
          q.push({cost+i.first,i.second});
      }
    }
  }
}
int main(){
  int n,e,v1,v2;
  cin >> n >> e;
  for(int i=0;i<e;i++){
    int from, to, cost;
    cin >> from >> to >> cost;
    graph[from].push_back({cost,to});
    graph[to].push_back({cost,from});
  }
  cin >> v1 >> v2;
  D(1);
  int fromTov1 = node[v1]; 
  int fromTov2 = node[v2]; 
  D(v1);
  int v1Tov2 = node[v2];
  int v1Ton = node[n];
  D(v2);
  int v2Ton = node[n];
  int output = INF;
  output = min(output,fromTov1+v1Tov2+v2Ton);
  output = min(output,fromTov2+v1Tov2+v1Ton);
  if(output == INF)
    cout << -1;
  else
    cout << output;
}