#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <string>
using namespace std;

vector<int> outputs;
vector<vector<char>> arr;
vector<vector<bool>> visited;
vector<pair<int,int>> demon;
int N, M;
int sx,sy,ex,ey;

struct pos{
	int x,y,cnt;
	bool flag;
};

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

bool BFS(){
	queue<pos> q;
	q.push({sx,sy,0,true});
	for(int i=0;i<demon.size();i++){
		q.push({demon[i].second, demon[i].first,0,false});
	}
	while(!q.empty()){
		pos cur = q.front();
		q.pop();
		if(!cur.flag){
			//만약 악마가 영토를 넓힌다면.
			//현재 위치를 악마로 바꾸고, 상하좌우를 큐에 다시 넣는다.
			arr[cur.y][cur.x] = '*';
			for(int i=0;i<4;i++){
				int nx = cur.x + dx[i];
				int ny = cur.y + dy[i];
				if(nx>=0 && nx<M && ny >=0 && ny<N && (arr[ny][nx]=='.' || arr[ny][nx]=='S')){
					q.push({nx,ny,0,false});
				}
			}
		}
		else{
			//수연이가 움직인다면, 목적지에 도달했는지 체크한다.
			if(cur.x == ex && cur.y == ey){
				outputs.push_back(cur.cnt);
				return true;
			}
			if(arr[cur.y][cur.x]=='*') continue;
			for(int i=0;i<4;i++){
				int nx = cur.x + dx[i];
				int ny = cur.y + dy[i];
				if(nx>=0 && nx<M && ny >=0 && ny<N && (arr[ny][nx]=='.' || arr[ny][nx]=='D') && !visited[ny][nx]){
					visited[ny][nx] = true;
					q.push({nx,ny,cur.cnt+1,true});
				}
			}
		}
	}
	return false;
}
int main(int argc, char** argv)
{
	freopen("input.txt", "r", stdin);
	freopen("myoutput.txt", "w", stdout);
	int test_case,T;
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case){
		
		cin >> N >> M;
		arr.resize(N,vector<char>(M));
		visited.resize(N,vector<bool>(M,false));
		for(int i=0;i<N;i++){
			for(int j=0;j<M;j++){
				cin >> arr[i][j];
				if(arr[i][j]=='S'){
					sx = j;
					sy = i;
				}
				else if(arr[i][j]=='D'){
					ex = j;
					ey = i;
				}else if(arr[i][j]=='*'){
					demon.push_back({i,j});
				}
			}
		}
		if(!BFS()) outputs.push_back(-1);
		demon.clear();
		arr.clear();
		visited.clear();
	}
	
	int a = 1;
	for(auto &it : outputs){
		if(it!=-1)
			cout << '#' << a++ << ' ' << it << '\n';
		else
			cout << '#' << a++ << ' ' << "GAME OVER" << '\n';
	}

	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}