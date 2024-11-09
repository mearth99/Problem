/*
입력
첫 번째 줄에는 지도의 크기 N(정사각형이므로 가로와 세로의 크기는 같으며 5≤N≤25)이 입력되고, 그 다음 N줄에는 각각 N개의 자료(0혹은 1)가 입력된다.

출력
첫 번째 줄에는 총 단지수를 출력하시오. 그리고 각 단지내 집의 수를 오름차순으로 정렬하여 한 줄에 하나씩 출력하시오.
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
vector<int> output;
int dx[4] = {0,0,-1,1}; // 상하좌우
int dy[4] = {-1,1,0,0};
int visited[25][25];
int n;
void BFS(int y, int x){
    int count = 0;
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
            if(nx>=0 && nx<n && ny>=0 && ny<n && visited[ny][nx]==1){
                q.push(make_pair(ny,nx));
                visited[ny][nx] = 0;
            }
        }
        count++;
    }
    output.push_back(count);
}
int main()
{
    ios::sync_with_stdio(0);
	cin.tie(0);
    cin >> n;
    for(int i=0;i<n;i++){
        string temp;
        cin >> temp;
        for(int j=0;j<temp.length();j++)
        visited[i][j] = temp.at(j) - '0';
    }
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(visited[i][j]==1)
                BFS(i,j);
            
    sort(output.begin(),output.end());
    cout << output.size() << '\n';
    for(auto i : output)
        cout << i <<'\n';
    return 0;
}