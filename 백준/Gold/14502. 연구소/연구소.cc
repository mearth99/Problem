#include <bits/stdc++.h>
using namespace std;

queue<pair<int,int>> virus;
vector<vector<int>> arr;
vector<vector<bool>> visited;
int N, M,maxv=0,safe_room=-3;
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};

int BFS(){
	queue<pair<int,int>> v = virus;
	vector<vector<int>> now_arr = arr;
	int now_safe_room = safe_room;
	while(!v.empty()){
		pair<int,int> target = v.front();
		v.pop();
		for(int i=0;i<4;i++){
			int nx = dx[i] + target.first;
			int ny = dy[i] + target.second;
			if(nx>=0 && ny>=0 && nx<N && ny<M && now_arr[nx][ny]==0){
				now_safe_room--;
				now_arr[nx][ny] = 2;
				v.push({nx,ny});
			}
		}

	}
	return now_safe_room;
}
void DFS(int cnt){
	if(cnt==3){
		maxv=max(maxv,BFS());
		return;
	}
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			if(arr[i][j]==0){
				arr[i][j] = 1;
				DFS(cnt+1);
				arr[i][j] = 0;
			}
		}
	}

}

void solution(){
	cin >> N >> M;
	arr.resize(N, vector<int>(M));
	visited.resize(N, vector<bool>(M));

	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			cin >> arr[i][j];
			if(arr[i][j]==2) virus.push({i,j});
			if(arr[i][j]==0) safe_room++;  
		}
	}
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			if(arr[i][j]==0){
				arr[i][j] = 1;
				DFS(1);
				arr[i][j] = 0;
			}
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