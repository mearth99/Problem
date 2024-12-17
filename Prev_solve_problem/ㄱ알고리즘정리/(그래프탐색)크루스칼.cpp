/*
 크루스칼은 최소 신장 트리를 만드는 비용 혹은 최소 신장 트리의 모습을 알 수 있다.
 
 최소 신장 트리는 Cycle을 형성하지 않고, 모든 Node에 연결하는 트리를 말한다. + 비용이 가장 적은.
 
 크루스칼알고리즘은 다음과 같이 동작한다.
 1. 비용이 낮은 순서대로 정렬한다.
 2. Node와 Node를 연결하기 전, 이 둘 간에 Cycle이 형성되어 있는지 확인한다. (서로 연결되어 있는지 확인하거나, 같은 모임인지 파악한다.)
 3. Cycle이 없다면, 연결한다.
 4. 모든 탐색이 끝나면 종료한다.

*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define MAX 500

using namespace std;

bool cmp(pair<int,pair<int,int>> &p1,pair<int,pair<int,int>> &p2){
  return p1.first < p2.first; //오름차순정렬
}


int node[MAX];
int GetParent(int x){
  if(x==node[x]) return x;
  else return node[x] = GetParent(node[x]);
}
void UnionParent(int a, int b){
  a = GetParent(a);
  b = GetParent(b);
  if(a<b) node[b] = a;
  else node[a] = b; 
}
bool FindParent(int a, int b){
  a = GetParent(a);
  b = GetParent(b);
  if(a==b) return true;
  else return false;
}
int main(){
  for(int i=0;i<MAX;i++)
    node[i] = i;

  vector<pair<int,pair<int,int>>> graph;
  //first => cost. second.first = from. second.second = to;
  sort(graph.begin(),graph.end(),cmp);
  int costs = 0;
  for(int i=0;i<graph.size();i++){
    if(!FindParent(graph[i].second.first,graph[i].second.second)){
      //둘 사이에 사이클이 형성되어있지 않은 경우.
      costs += graph[i].first; //비용을 더해준다. (선택했다는 뜻)
      UnionParent(graph[i].second.first,graph[i].second.second);
      //둘 사이를 연결해준다. (방문했다고도 봐도 되겠다. ~~ 같은 집합이다.)
    }
  }

  return 0;
}