/*
입력
입력의 첫째 줄에는 테스트 케이스의 개수가 주어진다.

각 테스트 케이스는 세 줄로 이루어져 있다. 첫째 줄에는 체스판의 한 변의 길이 l(4 ≤ l ≤ 300)이 주어진다. 
체스판의 크기는 l × l이다. 체스판의 각 칸은 두 수의 쌍 {0, ..., l-1} × {0, ..., l-1}로 나타낼 수 있다.
둘째 줄과 셋째 줄에는 나이트가 현재 있는 칸, 나이트가 이동하려고 하는 칸이 주어진다.

출력
각 테스트 케이스마다 나이트가 최소 몇 번만에 이동할 수 있는지 출력한다.
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
struct codes{
  int x;
  int y;
  int timed;
};
codes make_codes(int y, int x , int timed){
  codes re_code;
  re_code.timed = timed;
  re_code.x = x;
  re_code.y = y;
  return re_code;
}
int dx[4] = {0,0,1,-1};
int dy[4] = {-1,1,0,0};
int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m,count=0,tomato_empty=0;
    queue<codes> q;
    cin >> m >> n;
    vector<vector<int>> farm(n,vector<int>(m));
    vector<vector<bool>> visited(n,vector<bool>(m));
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++){
            cin >> farm[i][j];
            if(farm[i][j]==1){
                q.push(make_codes(i,j,0));
                visited[i][j] = true;
            }else if(farm[i][j] == -1){
                visited[i][j] = true;
                tomato_empty++;
            }
            
        }

    while(!q.empty()){
        codes target = q.front();
        q.pop();
        count++;
        if(count==n*m-tomato_empty){
            cout << target.timed;
            return 0;
        }else{
            for(int i=0;i<4;i++){
                int ny = target.y + dy[i];
                int nx = target.x + dx[i];
                if(nx>=0 && nx<m && ny>=0 && ny<n && !visited[ny][nx]){
                    q.push(make_codes(ny,nx,target.timed+1));
                    visited[ny][nx] = true;
                }
            }
        }
    }
    cout << -1;
    return 0;
}