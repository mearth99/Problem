#include <bits/stdc++.h>
using namespace std;
int arr[31][31] = {0};
int visited[31][31] = {0};
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
int N,M, star;

void DFS(int sy, int sx, int sum, int levels){	
	int ny,nx,cnt=0;
	if(sum==star){

	}
	for(int i=0;i<4;i++){
		ny = sy;
		nx = sx;
		while(true){
			int nny = ny + dy[i];
			int nnx = nx + dx[i];
			if(nny>=0 && nnx >=0 && nny<N && nnx < M){
				ny = nny;
				nx = nnx;
				if(!visited[ny][nx]) cnt++;
			}else{
				break;
			}
		}
		if(!visited[ny][nx]){
			visited[ny][nx] = 1;
			DFS(ny,nx,sum+cnt,);
		}
	}
}

void solution(){
	star = 0;
	cin >> N >> M;
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			char temp;
			cin >> temp;
			if(temp == '*'){
				arr[i][j] = 0;
			}
			else{
				arr[i][j] = 1;
				star++;
			}
		}
	}

}

int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int T;
	cin >> T;
	while(T--)
		solution();
	// file.clear();
    return 0;
}

