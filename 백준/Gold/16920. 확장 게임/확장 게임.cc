#include <bits/stdc++.h>
using namespace std;
int dy[4] = {0,0,1,-1};
int dx[4] = {1,-1,0,0};

int arr[1001][1001];

int N, M, P;
int p[10];
int castle[10];
vector<pair<int,int>> p_list[10];


void BFS(){

}

void solution(){
	
	cin >> N >> M >> P;
	for(int i=1;i<=P;i++)
		cin >> p[i];
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			char temp;
			cin >> temp;
			if(temp == '.'){
				arr[i][j] = 0;
			}
			else if(temp=='#'){
				arr[i][j] = -1;
			}
			else{
				arr[i][j] = temp - '0';
				p_list[arr[i][j]].push_back({i,j});
			}
		}		
	}
	bool end = false;
	while(!end){
		int total_cnt = 0;
		for(int player = 1; player<=P; player++){
			for(int i=0; i<p[player]; i++){
				int p_cnt = 0;
				vector<pair<int,int>> nextp_list;
				for(auto it : p_list[player]){
					for(int j=0;j<4;j++){
						int ny = it.first + dy[j];
						int nx = it.second + dx[j];
						if(nx < 0 || ny < 0 || nx >= M || ny >= N) continue;
						if(arr[ny][nx]!=0) continue;
						total_cnt++;
						p_cnt++;
						nextp_list.push_back({ny,nx});
						arr[ny][nx] = player;
					}
				}
				if(p_cnt == 0) break;
				p_list[player] = nextp_list; 
			}
		}
		if(total_cnt == 0) end = true;
	}
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			castle[arr[i][j]]++;
		}
	}

	for(int i=1;i<P;i++){
		cout << castle[i] << ' ';
	}
	cout << castle[P];
}


int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	solution();
    return 0;
}

