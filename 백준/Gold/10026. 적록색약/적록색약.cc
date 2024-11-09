#include <bits/stdc++.h>
using namespace std;
int dy[4] = {0,0,-1,1}; //좌, 우, 상, 하
int dx[4] = {-1,1,0,0};
int normal_cnt = 0;
int unique_cnt = 0;
vector<vector<int>> visited;
vector<vector<int>> visited_unique;
vector<vector<char>> arr;
int N;
void BFS(int y, int x, char alp){ // R, G, B  
	queue<pair<int,int>> q;
	q.push({y,x});
	visited[y][x] = 1;
	while(!q.empty()){
		pair<int,int> t = q.front(); q.pop();
		for(int i=0;i<4;i++){
			int ny = t.first + dy[i];
			int nx = t.second + dx[i];
			if(ny<0 || ny >= N || nx<0 || nx>=N || visited[ny][nx] || arr[ny][nx] != alp) continue;
			visited[ny][nx] = 1;
			q.push({ny,nx});
		}
	}
	normal_cnt++;
}
void BFS2(int y, int x, char alp){ // R, G, B  
	queue<pair<int,int>> q;
	q.push({y,x});
	visited_unique[y][x] = 1;
	while(!q.empty()){
		pair<int,int> t = q.front(); q.pop();
		for(int i=0;i<4;i++){
			int ny = t.first + dy[i];
			int nx = t.second + dx[i];
			if(ny<0 || ny >= N || nx<0 || nx>=N || visited_unique[ny][nx]) continue;
			if(alp == 'B' && alp == arr[ny][nx]){
				visited_unique[ny][nx] = 1;
				q.push({ny,nx});
			}else if((alp == 'R' || alp == 'G') && (arr[ny][nx] == 'R' || arr[ny][nx] == 'G')){
				visited_unique[ny][nx] = 1;
				q.push({ny,nx});
			}
		}
	}
	unique_cnt++;
}

void solution(){
	
	cin >> N;
	arr.resize(N,vector<char>(N));
	visited.resize(N,vector<int>(N,0));
	visited_unique.resize(N,vector<int>(N,0));
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cin >> arr[i][j];
		}
	}
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(visited[i][j]==0) BFS(i,j,arr[i][j]);
			if(visited_unique[i][j]==0) BFS2(i,j,arr[i][j]);
		}
	}
	cout << normal_cnt << ' ' << unique_cnt;
}

int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	solution();
    return 0;
}

