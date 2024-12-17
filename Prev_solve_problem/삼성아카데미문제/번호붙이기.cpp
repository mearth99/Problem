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
vector<int> arr;
bool visited[5001];
int DFS(int cur){
	if(cur==N){
		for(int i=1;i<=N;i++){
			if(visited[i]) continue;
			if(arr[cur]==i) continue;
				return 1;
		}
		return 0;
	}
	int sum = 0;
	for(int i=1;i<=N;i++){
		if(visited[i]) continue;
		if(arr[cur]==i) continue;
		visited[i] = true;
		sum = (sum + DFS(cur+1)) % 1000000007;
		visited[i] = false;
	}
	return sum;
}
int main(int argc, char** argv)
{
	freopen("input.txt", "r", stdin);
	freopen("myoutput.txt", "w", stdout);
	int test_case,T;
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case){
		memset(visited,false,sizeof(visited));
		cin >> N;
		arr.resize(N+1);
		for(int i=1;i<=N;i++){
			cin >> arr[i];
		}
		outputs.push_back(DFS(1));
		arr.clear();
	}
	int a = 1;
	for(auto &it : outputs){
		cout << '#' << a++ << ' ' << it << '\n';
	}

	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}