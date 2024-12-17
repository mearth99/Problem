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
int visited[101];

int BFS(int start){
	int maxheight = 0;
	queue<pair<int,int>> q;
	q.push({start,1});
	visited[start] = 1;
	while(!q.empty()){
		int cur = q.front().first;
		int cnt = q.front().second;
		q.pop();
		for(int it : graph[cur]){
			if(visited[it]==0){
				visited[it] = cnt+1;
				maxheight = max(maxheight,cnt+1);
				q.push({it,cnt+1});
			}
		}
	}
	return maxheight;
}

int main(int argc, char** argv)
{
	freopen("input.txt", "r", stdin);
	freopen("myoutput.txt", "w", stdout);
	int test_case,T;

	for(test_case = 1; test_case <= 10; ++test_case){
		int N, startnode;
		cin >> N >> startnode;
		memset(visited, 0, sizeof(visited));
		for(int i=0;i<N/2;i++){
			int from, to;
			cin >> from >> to;
			graph[from].push_back(to);
		}
		int height = BFS(startnode);
		int output=0;
		for(int i=0;i<101;i++){
			if(visited[i]==height){
				output = max(output, i);
			}
		}
		outputs.push_back(output);

		for(int i=0;i<101;i++) graph[i].clear();
		graph->clear();
	}
	int a = 1;
	for(int i=0;i<outputs.size();i++){
		if(i!=outputs.size()-1)
			cout << '#' << a++ << ' ' << outputs[i] << '\n';
		else
			cout << '#' << a++ << ' ' << outputs[i] << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}