/*
 DFS는 깊이우선탐색으로 재귀함수, 스택를 통해 동작하는 방식이며, 깊게 탐색하는 방식이다.
 보통 그래프, 트리 탐색에서 사용하며 이를 사용한다면 계속 연결된 그래프를 깊게 탐색한다.
 스택 혹은 재귀로 구현할 수 있다.
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
#define MAX 500

vector<vector<int>> graph;
int visit[MAX]; //방문할 개수이다.
void DFS(int start){
  // graph[from][to] = 1 방식일때
  //start 지점을 방문처리한다.
  visit[start] = true;
  for(int i=0;i<graph[start].size();i++){
    if(graph[start][i]==1 && !visit[i]){ // 길이 연결되어 있고 동시에, 이 i번째 노드에 방문한 적이 있는지 확인한다.
      //만약, 방문한적이 없고 길이 이어져 있다면, 
      DFS(i);
      //다음과 같은 재귀(스택) 가능 으로 마무리 한다.
    }
  }
}
void DFS2(int start){
  // graph[from].push_back(to)방식도 사용가능하며 이 경우도 같이 서술하겠다.
  //start 지점을 방문처리한다.
  visit[start] = true;
  for(auto i : graph[start]){
    if(!visit[i]){ // 길이 연결되어 있고 동시에, 이 i번째 노드에 방문한 적이 있는지 확인한다.
      //만약, 방문한적이 없고 길이 이어져 있다면, 
      DFS2(i);
      //다음과 같은 재귀(스택) 가능 으로 마무리 한다.
    }
  }
}
int main(){
  //두가지 방식을 사용하였다(코드 테크닉)
  DFS(0);
  DFS2(0);
}