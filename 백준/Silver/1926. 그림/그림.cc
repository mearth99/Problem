#include <bits/stdc++.h>
using namespace std;
int dy[4] = {0,0,-1,1};
int dx[4] = {-1,1,0,0};

int N,M;
vector<vector<int>> arr;
vector<vector<bool>> visited;

void solution(){
	int maxv = 0;
	int var = 0;
	int cnt = 0;
	cin >> N >> M;
	arr.resize(N, vector<int>(M));
	visited.resize(N, vector<bool>(M));
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++)
			cin >> arr[i][j];
	}
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			if(arr[i][j]==1 && !visited[i][j]){
				cnt = 1;
				var++;
				visited[i][j] = 1;
				queue<pair<int,int>> q;
				q.push({i,j});
				while(!q.empty()){
					int y = q.front().first;
					int x = q.front().second;
					q.pop();
					for(int k=0;k<4;k++){
						int ny = y+dy[k];
						int nx = x+dx[k];
						if(ny>=0 && ny<N && nx>=0 && nx<M && visited[ny][nx]==0 && arr[ny][nx]==1){
							visited[ny][nx] = 1;
							q.push({ny,nx});
							cnt++;
						}
					}
				}
			}
			maxv = max(cnt,maxv);
		}
	}
	cout << var << endl;
	cout << maxv;
}

int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	solution();
    return 0;
}

