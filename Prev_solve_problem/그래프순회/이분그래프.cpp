/*
입력
입력은 여러 개의 테스트 케이스로 구성되어 있는데, 첫째 줄에 테스트 케이스의 개수 K가 주어진다. 
각 테스트 케이스의 첫째 줄에는 그래프의 정점의 개수 V와 간선의 개수 E가 빈 칸을 사이에 두고 순서대로 주어진다. 
각 정점에는 1부터 V까지 차례로 번호가 붙어 있다. 이어서 둘째 줄부터 E개의 줄에 걸쳐 간선에 대한 정보가 주어지는데, 
각 줄에 인접한 두 정점의 번호 u, v (u ≠ v)가 빈 칸을 사이에 두고 주어진다. 

출력
K개의 줄에 걸쳐 입력으로 주어진 그래프가 이분 그래프이면 YES, 아니면 NO를 순서대로 출력한다.
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
void BFS(int start, vector<vector<int>> &graph, vector<int> visited){
  queue<int> q;
  q.push(start);
  visited[start] = 1;
  while(!q.empty()){
    int target = q.front();
    q.pop();
    for(auto i : graph[target]){

    }
  }

}
int main()
{
  //양뱡향 정점을 만든다. Q에 임의의 정점을 넣고 시작한다.
  int t,u,e;
  cin >> t;
  while(t>0){
    cin >> u >> e;
    vector<vector<int>> graph;
    vector<int> visited;
    for(int i=0;i<e;e++){
      int from, to;
      cin >> from >> to;
      graph
    }
    BFS(1,graph,visited);
    graph.clear();
    visited.clear();
    t--;
  }
    
}