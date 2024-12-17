#include <bits/stdc++.h>
using namespace std;
int dy[12] = {0,0,-1,1,-1,-1,1,1,2,2,-2,-2}; //좌, 우, 상, 하
int dx[12] = {-1,1,0,0,-2,2,-2,2,-1,1,-1,1};

int K, W, H;
int arr[201][201];
int visited[201][201];
struct monkey{
	int y,x,horse,cnt;
};

void solution(){
	int minv = 987654321;
	cin >> K >> W >> H;
	for(int i=0;i<H;i++){
		for(int j=0;j<W;j++){
			cin >> arr[i][j];
			visited[i][j] = -1;
		}
	}
	queue<monkey> q;
	q.push({0,0,K,0});
	visited[0][0] = K;
	while(!q.empty()){
		int nx,ny;
		monkey now = q.front(); q.pop();
		if(now.x == W-1 && now.y == H-1){
			minv = min(minv, now.cnt);
			continue;
		}
		for(int i=0;i<12;i++){
			if(now.horse==0 && i>=4) break;
			int ny = now.y + dy[i];
			int nx = now.x + dx[i];
			if(ny<H && ny>=0 && nx<W && nx>=0 && visited[ny][nx]<now.horse && arr[ny][nx]==0){
				
				if(i>=4){
					q.push({ny,nx,now.horse-1,now.cnt+1});
					visited[ny][nx] = now.horse-1;
				}
				else{
					q.push({ny,nx,now.horse,now.cnt+1});
					visited[ny][nx] = now.horse;
				}
			}
		}

	}
	if(minv == 987654321) cout << -1;
	else
		cout << minv;
}

int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	solution();
    return 0;
}

