#include <bits/stdc++.h>
using namespace std;

/*
N×M의 행렬로 표현되는 맵이 있다. 맵에서 0은 이동할 수 있는 곳을 나타내고, 1은 이동할 수 없는 벽이 있는 곳을 나타낸다. 당신은 (1, 1)에서 (N, M)의 위치까지 이동하려 하는데, 이때 최단 경로로 이동하려 한다. 최단경로는 맵에서 가장 적은 개수의 칸을 지나는 경로를 말하는데, 이때 시작하는 칸과 끝나는 칸도 포함해서 센다.

만약에 이동하는 도중에 벽을 부수고 이동하는 것이 좀 더 경로가 짧아진다면, 벽을 K개 까지 부수고 이동하여도 된다.

한 칸에서 이동할 수 있는 칸은 상하좌우로 인접한 칸이다.

맵이 주어졌을 때, 최단 경로를 구해 내는 프로그램을 작성하시오.
*/
vector<vector<int>> arr;
vector<vector<int>> visited;
int N, M, K,output=987654321;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};


struct wall{
    int x, y, dis, can_K;
};

void BFS(){
    queue<wall> q;
    q.push({0,0,1,K});
    visited[0][0] = K;
    while(!q.empty()){
        int x = q.front().x;
        int y = q.front().y;
        int dis = q.front().dis;
        int can_K = q.front().can_K; q.pop();
        if(x==M-1 && y == N-1){
            output = min(dis,output);
            continue;
        }
        for(int i=0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx >=0 && nx < M && ny >=0 && ny<N){
                if(arr[ny][nx]==0 && visited[ny][nx] < can_K){
                    visited[ny][nx] = can_K;
                    q.push({nx,ny,dis+1,can_K});
                }
                if(arr[ny][nx]==1 && can_K > 0 && visited[ny][nx] < can_K-1){
                    visited[ny][nx] = can_K-1;
                    q.push({nx,ny,dis+1,can_K-1});
                }
            }
        }
    }
}

int main(){
    cin >> N >> M >> K;
    arr.resize(N,vector<int>(M));
    visited.resize(N,vector<int>(M,-1));
    for(int i=0;i<N;i++){
        string temp;
        cin >> temp;
        for(int j=0;j<temp.length();j++){
            arr[i][j] = temp.at(j) - '0';
        }
    }
    BFS();
    if(output == 987654321) cout << -1;
    else cout << output;
    return 0;
}