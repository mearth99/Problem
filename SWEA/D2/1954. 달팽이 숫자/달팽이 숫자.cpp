#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <string>
using namespace std;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int d=0;
vector<vector<int>> arr;
pair<int,int> direct(int N, int y, int x){
	int nx = x + dx[d];
	int ny = y + dy[d];
	if(nx<N && nx>=0 && ny<N && ny>=0 && arr[ny][nx]==0){
		return {ny,nx};
	}else{
		d++;
		if(d==4) d=0;
		return direct(N,y,x);
	}
}

void Go(int N){
	//오른쪽, 아래, 왼쪽, 위 반복
	pair<int,int> cur;
	cur.first = 0, cur.second = 0;
	int count=1;
	while(1){
		arr[cur.first][cur.second] = count++;
		if(count >= N*N+1) break;
		cur = direct(N,cur.first,cur.second);
	}
}

int main(int argc, char** argv)
{
	int test_case,T;
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case){
		int N;
		cin >> N;
		arr.resize(N, vector<int>(N,0));
		Go(N);
		cout << '#' << test_case << '\n';
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++)
				cout << arr[i][j] << ' ';
			cout << '\n';
		}
		arr.clear();
	}
	
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}