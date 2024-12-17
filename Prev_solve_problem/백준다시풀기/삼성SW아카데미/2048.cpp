#include <bits/stdc++.h>
using namespace std;

int dy[4] = {-1,1,0,0}; //상,하,좌,우
int dx[4] = {0,0,-1,1};
int N,mav=0;
struct quzzel{
	int count;
	vector<vector<int>> quz;
};
int acnt = 0;


void BFS(vector<vector<int>> arr){
	queue<quzzel> q;
	q.push({0,arr});
	while(!q.empty()){
		quzzel target = q.front();
		q.pop();
		vector<vector<int>> backup = target.quz;
		if(target.count==6) continue;
		for(int k=0;k<4;k++){
			if(k==0) //상
				for(int i=0;i<N;i++){
					for(int j=0;j<N;j++){
						if(i+dy[k]>=N || i+dy[k]<0 || j+dx[k]>=N || j+dx[k]<0) continue;
						if(target.quz[i+dy[k]][j+dx[k]] == target.quz[i][j] || target.quz[i+dy[k]][j+dx[k]]==0){
							target.quz[i+dy[k]][j+dx[k]] += target.quz[i][j];
							target.quz[i][j] = 0;
							mav = max(mav,target.quz[i+dy[k]][j+dx[k]]);
						}
					}
				}
			else if(k==1)
				for(int i=N;i>=0;i--){
					for(int j=0;j<N;j++){
						if(i+dy[k]>=N || i+dy[k]<0 || j+dx[k]>=N || j+dx[k]<0) continue;
						if(target.quz[i+dy[k]][j+dx[k]] == target.quz[i][j] || target.quz[i+dy[k]][j+dx[k]]==0){
							target.quz[i+dy[k]][j+dx[k]] += target.quz[i][j];
							target.quz[i][j] = 0;
							mav = max(mav,target.quz[i+dy[k]][j+dx[k]]);
						}
					}
				}
			else if(k==2)
				for(int i=0;i<N;i++){
					for(int j=0;j<N;j++){
						if(i+dy[k]>=N || i+dy[k]<0 || j+dx[k]>=N || j+dx[k]<0) continue;
						if(target.quz[i+dy[k]][j+dx[k]] == target.quz[i][j] || target.quz[i+dy[k]][j+dx[k]]==0){
							target.quz[i+dy[k]][j+dx[k]] += target.quz[i][j];
							target.quz[i][j] = 0;
							mav = max(mav,target.quz[i+dy[k]][j+dx[k]]);
						}
					}
				}
			else if(k==3)
				for(int i=0;i<N;i++){
					for(int j=N-2;j>=0;j--){
						if(i+dy[k]>=N || i+dy[k]<0 || j+dx[k]>=N || j+dx[k]<0) continue;
						if(target.quz[i+dy[k]][j+dx[k]] == target.quz[i][j] || target.quz[i+dy[k]][j+dx[k]]==0){
							target.quz[i+dy[k]][j+dx[k]] += target.quz[i][j];
							target.quz[i][j] = 0;
							mav = max(mav,target.quz[i+dy[k]][j+dx[k]]);
						}
					}
				}
			q.push({target.count+1,target.quz});
			target.quz = backup;
		}
	}
}


void solution(){
	cin >> N;
	vector<vector<int>> arr(N,vector<int> (N));
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cin >> arr[i][j];
			mav = max(mav, arr[i][j]);
		}
	}
	BFS(arr);
	cout << mav;
}

int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	solution();
    return 0;
}