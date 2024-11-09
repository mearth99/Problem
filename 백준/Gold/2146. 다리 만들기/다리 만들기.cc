#include <bits/stdc++.h>
using namespace std;
#define MAX 101
int arr[MAX][MAX] = {0};
bool visited[MAX][MAX] = {0};
int N;
vector<pair<int,int>> outside;
int dy[4] = {1,-1,0,0};
int dx[4] = {0,0,1,-1};
int minv = INT32_MAX;

struct island{
	int y,x,cnt;
};

void BFS(int cy,int cx){
	queue<island> q;
	int region = arr[cy][cx];
	visited[cy][cx] = true;
	q.push({cy,cx,0});
	while(!q.empty()){
		island now = q.front(); q.pop();
		for(int i=0;i<4;i++){
			int ny = now.y + dy[i];
			int nx = now.x + dx[i];
			if(ny>=0 && nx >=0 && nx<N && ny<N && !visited[ny][nx] && arr[ny][nx]!=region){
				if(arr[ny][nx]==0){
					visited[ny][nx] = 1;
					q.push({ny,nx,now.cnt+1});
				}else{
					minv = min(minv, now.cnt);
					return;
				}

			}
		}
	}

}
void solution(){
	int region_cnt = 2;
	cin >> N;
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cin >> arr[i][j];
		}
	}	
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(arr[i][j]==1){
				queue<pair<int,int>> q;
				q.push({i,j});
				arr[i][j] = region_cnt;
				while(!q.empty()){
					pair<int,int> now = q.front(); q.pop();
					for(int i=0;i<4;i++){
						int ny = now.first + dy[i];
						int nx = now.second + dx[i];
						if(ny>=0 && ny<N && nx>=0 && nx<N && arr[ny][nx]==1){
							arr[ny][nx] = region_cnt;
							q.push({ny,nx});
						}
						if(ny>=0 && ny<N && nx>=0 && nx<N && arr[ny][nx]==0 && visited[now.first][now.second]==0){
							visited[now.first][now.second]=1;
							outside.push_back({now.first,now.second});
						}
					}
				}
				region_cnt++;
			}
		}
	}
	
	for(auto it : outside){
		memset(visited, 0, sizeof(visited));
		BFS(it.first,it.second);
	}
	cout << minv;
}

int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	solution();
    return 0;
}

