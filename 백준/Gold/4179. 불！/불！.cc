#include <bits/stdc++.h>
using namespace std;
int dy[4] = {0,0,-1,1}; //좌, 우, 상, 하
int dx[4] = {-1,1,0,0};

vector<vector<char>> arr;
vector<vector<bool>> visited_human;
vector<vector<bool>> visited_fire;
int R,C;
struct fire{
	int y,x,cnt;
	bool fire;
};
#define MAX 987654321
void solution(){
	int output = MAX;
	cin >> R >> C;
	arr.resize(R,vector<char>(C));
	visited_fire.resize(R,vector<bool>(C));
	visited_human.resize(R,vector<bool>(C));
	queue<fire> q;
	queue<fire> tq;
	for(int i=0;i<R;i++){
		for(int j=0;j<C;j++){
			cin >> arr[i][j];
			if(arr[i][j]=='J') {
				q.push({i,j,1,false});
				visited_human[i][j] = true;
			}
			else if(arr[i][j]=='F'){
				 tq.push({i,j,0,true});
				 visited_fire[i][j] = true;
			}
		}
	}
	while(!tq.empty()){
		q.push(tq.front());
		tq.pop();
	}
	while(!q.empty()){
		fire now = q.front(); q.pop();
		if(arr[now.y][now.x]=='F' && !now.fire) continue;
		for(int i=0;i<4;i++){
			int ny = now.y + dy[i];
			int nx = now.x + dx[i];
			if(now.fire){
				//불이라면
				if(nx>=0 && ny>=0 && nx<C && ny<R){
					if(arr[ny][nx]=='F' || arr[ny][nx]=='#' || visited_fire[ny][nx]) 
						continue;
					visited_fire[ny][nx] = true;
					arr[ny][nx] = 'F';
					q.push({ny,nx,now.cnt,now.fire});
				}
			}else{
				//불이 아니라면
				if(nx>=0 && ny>=0 && nx<C && ny<R){
					if(arr[ny][nx]=='F' || arr[ny][nx]=='#' || visited_human[ny][nx]) 
						continue;	
					visited_human[ny][nx] = true;
					q.push({ny,nx,now.cnt+1,now.fire});
				}else{
					output = min(output,now.cnt);
				}
			}
		}
	}
	if(output == MAX) cout << "IMPOSSIBLE";
	else cout << output;
}

int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	solution();
    return 0;
}
