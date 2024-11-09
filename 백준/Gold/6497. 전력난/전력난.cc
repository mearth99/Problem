/*
  1. 프림알고리즘은 최초 출발 노드와 연결되어 있는 간선중 가장 가중치가 낮은걸 선택한다.
  이후, 출발노드 집합에 연결된 간선 중 가중치가 최소인 것을 선택하되 방문하지 않은걸 추가한다.
  N-1개 간선이 선택될 때 까지 반복한다.
  프림 알고리즘의 경우 그래프가 양방향일 때 제대로 활용할 수 있다.
*/
#include <limits>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
struct house{
  int from;
  int to;
  int cost;
};
bool cmp(house p1, house p2){
    return p1.cost < p2.cost;
}

int n,m;
vector<house> arr;
int node[200001];
int costs=0;

int Get_Parent(int x){
  if(node[x]==x) return x;
  else return node[x] = Get_Parent(node[x]);
}
void Union_Parent(int a, int b){
  a = Get_Parent(a);
  b = Get_Parent(b);
  if(a>b)
    node[a] = b;
  else 
    node[b] = a;
  return;
}
bool Find_Parent(int a, int b){
  a = Get_Parent(a);
  b = Get_Parent(b);
  if(a==b) return true;
  else return false;
}
void Sol(){
  sort(arr.begin(),arr.end(),cmp);
  for(int i=0;i<arr.size();i++){
    if(!Find_Parent(arr[i].from,arr[i].to)){
      costs -= arr[i].cost;
      Union_Parent(arr[i].from,arr[i].to);
    }
  }
  return;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  while(1){
    cin >> m >> n;
    if(m==0 && n==0) break;
    arr.clear();
    costs=0;
    for(int i=1;i<=m;i++)
      node[i] = i;
    for(int i=0;i<n;i++){
      int from, to, cost;
      cin >> from >> to >> cost;
      arr.push_back({from,to,cost});
      costs += cost;
    }
    Sol();
    cout << costs <<'\n';
  }
}