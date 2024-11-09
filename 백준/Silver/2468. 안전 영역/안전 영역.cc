#include <bits/stdc++.h>
using namespace std;

int arr[101][101];
int visited[101][101];
vector<int> parent(101);
int dy[4] = {0,0,1,-1};
int dx[4] = {1,-1,0,0};
int N;
int counts = 1, output=0;
void BFS(int h, int y, int x){
	queue<pair<int,int>> q;
	q.push({y,x});
	visited[y][x] = counts;
	while(!q.empty()){
		pair<int,int> t = q.front();
		q.pop();
		for(int i=0;i<4;i++){
			int nx = t.second + dx[i];
			int ny = t.first + dy[i];
			if(nx < 0 || nx >= N || ny < 0 || ny >=N || visited[ny][nx]>0 || arr[ny][nx]<=h) continue;  
			visited[ny][nx] = counts;
			q.push({ny,nx});
		}
	}
	counts++;
}	

void solution(){
	cin >> N;
	int maxv = 0;
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cin >> arr[i][j];
			maxv = max(maxv, arr[i][j]);
		}
	}
	for(int k=0;k<=100;k++){
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++)
				if(visited[i][j]==0 && arr[i][j]>k){
					BFS(k, i, j);
				}
					
		}
		memset(visited,0,sizeof(visited));
		output = max(output,counts);
		counts = 1;
	}
	
	cout << output-1;
}

int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	solution();
    return 0;
}

