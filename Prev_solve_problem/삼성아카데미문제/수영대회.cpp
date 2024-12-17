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

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int output = 0;
void DFS(int N, pair<int,int> cur, pair<int,int> dest, int times, int move){
	if(cur.first == dest.first && cur.second == dest.second){

	}
}

int main(int argc, char** argv)
{
	freopen("/mnt/c/Users/dlwls/Downloads/input.txt", "r", stdin);
	freopen("/mnt/c/Users/dlwls/Downloads/myoutput.txt", "w", stdout);
	int test_case,T;
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case){
		int N;
		output = 0;
		pair<int,int> start, dest;
		cin >> N;
		arr.resize(N,vector<int>(N));
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++)
				cin >> arr[i][j];
		}
		cin >> start.first >> start.second;
		cin >> dest.first >> dest.second;
	}
	int a = 0;
	for(auto it : outputs)
		cout << '#' << a++ << ' ' << it << '\n';
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}