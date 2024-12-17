#include <bits/stdc++.h>
using namespace std;

int maps[101][101];
bool visited[101][101];
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

int uniq = 2;
int N;

struct island{
    int x, y, v;
};

void DFS(int y, int x){
    maps[y][x] = uniq;
    for(int i=0;i<4;i++){
        int nx = dx[i] + x;
        int ny = dy[i] + y;
        if(nx>=0 && nx < N && ny >=0 && ny<N && maps[ny][nx]==1)
            DFS(ny,nx);
    }

}
int BFS(int y, int x){
    int cur_uniq = maps[y][x];
    int result = 987654321;
    queue<island> q;
    q.push({x,y,0});
    visited[y][x] = true;
    while(!q.empty()){
        island c = q.front();
        q.pop();
        if(maps[c.y][c.x] != cur_uniq && maps[c.y][c.x]!=0){
            result = min(c.v,result);
            continue;
        }
        for(int i=0;i<4;i++){
            int nx = dx[i] + c.x;
            int ny = dy[i] + c.y;
            if(visited[ny][nx]) continue;
            visited[ny][nx] = true;
            if(nx>=0 && nx < N && ny >=0 && ny<N && maps[ny][nx]==cur_uniq)
                q.push({nx,ny,c.v});
            else if(nx>=0 && nx < N && ny >=0 && ny<N && maps[ny][nx]==0)
                q.push({nx,ny,c.v+1});
        }
    }
    return result;
}

int main(){
    int value = 99999;
    cin >> N;
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++){
            cin >> maps[i][j];
        }
    
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            if(maps[i][j]==1) {
                DFS(i,j);
                uniq++;
            }
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++){
            if(maps[i][j]!=0 && !visited[i][j])
                value = min(value,BFS(i,j));
        }
    
    cout << value;
    return 0;
}