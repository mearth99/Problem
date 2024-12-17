#include <bits/stdc++.h>
using namespace std;


int N, M;
int day = -1;
int flag = 0;
vector<vector<char>> arr;
vector<vector<int>> visited;
vector<pair<int,int>> bird(2);
struct space{
	int y,x,type;
};
vector<space> sq;

int dy[4] = {0,0,1,-1};
int dx[4] = {1,-1,0,0};


ofstream file("output.txt");
void outfile(vector<vector<char>> arr){
	if(file.is_open()){
		for(int i=0;i<N;i++){
			for(int j=0;j<M;j++){
				file << arr[i][j] << ' ';
			}
			file << '\n';
		}
	}else{
		cout << "파일 에러.";
		return;
	}
}
void BFS2(){
	day++;
	vector<space> now_sq = sq;
	sq.clear();
	for(auto it: now_sq){
		arr[it.y][it.x] = it.type + '0';
		for(int i=0;i<4;i++){
			int ny = it.y + dy[i];
			int nx = it.x + dx[i];
			if(ny<0 || ny>=N || nx<0 || nx>=M) continue;
			if(arr[ny][nx]=='X' && !visited[ny][nx]){ 
				sq.push_back({ny,nx,it.type});
				visited[ny][nx] = 1;
			}
			if(it.type==0 && arr[ny][nx]=='1') flag = true;
			if(it.type==1 && arr[ny][nx]=='0') flag = true;
		}
	}
	now_sq.clear();
}


void BFS(pair<int,int> bird, int cnt){
	queue<pair<int,int>> q;
	q.push({bird.first,bird.second});
	while(!q.empty()){
		pair<int,int> t = q.front(); q.pop();
		arr[t.first][t.second] = cnt + '0';
		for(int i=0;i<4;i++){
			int ny = t.first + dy[i];
			int nx = t.second + dx[i];
			if(ny<0 || ny>=N || nx<0 || nx>=M) continue;
			if(arr[ny][nx]=='.' && !visited[ny][nx]) {
				q.push({ny,nx});
				visited[ny][nx] = 1;
			}
			if(arr[ny][nx]=='X' && !visited[ny][nx]) {
				sq.push_back({ny,nx,cnt});
				visited[ny][nx] = 1;
			}
			if(cnt==0 && arr[ny][nx]== '1') day = 0;
			if(cnt==1 && arr[ny][nx]== '0') day = 0;
		}
	}	
}
void solution(){
	cin >> N >> M;
	arr.resize(N,vector<char>(M));
	visited.resize(N,vector<int>(M));
	for(int i=0,cnt=0;i<N;i++){
		string str;
		cin >> str;
		for(int j=0;j<M;j++){
			arr[i][j] = str.at(j);
			if(arr[i][j] == 'L'){
				bird[cnt].first = i;
				bird[cnt++].second = j;
			}
		}
	}
	BFS(bird[0],0);
	BFS(bird[1],1);
	if(day==0){
		cout << 0;
		return;
	}
	day = 0;
	while(day<100){
		BFS2();
		if(flag){
			cout << day;
			return;
		}
	}
	outfile(arr);
}

int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	solution();
	file.clear();
    return 0;
}

