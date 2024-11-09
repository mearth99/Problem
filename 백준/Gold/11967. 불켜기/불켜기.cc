#include <bits/stdc++.h>
using namespace std;
int dy[4] = {0,0,1,-1};
int dx[4] = {1,-1,0,0};

int arr[101][101];
int visited[101][101];
vector<pair<int,int>> light[101][101];
int N, M;


void solution(){
	int light_room = 1;
	cin >> N >> M;
	for(int i=0;i<M;i++){
		int x, y, a, b;
		cin >> x >> y >> a >> b;
		light[y][x].push_back({b,a});
	}
	queue<pair<int,int>> q;
	q.push({1,1});
	visited[1][1] = true;
	arr[1][1] = 1;
	while(!q.empty()){
		pair<int,int> now =  q.front(); q.pop();
		for(auto it : light[now.first][now.second]){
			if(arr[it.first][it.second]==0){
				arr[it.first][it.second] = 1;
				light_room++;
				bool flag = false;
				for(int i=0;i<4;i++){
					int ny = it.first + dy[i];
					int nx = it.second + dx[i];
					if(ny>=1 && nx >=1 && ny<=N && nx<=N && visited[ny][nx]==1 && visited[it.first][it.second]==0){
						visited[it.first][it.second] = 1;
						q.push({it.first,it.second});
					}
				}
			}
		}
		for(int i=0;i<4;i++){
			int ny = now.first + dy[i];
			int nx = now.second + dx[i];
			if(ny>=1 && nx >=1 && ny<=N && nx<=N && arr[ny][nx]==1 && !visited[ny][nx]){
				q.push({ny,nx});
				visited[ny][nx] = 1;
			}
		}
	}
	cout << light_room;
}


int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	solution();
    return 0;
}

