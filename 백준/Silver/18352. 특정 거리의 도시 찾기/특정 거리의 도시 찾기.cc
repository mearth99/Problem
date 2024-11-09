
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define INF 987654321
using namespace std;

vector<int> graph[300001];
queue<pair<int,int>> q; //큐를 통해 그래프를 탐색한다.
int visit[300001];
void BFS(int start,int distance){
  // graph[from].push_back(to)방식도 사용가능하며 이 경우도 같이 서술하겠다.
  q.push({start,0});
  visit[start] = 0;
  while(!q.empty()){ //큐안에 있는 내용이 모두 없을 때까지 탐사한다 => 모든 노드를 한번씩 방문한다.
    int target = q.front().first;
    int cost = q.front().second;
    q.pop();
    if(cost>distance) continue;
    for(auto i : graph[target]){
      if(visit[i]>cost+1){
        //만약, 방문한적이 없고 길이 이어져 있다면, 
        q.push({i,cost+1});
        visit[i] = cost+1;
      }
    }
  }
}
int main(){
  //두가지 방식을 사용하였다(코드 테크닉)
  vector<int> answer;
  fill_n(visit,300001,INF);
  int n, m, k, x;
  cin >> n >> m >> k >> x;
  for(int i=0;i<m;i++){
    int from, to;
    cin >> from >> to;
    graph[from].push_back(to);
  }
  BFS(x,k);
  for(int i=1;i<=n;i++){
    if(visit[i]==k) answer.push_back(i);
  }
  sort(answer.begin(),answer.end());
  if(answer.size()){
    for(auto it : answer)
        cout << it << '\n';
  }else
    cout << -1;
}