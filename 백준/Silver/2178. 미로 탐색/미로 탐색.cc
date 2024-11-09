/*
입력
첫째 줄에 두 정수 N, M(2 ≤ N, M ≤ 100)이 주어진다. 다음 N개의 줄에는 M개의 정수로 미로가 주어진다. 각각의 수들은 붙어서 입력으로 주어진다.

출력
첫째 줄에 지나야 하는 최소의 칸 수를 출력한다. 항상 도착위치로 이동할 수 있는 경우만 입력으로 주어진다.
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
struct codes{
  int x;
  int y;
  int count;
};
codes make_codes(int y, int x , int count){
  codes re_code;
  re_code.count = count;
  re_code.x = x;
  re_code.y = y;
  return re_code;
}
int dx[4] = {0,0,-1,1}; // 상하좌우
int dy[4] = {-1,1,0,0};
bool visited[101][101];
int n,m,output = 999999;

void BFS(int y, int x){
    queue<codes> q;
    visited[y][x] = 0;
    q.push(make_codes(y,x,1));
    
    while(!q.empty()){
        codes target = q.front();
        q.pop();
        if(target.x==m-1 && target.y == n-1)
          output = min(output, target.count);
        
        for(int i=0;i<4;i++){
            int nx = target.x + dx[i];
            int ny = target.y + dy[i];
            if(nx>=0 && nx<m && ny>=0 && ny<n && visited[ny][nx]==1){
                q.push(make_codes(ny,nx,target.count+1));
                visited[ny][nx] = 0;
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for(int i=0;i<n;i++){
      string temp;
      cin >> temp;
      for(int j=0;j<temp.length();j++)
        visited[i][j] = temp.at(j) - '0';
    }
    BFS(0,0);
    cout << output;
    return 0;
}