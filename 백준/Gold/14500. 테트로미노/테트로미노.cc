#include <bits/stdc++.h>
using namespace std;

int maxv = 0;
int arr[501][501];
bool visited[501][501];

int dy[4] = {0,0,1,-1};
int dx[4] = {1,-1,0,0};
int N, M;
void DFS(int x,int y, int cnt, int value){
	if(cnt==4){
		maxv = max(maxv,value);
		return;
	}
	for(int i=0;i<4;i++){
		int nx = x+dx[i];
		int ny = y+dy[i];
		if(ny<1 || ny>M || nx<1 || nx>N || visited[nx][ny]) continue;
		visited[nx][ny] = true;
		DFS(nx,ny,cnt+1,value+arr[nx][ny]);
		visited[nx][ny] = false;
	}
	if(x-1 >= 1 && y-1 >= 1 && x+1 <= N) { //ㅓ
        maxv = max(maxv, (arr[x-1][y] + arr[x][y-1] + arr[x][y] + arr[x+1][y]));
    }
    if(x-1 >= 1 && y+1 <= M && x+1 <= N) { //ㅏ
        maxv = max(maxv, (arr[x-1][y] + arr[x][y+1] + arr[x][y] + arr[x+1][y]));
    }
    if(y-1 >= 1 && y+1 <= M && x+1 <= N) { //ㅗ
        maxv = max(maxv, (arr[x][y] + arr[x+1][y] + arr[x+1][y-1] + arr[x+1][y+1]));
    }
    if(y-1 >= 1 && y+1 <= M && x+1 <= N) { //ㅜ
        maxv = max(maxv, (arr[x][y-1] + arr[x][y] + arr[x][y+1] + arr[x+1][y]));
    }

}

void solution(){
	
	cin >> N >> M;
	for(int i=1;i<=N;i++){
		for(int j=1;j<=M;j++){
			cin >> arr[i][j];
		}
	}
	for(int i=1;i<=N;i++){
		for(int j=1;j<=M;j++){
			visited[i][j] = true;
			DFS(i,j,1,arr[i][j]);
			visited[i][j] = false;
		}
	}
	cout << maxv;
}

int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	solution();
    return 0;
}