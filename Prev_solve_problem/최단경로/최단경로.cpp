#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define INF 2000000
using namespace std;

int main(){
  int v,e,start;
  cin >> v >> e >> start;
  vector<vector<int>> graph(v+1, vector<int>(v+1));
  vector<int> node(v+1,INF);
  for(int i=0;i<e;i++){
    int from, to, cost;
    cin >> from >> to >> cost;
    graph[from][to] = cost;
  }
  priority_queue<pair<int, int>> q;
  q.push({0, start});
  while(!q.empty()){
    int cost = -q.top().first;
    int target = q.top().second; 
    q.pop();
    if(node[target]==INF){
      //한번도 접근하지 않은 곳. 탐색해야한다.
      node[target] = cost;
      for(int i=0;i<graph[target].size();i++){
        if(graph[target][i]==0) continue;
        else if(node[i]==INF)
          q.push({-(cost+graph[target][i]),i});
      }
    }
  }
  for(int i=1;i<=v;i++){
    if(node[i]==INF)
      cout << "INF" << '\n';
    else
      cout << node[i] << '\n';
  }
}