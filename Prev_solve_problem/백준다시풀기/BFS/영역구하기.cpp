#include <bits/stdc++.h>
using namespace std;
int dy[4] = {0,0,-1,1}; //좌, 우, 상, 하
int dx[4] = {-1,1,0,0};



void solution(){
	int M,N,K;
	cin >> M >> N >> K;
	vector<vector<int>> arr(M, vector<int>(N,0));
	vector<int> out;
	for(int i=0;i<K;i++){
		int x1,y1,x2,y2;
		cin >> x1 >> y1 >> x2 >> y2;
		for(int j=y1; j<y2;j++){
			for(int k=x1; k<x2;k++){
				arr[j][k] = 1;
			}
		}
	}
	for(int i=0;i<M;i++){
		for(int j=0;j<N;j++){
			if(arr[i][j]==0){
				int cnt=1;
				arr[i][j] = 1;
				queue<pair<int,int>> q;
				q.push({i,j});
				while(!q.empty()){
					pair<int,int> t = q.front(); q.pop();
					for(int k=0;k<4;k++){
						int ny = t.first + dy[k];
						int nx = t.second + dx[k];
						if(ny>=0 && ny<M && nx>=0 && nx<N && arr[ny][nx]==0){
							arr[ny][nx] = 1;
							q.push({i,j});
							cnt++;
						}
					}
				}
				out.push_back(cnt);
			}
		}
	}
	sort(out.begin(),out.end());
	cout << out.size() << '\n';
	for(auto it : out)
		cout << it << ' ';
}

int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	solution();
    return 0;
}

