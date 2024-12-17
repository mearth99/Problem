#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <string>
using namespace std;
struct tun{
	int y,x,limit;
};

vector<int> outputs;
vector<vector<int>> arr;
vector<vector<bool>> visited;
int N,M,R,C,L;

int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0,}; //상, 하, 좌, 우

vector<vector<int>> tunnel = {{-999},{0,1,2,3},{0,1},{2,3},{0,3},{1,3},{1,2},{0,2}};
bool tunnel_can(pair<int,int> start, pair<int,int> end){
	bool start_flag = false, end_flag = false;
	for(auto it : tunnel[arr[start.first][start.second]]){
		if(start.first + dy[it] == end.first && start.second + dx[it] == end.second)
			start_flag = true;
	}
	for(auto it : tunnel[arr[end.first][end.second]]){
		if(end.first + dy[it] == start.first && end.second + dx[it] == start.second)
			end_flag = true;
	}
	if(start_flag && end_flag) return true;
	return false;
}
int BFS(int y,int x, int limit){
	int count = 1;
	queue<tun> q;
	q.push({y,x,limit});
	visited[y][x] = limit;
	while(!q.empty()){
		tun cur = q.front(); q.pop();
		if(cur.limit==1) continue;
		for(auto it : tunnel[arr[cur.y][cur.x]]){
			int ny = cur.y + dy[it];
			int nx = cur.x + dx[it];
			if(ny>=0 && ny<N && nx>=0 && nx<M && arr[ny][nx]!=0 && tunnel_can({cur.y,cur.x},{ny,nx}) && !visited[ny][nx]){
				count++;
				visited[ny][nx]=true;
				q.push({ny,nx,cur.limit-1});
			}
		}
	}
	return count;
}

int main(int argc, char** argv)
{
	freopen("input.txt", "r", stdin);
	freopen("myoutput.txt", "w", stdout);
	int test_case,T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case){
		cin >> N >> M >> R >> C >> L;
		arr.resize(N,vector<int>(M));
		visited.resize(N,vector<bool>(M,0));
		for(int i=0;i<N;i++){
			for(int j=0;j<M;j++){
				cin >> arr[i][j];
			}
		}
		outputs.push_back(BFS(R,C,L));
		arr.clear();
		visited.clear();
	}
	int a = 1;
	for(auto &it : outputs){
		cout << '#' << a++ << ' ' << it << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}