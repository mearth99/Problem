#include <bits/stdc++.h>
using namespace std;


int dz[6] = {-1,1,0,0,0,0};
int dy[6] = {0,0,-1,1,0,0};
int dx[6] = {0,0,0,0,-1,1};
bool flag = true;
struct building{
	int z,y,x,time;
};

void solution(){
	int L, R, C;
	cin >> L >> R >> C;

	if(!L&&!R&&!C){
		flag = false;
		return;
	}

	char arr[31][31][31] = {0};
	bool visited[31][31][31] = {0};
	int minv = INT32_MAX;
	queue<building> q;

	for(int i=0;i<L;i++){
		for(int j=0;j<R;j++){
			for(int k=0;k<C;k++){
				cin >> arr[i][j][k];
				if(arr[i][j][k]=='S'){
					q.push({i,j,k,0});
					visited[i][j][k] = 1;
				}
			}
		}
	}


	while(!q.empty()){
		building now = q.front(); q.pop();
		if(arr[now.z][now.y][now.x]=='E'){
			minv = min(minv, now.time);
			continue;
		}
		for(int i=0;i<6;i++){
			int nz = now.z + dz[i];
			int ny = now.y + dy[i];
			int nx = now.x + dx[i];
			if(nz<L && nz>=0 && ny < R && ny>=0 && nx<C && nx>=0 && visited[nz][ny][nx]==0 && arr[nz][ny][nx]!='#'){
				visited[nz][ny][nx] = 1;
				q.push({nz,ny,nx,now.time+1});
			}
		}
	}
	if(minv == INT32_MAX){
		cout << "Trapped!\n";
	}else{
		cout << "Escaped in " << minv << " minute(s).\n";
	}
}

int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	while(flag)
		solution();
    return 0;
}

