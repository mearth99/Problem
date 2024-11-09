/*
입력
첫째 줄에 N(1 ≤ N ≤ 1,000), M(1 ≤ M ≤ 1,000)이 주어진다. 다음 N개의 줄에 M개의 숫자로 맵이 주어진다. 
(1, 1)과 (N, M)은 항상 0이라고 가정하자.

출력
첫째 줄에 최단 거리를 출력한다. 불가능할 때는 -1을 출력한다.

//생각. 단 한번만 부수거나 안부수는걸 선택할 수 있다.
모든 경우의 수를 탐색하면서, 부쉈는지 안부쉈는지 확인한다. 
안부순 경우, 부수고 부슨 경우 부수지 않고 진행한다.
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define INF 20000000
using namespace std;

struct codes{
  int x;
  int y;
  int move;
  bool is_crash;
};
codes make_codes(int y, int x, int move, bool crash){
  codes re_code;
  re_code.move = move;
  re_code.is_crash = crash;
  re_code.x = x;
  re_code.y = y;
  return re_code;
}

int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};
int main()
{
    queue<codes> q;
    ios::sync_with_stdio(0); cin.tie(0);
    int N,M,min_value=INF;
    cin >> N >> M;
    string temp;
    vector<vector<int>> position(N,vector<int> (M));
    vector<vector<bool>> visited(N,vector<bool> (M));
    vector<vector<bool>> crash_visited(N,vector<bool> (M));
    
    for(int i=0;i<N;i++){
      cin >> temp;
      for(int j=0;j<temp.length();j++)
        position[i][j] = temp.at(j) - '0';
    }
    q.push(make_codes(0,0,1,false));
    visited[0][0] = true;
    while(!q.empty()){
      codes target = q.front();
      q.pop();
      if(target.x==M-1 && target.y == N-1){
        min_value = min(min_value,target.move);
      }
      for(int i=0;i<4;i++){
        int nx = target.x + dx[i];
        int ny = target.y + dy[i];
        if(nx>=0 && nx<M && ny>=0 && ny<N){
          if(target.is_crash){
            //부순 경우
              if(position[ny][nx]==0 && !visited[ny][nx] && !crash_visited[ny][nx]){
                //visited : 부수지 않았을 때 탐방한 곳. <- 겹치면 벽부술 기회가 없는 하위호환이 방문할 이유가 없다.
                //crash_visited : 부수고 이미 탐방한 곳. 기존과 일치.
                q.push(make_codes(ny,nx,target.move+1,target.is_crash));
                crash_visited[ny][nx] = true;
              }  
          }else{
            //부수지 않았을 경우.
              if(position[ny][nx]==0 && !visited[ny][nx]){
                q.push(make_codes(ny,nx,target.move+1,target.is_crash));
                visited[ny][nx] = true;
              }
              if(position[ny][nx]==1 && !visited[ny][nx]){
                q.push(make_codes(ny,nx,target.move+1,true));
                visited[ny][nx] = true;
              }
          }
      }
    }
  }
    if(min_value==INF)
      cout << -1;
    else
      cout << min_value;
    return 0;
}