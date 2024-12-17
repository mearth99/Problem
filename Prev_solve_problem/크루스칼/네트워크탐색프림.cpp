
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

bool visited[1001];

int main(){
  int n,m;
  cin >> n >> m;
  vector<pair<int,int>> graph[1001]; 
  for(int i=0;i<m;i++){
    int from, to, cost;
    cin >> from >> to >> cost;
    graph[from].push_back({to,cost});
    graph[to].push_back({from,cost});
  }
  for(int i=0;i<1001;i++) visited[i] = false;

  int sum=0;
  priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
  q.push({0,2});
  cout << endl << endl;
  while(!q.empty()){
    int cost = q.top().first;
    int target = q.top().second;
    cout << cost << endl;
    q.pop();
    if(!visited[target]){
      visited[target] = true;
      sum += cost;

      for(auto i : graph[target]){
        if(!visited[i.first])
          q.push({i.second,i.first});
      }
    }
  }
  cout << sum;
}