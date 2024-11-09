#include <bits/stdc++.h>
using namespace std;
int N,M;
int dy[4] = {0,0,-1,1};
int dx[4] = {-1,1,0,0};
vector<vector<int>> arr;
#include <bits/stdc++.h>
using namespace std;



void iceleck(){
	vector<vector<int>> arr_back = arr;
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			if(arr[i][j]==0) continue;
			for(int k=0;k<4;k++){
				int ny = i+dy[k];
				int nx = j+dx[k]; 
				if(ny>=N || ny<0 || nx>=M || nx<0){
					if(arr_back[i][j]!=0)
						arr_back[i][j]--;
				} else if(arr[ny][nx]==0) 
					if(arr_back[i][j]!=0)
						arr_back[i][j]--;
			}
		}
	}
	arr = arr_back;
}
int check(){
	int check_idx = 0;
	vector<vector<int>> temp(N,vector<int>(M,1));
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			if(arr[i][j]>0 && temp[i][j]){
				temp[i][j] = 0;
				queue<pair<int,int>> q;
				q.push({i,j});
				while(!q.empty()){
					pair<int,int> t = q.front(); q.pop();
					for(int i=0;i<4;i++){
						int ny = t.first+dy[i];
						int nx = t.second+dx[i];
						if(ny<N && ny>=0 && nx<M && nx>=0 && temp[ny][nx] && arr[ny][nx]>0){
							temp[ny][nx] = 0;
							q.push({ny,nx});
						}
					}
				}
				check_idx++;
			}
		}
	}
	return check_idx;
}

void solution(){
	int maxv = 0;
	bool flag = false;
	cin >> N >> M;
	arr.resize(N, vector<int>(M,0));
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			cin >> arr[i][j];
			maxv = max(maxv, arr[i][j]);
		}
	}
	int time = 0;
	while(true){
		if(check()>=2){
			cout << time;
			flag = true;
			break;
		}
		if(check()==0){
			cout << 0;
			break;
		}
		time++;
		iceleck();
	}
	
}

int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	solution();
    return 0;
}

