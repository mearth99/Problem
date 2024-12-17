#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <string>
using namespace std;
int N;
vector<int> outputs;
vector<vector<int>> arr;
vector<vector<bool>> visited;
vector<pair<int,int>> professor;
pair<int,int> output; // 갯수, 길이

int dy[4] = {-1,1,0,0}; // 상 하 좌 우 
int dx[4] = {0,0,-1,1};

bool check(pair<int,int> profe, int dir){
	int y = profe.first, x = profe.second;
	while(true){
		int ny = y + dy[dir];
		int nx = x + dx[dir];
		if(visited[ny][nx]) return false;
		if(ny==0 || nx == 0 || ny==N-1 || nx == N-1) return true;
		y = ny;
		x = nx;
	}
}
int resize(pair<int,int> profe, int dir){
	int leg = 0;
	int y = profe.first, x = profe.second;
	while(true){
		int ny = y + dy[dir];
		int nx = x + dx[dir];
		if(ny==N || nx==N || ny<0 || nx<0){
			break;
		}
		visited[ny][nx] = true;
		leg++;
		y = ny;
		x = nx;
	}
	return leg;
}
void reset(pair<int,int> profe, int dir){
	int y = profe.first, x = profe.second;
	while(true){
		int ny = y + dy[dir];
		int nx = x + dx[dir];
		if(ny==N || nx==N || ny<0 || nx<0){
			break;
		}
		if(!arr[ny][nx]) //arr[ny][nx]==1 인 곳은 professor이다.
			visited[ny][nx] = false;
		y = ny;
		x = nx;
	}
}
void DFS(int cur, int pro_count, int length){
	if(cur == professor.size()){
		if(output.first < pro_count){
			output.first = pro_count;
			output.second = length;
		}else if(output.first == pro_count && output.second > length){
			output.second = length;
		}
		return;
	}
	for(int i=0;i<4;i++){ //상하좌우
		//시작지점에서 i방향에 따라 벽에 도달할 수 있는지 파악한다. 전선, 프로페서로 도달못하면 0, 도달시 1
		if(check(professor[cur],i)==0) continue;
		//이방향에 따라 도달할 수 있다면 visited를 전부 1로 표시한다. + 길이 파악
		int leg = resize(professor[cur],i);
		DFS(cur+1, pro_count+1, length + leg);
		//DFS탐색에 따라 다시 visited를 전부 0로 표시한다.
		reset(professor[cur],i); 
	}
	//어떠한 경우에도 선택할 수 없다면, 이 프로세서는 제외하고 다음 프로세서로 넘어간다.
	DFS(cur+1,pro_count,length); 
}
int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
  	cin.tie(NULL);
	cout.tie(NULL);	
	freopen("input.txt", "r", stdin);
	freopen("myoutput.txt", "w", stdout);
	int test_case,T;
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case){
		output = {0,0};
		cin >> N;
		arr.resize(N,vector<int>(N));
		visited.resize(N,vector<bool>(N,0));
		
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				cin >> arr[i][j];
				if(arr[i][j]) {
					if(i!=0 && j!=0 && i!=N-1 && j!=N-1)
						professor.push_back({i,j});
					visited[i][j] = true;
				}
			}
		}
		DFS(0,0,0);
		outputs.push_back(output.second);
		professor.clear();
		arr.clear();
		visited.clear();
	}
	int a = 1;
	for(auto &it : outputs){
		cout << '#' << a++ << ' ' << it << '\n';
	}

	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}