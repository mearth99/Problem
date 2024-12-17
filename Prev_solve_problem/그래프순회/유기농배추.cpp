/*
입력
입력의 첫 줄에는 테스트 케이스의 개수 T가 주어진다. 그 다음 줄부터 각각의 테스트 케이스에 대해 첫째 줄에는 배추를 심은 배추밭의 가로길이 M(1 ≤ M ≤ 50)과 
세로길이 N(1 ≤ N ≤ 50), 그리고 배추가 심어져 있는 위치의 개수 K(1 ≤ K ≤ 2500)이 주어진다. 그 다음 K줄에는 배추의 위치 X(0 ≤ X ≤ M-1), Y(0 ≤ Y ≤ N-1)가 주어진다. 
두 배추의 위치가 같은 경우는 없다.

출력
각 테스트 케이스에 대해 필요한 최소의 배추흰지렁이 마리 수를 출력한다.
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int dx[4] = {0,0,-1,1}; // 상하좌우
int dy[4] = {-1,1,0,0};
bool visited[50][50];
int n,m;
vector<int> output;
void BFS(int y, int x){
    queue<pair<int,int>> q;
    visited[y][x] = 0;
    q.push(make_pair(y,x));
    while(!q.empty()){
        int qy = q.front().first;
        int qx = q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int nx = qx + dx[i];
            int ny = qy + dy[i];
            if(nx>=0 && nx<m && ny>=0 && ny<n && visited[ny][nx]==1){
                q.push(make_pair(ny,nx));
                visited[ny][nx] = 0;
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
	cin.tie(0);
    int t,k;
    cin >> t;
    while(t>0){
        int target = 0;
        for(int i=0;i<50;i++)
            for(int j=0;j<50;j++)
                visited[i][j] = 0;

        cin >> m >> n >> k;
        for(int i=0;i<k;i++){
            int x, y;
            cin >> x >> y;
            visited[y][x] = 1;
        }
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(visited[i][j]==1){
                    target++;
                    BFS(i,j);
                }
        cout << target << '\n';
        t--;
    }
    return 0;
}