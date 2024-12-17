#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <string>
using namespace std;

vector<int> outputs;

vector<int> graph[101];
bool visited[101];

void BFS(){
	queue<int> q;
	q.push(0);
	visited[0] = true;
	while(!q.empty()){
		int cur = q.front();
		q.pop();
		for(int it : graph[cur]){
			if(!visited[it]){
				visited[it] = true;
				q.push(it);
			}
		}
	}
}

int main(int argc, char** argv)
{
	freopen("input.txt", "r", stdin);
	freopen("myoutput.txt", "w", stdout);
	int test_case,T;

	for(test_case = 1; test_case <= 10; ++test_case){
		int N;
		cin>> T >> N;
		memset(visited, 0, sizeof(visited));
		for(int i=0;i<N;i++){
			int from, to;
			cin >> from >> to;
			graph[from].push_back(to);
		}
		BFS();
		if(visited[99]) outputs.push_back(1);
		else outputs.push_back(0);
		for(int i=0;i<101;i++) graph[i].clear();
		graph->clear();
	}
	int a = 1;
	for(int i=0;i<outputs.size();i++){
		if(i!=outputs.size()-1)
			cout << '#' << a++ << ' ' << outputs[i] << '\n';
		else
			cout << '#' << a++ << ' ' << outputs[i];
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}