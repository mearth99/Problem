/*
입력
첫 번째 줄에는 테스트 케이스의 T(1 ≤ T ≤ 100)가 주어진다. 각 테스트 케이스마다

첫 번째 줄에 3개의 정수 n, m, t (2 ≤ n ≤ 2 000, 1 ≤ m ≤ 50 000 and 1 ≤ t ≤ 100)가 주어진다. 각각 교차로, 도로, 목적지 후보의 개수이다.
두 번째 줄에 3개의 정수 s, g, h (1 ≤ s, g, h ≤ n)가 주어진다. s는 예술가들의 출발지이고, g, h는 문제 설명에 나와 있다. (g ≠ h)
그 다음 m개의 각 줄마다 3개의 정수 a, b, d (1 ≤ a < b ≤ n and 1 ≤ d ≤ 1 000)가 주어진다. a와 b 사이에 길이 d의 양방향 도로가 있다는 뜻이다.
그 다음 t개의 각 줄마다 정수 x가 주어지는데, t개의 목적지 후보들을 의미한다. 이 t개의 지점들은 서로 다른 위치이며 모두 s와 같지 않다.
교차로 사이에는 도로가 많아봐야 1개이다. m개의 줄 중에서 g와 h 사이의 도로를 나타낸 것이 존재한다. 또한 이 도로는 목적지 후보들 중 적어도 1개로 향하는 최단 경로의 일부이다.

출력
테스트 케이스마다

입력에서 주어진 목적지 후보들 중 불가능한 경우들을 제외한 목적지들을 공백으로 분리시킨 오름차순의 정수들로 출력한다.
*/


#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define INF 2000000
using namespace std;
vector<pair<int, int>> graph[2001];
int node[3][2001];
int n;
void DFS(int node_select, int start){
  priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
  for(int i=0;i<2001;i++)
    node[node_select][i] = INF;
  q.push({0,start});
  while(!q.empty()){
    int cost = q.top().first;
    int target = q.top().second;
    q.pop();
    if(node[node_select][target] == INF){
      node[node_select][target] = cost;
      for(auto i: graph[target]){
        if(node[node_select][i.first] == INF)
          q.push({cost+i.second,i.first});
      }
    }
  }
}
int main(){
  int T,m,t,s,g,h;
  vector<int> output;
  cin >> T;
  while(T>0){
    for(int i=0;i<2001;i++)
      graph[i].clear();
    vector<int> dest_cand;
    cin >> n >> m >> t;
    cin >> s >> g >> h;
    for(int i=0;i<m;i++){
      int from, to, cost;
      cin >> from >> to >> cost;
      graph[from].push_back({to,cost});
      graph[to].push_back({from,cost});
    }
    for(int i=0;i<t;i++){
      int candidate;
      cin >> candidate;
      dest_cand.push_back(candidate);
    }
    DFS(0,s);
    DFS(1,g);
    DFS(2,h);
    for(auto candidate:dest_cand){
      if(node[0][candidate]==node[0][g] + node[1][h] + node[2][candidate])
        output.push_back(candidate);
      else if(node[0][candidate]==node[0][h] + node[2][g] + node[1][candidate])
        output.push_back(candidate);
    }
    sort(output.begin(),output.end());
    for(auto i : output){
      cout << i << ' ';
    }
    cout << '\n';
    dest_cand.clear();
    output.clear();
    T--;
  }
}