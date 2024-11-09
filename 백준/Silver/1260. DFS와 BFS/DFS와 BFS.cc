/*
입력
첫째 줄에는 컴퓨터의 수가 주어진다. 컴퓨터의 수는 100 이하인 양의 정수이고 각 컴퓨터에는 1번 부터 차례대로 번호가 매겨진다. 둘째 줄에는 네트워크 상에서 직접 연결되어 있는 컴퓨터 쌍의 수가 주어진다. 이어서 그 수만큼 한 줄에 한 쌍씩 네트워크 상에서 직접 연결되어 있는 컴퓨터의 번호 쌍이 주어진다.

출력
1번 컴퓨터가 웜 바이러스에 걸렸을 때, 1번 컴퓨터를 통해 웜 바이러스에 걸리게 되는 컴퓨터의 수를 첫째 줄에 출력한다.
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
vector<int> d;
vector<int> b;
queue<int> q;
int graph[1001][1001];
int visited[1001];
int n,m,start;
void DFS(int target){
  visited[target] = true;
  d.push_back(target);
  for(int i=1;i<=n;i++)
    if(graph[target][i]==1 && visited[i]==false)
      DFS(i);
}
void BFS(int target){
  q.push(target);
  visited[target] = true;
  while(!q.empty()){
    int value = q.front();
    b.push_back(value);
    q.pop();
    for(int i=1;i<=n;i++){
      if(graph[value][i]==1 && visited[i]==false){
        q.push(i);
        visited[i] = true;
      }
    }
  }
}
int main()
{
    cin >> n >> m >> start;
    for(int i=0;i<m;i++){
      int from, to;
      cin >> from >> to;
      graph[from][to] = 1;
      graph[to][from] = 1;
    }
    DFS(start);
    for(int i=0;i<1001;i++)
      visited[i] = false;
    BFS(start);
    
    for(auto i: d)
      cout << i << ' ';
    cout << endl;
    for(auto i: b)
      cout << i << ' ';
    return 0;
}