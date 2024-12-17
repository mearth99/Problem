#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <string>
using namespace std;

vector<int> outputs;
vector<vector<int>> arr;
int N,cnt;
int dx[8] = {0,0,1,-1,1,1,-1,-1};
int dy[8] = {1,-1,0,0,1,-1,1,-1};
bool check_around(int y, int x){
	for(int i=0;i<8;i++){
		int nx = x + dx[i];
		int ny = y + dy[i];
		if(nx>=0 && nx<N && ny >=0 && ny < N){
			if(arr[ny][nx]==1) return false;
		}
	}
	return true;
}


void BFS(int i, int j){
	queue<pair<int,int>> q;
	q.push({i,j});
	arr[i][j] = 0;
	while(!q.empty()){
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		for(int i=0;i<8;i++){
			int nx = x + dx[i];
			int ny = y + dy[i];
			if(nx>=0 && nx<N && ny >=0 && ny < N){
				if(arr[ny][nx]==-1) {
					arr[ny][nx] = 0;
					if(check_around(ny,nx)) q.push({ny,nx});
				}
			}
		}
	}
}


int main(int argc, char** argv)
{
	freopen("input.txt", "r", stdin);
	freopen("myoutput.txt", "w", stdout);
	int test_case,T;
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case){
		cin >> N;
		cnt=0;
		arr.clear();
		arr.resize(N,vector<int>(N));
		for(int i=0;i<N;i++){
			string temp;
			cin >> temp;
			for(int j=0;j<temp.length();j++){
				if(temp.at(j)=='.') arr[i][j] = -1; 
				else arr[i][j] = 1; 
			}
		}
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				if(check_around(i,j) && arr[i][j]==-1) {
					BFS(i,j);
					cnt++;
				}
			}
		}
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				if(arr[i][j]==-1){
					cnt++;
				}
			}
		}
		outputs.push_back(cnt);
	}
	int a = 1;
	for(auto &it : outputs){
		cout << '#' << a++ << ' ' << it << '\n';
	}

	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}