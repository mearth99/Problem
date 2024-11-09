#include <bits/stdc++.h>
using namespace std;

int forest[501][501];
int DP[501][501];

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

int N, Maxv=0;
int DFS(int y, int x){
    if(DP[y][x]!=-1) return DP[y][x];
    int sum = 1;
    //탐사해야하는 경우
    for(int i=0;i<4;i++){
       int cur = 1;
       int nx = x + dx[i]; 
       int ny = y + dy[i];
       if(nx<N && nx>=0 && ny >=0 && ny < N && forest[y][x] < forest[ny][nx]){
            sum = max(sum, cur + DFS(ny,nx)); 
       } 
    }
    return DP[y][x] = sum;
}


int main(){
    cin >> N;
    memset(DP,-1,sizeof(DP));
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            cin >> forest[i][j];
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            Maxv = max(Maxv,DFS(i,j));
    cout << Maxv;
}