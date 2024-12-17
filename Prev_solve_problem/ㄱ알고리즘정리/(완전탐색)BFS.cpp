/*
 DFS는 너비우선으로 큐를 통해 동작하는 방식이며, 넓게 탐색하는 방식이다.
 보통 그래프, 트리 탐색에서 사용하며 이를 사용한다면 계속 연결된 그래프를 넓게 탐색한다.
 큐 구현할 수 있다.
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
#define MAX 500

vector<vector<int>> graph;
queue<int> q; //큐를 통해 그래프를 탐색한다.
int visit[MAX]; //방문할 개수이다.
void BFS(int start){
  // graph[from][to] = 1 방식일때
  q.push(start);
  visit[start] = true;
  while(!q.empty()){ //큐안에 있는 내용이 모두 없을 때까지 탐사한다 => 모든 노드를 한번씩 방문한다.
    int target = q.front();
    q.pop();
    for(int i=0;i<graph[target].size();i++){
      if(graph[target][i]==1 && !visit[i]){
        //만약, 방문한적이 없고 길이 이어져 있다면, 
        q.push(i);
        visit[i] = true;  // ** <- DFS와 다르게 여기서 방문처리를 해야 Queue에 중복 방문을 하는 걸 막을 수 있다.
      }
    }
  }
}
void BFS2(int start){
  // graph[from].push_back(to)방식도 사용가능하며 이 경우도 같이 서술하겠다.

  q.push(start);
  visit[start] = true;
  while(!q.empty()){ //큐안에 있는 내용이 모두 없을 때까지 탐사한다 => 모든 노드를 한번씩 방문한다.
    int target = q.front();
    q.pop();
    for(auto i : graph[target]){
      if(!visit[i]){
        //만약, 방문한적이 없고 길이 이어져 있다면, 
        q.push(i);
        visit[i] = true;  // ** <- DFS와 다르게 여기서 방문처리를 해야 Queue에 중복 방문을 하는 걸 막을 수 있다.
      }
    }
  }
}
int main(){
  //두가지 방식을 사용하였다(코드 테크닉)
  BFS(0);
  BFS2(0);
}