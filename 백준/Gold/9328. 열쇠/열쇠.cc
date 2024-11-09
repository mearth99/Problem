#include <bits/stdc++.h>
using namespace std;
int dy[4] = {0,0,1,-1};
int dx[4] = {1,-1,0,0};

bool alpabet[26];
queue<pair<int,int>> door[26];

void set_bfs(int i, int j, vector<vector<bool>> &visited, vector<vector<char>> &arr, queue<pair<int,int>> &q, int &document){
	if(arr[i][j]=='.') {
		q.push({i,j});
		visited[i][j] = true;
	}
	else if('A'<= arr[i][j] && arr[i][j]<='Z'){
		if(alpabet[arr[i][j]-'A']){
			q.push({i,j});
			visited[i][j] = true;
		}
		else{
			door[arr[i][j]-'A'].push({i,j});
		}
	}
	else if('a'<= arr[i][j] && arr[i][j]<='z'){
		alpabet[arr[i][j]-'a'] = true;
		q.push({i,j});
		visited[i][j] = true;
		while(!door[arr[i][j]-'a'].empty()){
			pair<int,int> now = door[arr[i][j]-'a'].front(); door[arr[i][j]-'a'].pop();
			q.push(now);
			visited[now.first][now.second] = true;
		}
	}
	else if(arr[i][j]=='$'){
		q.push({i,j});
		visited[i][j] = true;
		document++;
	}
}

void execute(){
	int h,w,document=0;
	cin >> h >> w;
	vector<vector<char>> arr(h, vector<char>(w));
	vector<vector<bool>> visited(h,vector<bool>(w));
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			cin >> arr[i][j];
		}
	}
	string key;
	cin >> key;
	for(auto it : key){
		if(it == '0') break;
		alpabet[it-'a'] = true;
	}
	queue<pair<int,int>> q;
	for(int i=1;i<w-1;i++){
		set_bfs(0,i,visited,arr,q,document);
		set_bfs(h-1,i,visited,arr,q,document);
	}
	for(int i=0;i<h;i++){
		set_bfs(i,0,visited,arr,q,document);
		set_bfs(i,w-1,visited,arr,q,document);
	}
	while(!q.empty()){
		pair<int,int> now = q.front(); q.pop();
		for(int i=0;i<4;i++){
			int ny = now.first + dy[i];
			int nx = now.second + dx[i];
			if(ny>=0 && ny<h && nx>=0 && nx<w && !visited[ny][nx]){
				set_bfs(ny,nx,visited,arr,q,document);
			}
		}
	}
	cout << document << '\n';
}


void solution(){
	int testcase;
	cin >> testcase;
	while(testcase-->0){
		execute();
		for(int reset = 0; reset<26; reset++){
			alpabet[reset] = false;
			while(!door[reset].empty()){
				door[reset].pop();
			}
		}
	}
}


int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	solution();
    return 0;
}

