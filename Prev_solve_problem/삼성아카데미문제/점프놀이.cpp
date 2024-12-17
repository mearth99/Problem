#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <string>
using namespace std;

vector<int> outputs;
vector<vector<pair<int,int>>> arr;
vector<vector<int>> DP;

int N, K;

int DFS(int number, int y, int x){
	if(DP[y][x]!=-1) return DP[y][x];
	if(number==K) return 0;
	

	DP[y][x] = 987654321;
	for(auto it: arr[number+1]){
		int sum = 0;
		sum = abs(y - it.first) + abs(x - it.second) + DFS(number+1,it.first,it.second);
		DP[y][x] = min(DP[y][x],sum);
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
		int value=987654321;
		cin >> N >> K;
		DP.resize(N,vector<int>(N,-1));
		arr.resize(N*N+1);
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				int number;
				cin >> number;
				arr[number].push_back({i,j});
			}
		}
		for(auto it: arr[1]){
			int v = DFS(1,it.first,it.second);
			value = min(v,value);
		}
		if(value != 987654321)
			outputs.push_back(value);
		else 
			outputs.push_back(-1);
		for(int i=0;i<N;i++)
			DP[i].clear();
		DP.clear();
		arr.clear();
	}	
	int a = 1;
	for(auto &it : outputs){
		cout << '#' << a++ << ' ' << it << '\n';
	}

	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}