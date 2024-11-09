#include <bits/stdc++.h>
using namespace std;
#define MAX 1001
int arr[MAX][MAX] = {0};
bool visited[MAX][MAX][11] = {0};
int N,M,K;

int dy[4] = {1,-1,0,0};
int dx[4] = {0,0,1,-1};

struct moves{
	int y,x,k,sun,cnt;
};

void solution(){
	int minv = INT32_MAX;
	cin >> N >> M >> K;
	for(int i=0;i<N;i++){
		string temp;
		cin >> temp;
		for(int j=0;j<temp.size();j++){
			arr[i][j] = temp.at(j)-'0';
		}
	}
	queue<moves> q;
	q.push({0,0,K,1,1});
	visited[0][0][1] = true;
	
	while(!q.empty()){
		moves now = q.front(); q.pop();
		if(now.y == N-1 && now.x == M-1){
			minv = min(minv, now.cnt);
			break;
		}
		bool next = (now.sun+1)%2; 
		for(int i=0;i<4;i++){
			int ny = now.y + dy[i];
			int nx = now.x + dx[i];
			if(ny<0 || ny >= N || nx<0 || nx>=M || visited[ny][nx][now.k]) continue;
			if(arr[ny][nx]==0){
				visited[ny][nx][now.k] = true;
				q.push({ny,nx,now.k,next,now.cnt+1});
			}
			if(arr[ny][nx]==1 && now.k>0)
				if(now.sun==1){
					visited[ny][nx][now.k] = true;
					q.push({ny,nx,now.k-1,next,now.cnt+1});
				}else{
					q.push({now.y,now.x,now.k,next,now.cnt+1});
				}
			}
		}
	if(minv == INT32_MAX)
		cout << -1;
	else
		cout << minv;
}

int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	solution();
    return 0;
}

