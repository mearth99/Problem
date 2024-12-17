#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <string>
using namespace std;

struct pos{
	int x,y;
};

vector<int> outputs;
vector<pos> customer;
vector<bool> visited;
int N;
int output;
int pairabs(pos a, pos b){
	return abs(a.x - b.x) + abs(a.y - b.y);  
}

void DFS(int prev, int count, int distance){
	if(distance > output) return;
	if(count == N){
		distance += pairabs(customer[1], customer[prev]);
		output = min(output, distance);
		return;
	}
	for(int i=2;i<N+2;i++){
		if(!visited[i]){
			visited[i] = true;
			DFS(i,count+1,distance+pairabs(customer[i], customer[prev]));
			visited[i] = false;
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
		output = 987645312;
		cin >> N;
		customer.resize(N+2);
		visited.resize(N,false);
		for(int i=0;i<N+2;i++){
			cin >> customer[i].x >> customer[i].y;
		}
		DFS(0,0,0);
		outputs.push_back(output);
		customer.clear();
		visited.clear();
	}
	int a = 1;
	for(auto &it : outputs){
		cout << '#' << a++ << ' ' << it << '\n';
	}

	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}