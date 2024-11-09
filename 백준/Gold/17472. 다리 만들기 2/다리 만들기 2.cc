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
#include <queue>
#define INF 987654321
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
int costs = 0;
int room[11][11];
bool visit[11][11];
vector<house> arr;
vector<vector<int>> v_room(11,vector<int>(11,INF));
int node[7];


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
void BFS(int sy, int sx, int u){
  int dx[4] = {0,0,1,-1};
  int dy[4] = {1,-1,0,0};
  queue<pair<int,int>> q;
  q.push({sy,sx});
  visit[sy][sx] = true;
  while(!q.empty()){
    int y = q.front().first;
    int x = q.front().second;
    q.pop();
    room[y][x] = u;
    for(int i=0;i<4;i++){
      int nx = dx[i] + x;
      int ny = dy[i] + y;
      if(nx>=0 && nx<m && ny >=0 && ny<n && visit[ny][nx]==false && room[ny][nx]!=0){
        visit[ny][nx] = true;
        q.push({ny,nx});
      }
    }
  }
  return;
}
void Go_island(int y,int x){
  int start_node = room[y][x];
  int c_x=x,c_y=y;
  int count = 0;
  while(c_x<11){
    if(room[y][c_x]!=start_node){
      if(room[y][c_x]!=0){
        if(count==1) break;
        int end_node = room[y][c_x];
        v_room[start_node][end_node] = min(v_room[start_node][end_node],count);
        break;
      }
      count++;
    }else{
      count = 0;
    }
    c_x++;
  }
  c_x=x,c_y=y;
  count = 0;
  while(c_y<11){
    if(room[c_y][x]!=start_node){
      if(room[c_y][x]!=0){
        if(count==1) break;
        int end_node = room[c_y][x];
        v_room[start_node][end_node] = min(v_room[start_node][end_node],count);
        break;
      }
      count++;
    }else{
      count = 0;
    }
    c_y++;
  }
  return;
}

void Sol(){
  // costs =0;
  sort(arr.begin(),arr.end(),cmp);
  for(int i=0;i<arr.size();i++){
    if(!Find_Parent(arr[i].from,arr[i].to)){
      costs += arr[i].cost;
      Union_Parent(arr[i].from,arr[i].to);
    }
  }
  return;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> m;
  for(int i=1;i<=7;i++) node[i] = i;
  for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
      cin >> room[i][j];;
  
  int uniq = 0;
  for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
        if(room[i][j]==1 && !visit[i][j])
          BFS(i,j,++uniq);
  
  for(int i=0;i<n;i++)
    for(int j=0;j<m;j++){
      if(room[i][j])
        Go_island(i,j);
    }
  for(int i=0;i<11;i++)
    for(int j=0;j<11;j++)
      if(v_room[i][j]!=INF){
        arr.push_back({i,j,v_room[i][j]});
        // arr.push_back({j,i,v_room[i][j]});
      }
  Sol();
  for(int i=2;i<=uniq;i++)
    if(Get_Parent(node[i-1])!=Get_Parent(node[i])){
      cout << -1;
      return 0;
    }
  
  cout << costs;    
  return 0;   
}
