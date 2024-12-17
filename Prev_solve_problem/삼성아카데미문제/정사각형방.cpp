#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <string>
using namespace std;

/*
	한방에 접근할 수 있는데, 그 방에 값이 이미 있다면, 그 방에서 얻을 수 있는 최고 값을 구할 수 있기 때문에
	반복할 필요가 없다.

*/

vector<pair<int,int>> outputs;
int N;
int arr[1001][1001];
int DP[1001][1001];
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

int DFS(int y, int x){
	if(DP[y][x] != -1) return DP[y][x];

	DP[y][x] = 1;
	for(int i=0;i<4;i++){
		int nx = x + dx[i];
		int ny = y + dy[i];
		if(nx>=0 && nx<N && ny>=0 && ny<N && arr[y][x]+1 == arr[ny][nx]){
			DP[y][x] += DFS(ny,nx);
		}
	}
	return DP[y][x];
}

int main(int argc, char** argv)
{
	freopen("input.txt", "r", stdin);
	freopen("myoutput.txt", "w", stdout);
	int test_case,T;
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case){
		memset(arr, 0, sizeof(arr));
		memset(DP, -1, sizeof(DP));
		cin >> N;
		int output = 0, position=-1;
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				cin >> arr[i][j]; 
			}
		}
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				int target = DFS(i,j);
				if(target > output){
					output = target;
					position = arr[i][j];
				}else if(target == output){
					position = min(position, arr[i][j]);
				}
			}
		}
		outputs.push_back({position,output});
	}
	int a = 1;
	for(auto &it : outputs){
		cout << '#' << a++ << ' ' << it.first << ' '<< it.second << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}