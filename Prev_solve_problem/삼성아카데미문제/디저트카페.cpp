#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <string>
using namespace std;

vector<int> outputs;
int N;
vector<vector<int>> arr;
bool dessert[101];
int four[4] = {0};
int dx[4] = {1,1,-1,-1};  //우하, 우상, 좌하, 좌상  // 우하 -> 좌상과 대칭 우상 -> 좌하와 대칭 즉, 0 : 3 , 1: 2
int dy[4] = {-1,1,-1,1};
int maxv = 0;
void DFS(int y, int x, int length, int start_y, int start_x){
	for(int i=0;i<4;i++){
		int ny = y + dy[i];
		int nx = x + dx[i];
		if(ny<N && ny>=0 && nx<N && nx>=0){
			if(ny == start_y && nx == start_x && four[0] == four[3] && four[1]==four[2]){
				maxv = max(length,maxv);
			}
			if(!dessert[arr[ny][nx]]){
				four[i]++;
				dessert[arr[ny][nx]] = true;
				DFS(ny,nx,length+1,start_y,start_x);
				four[i]--;
				dessert[arr[ny][nx]] = false;
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
		maxv = 0;
		cin >> N;
		arr.resize(N,vector<int>(N));
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				cin >> arr[i][j];
			}
		}
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				dessert[arr[i][j]] = true;
				DFS(i,j,0,i,j);
				dessert[arr[i][j]] = false;
			}
		}
		outputs.push_back(maxv);
		arr.clear();
	}
	int a = 1;
	for(auto &it : outputs){
		cout << '#' << a++ << ' ' << it << '\n';
	}

	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}