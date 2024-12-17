#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

vector<pair<int,int>> arr[1003];	
int visited[1003];

void cacu(int start){
	priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> q;
	q.push({0,start});
	visited[start] = 0;
	while(!q.empty()){
		int cost = q.top().first; 
		int next = q.top().second; q.pop();
		
		if(visited[next] < cost) continue;
		for(auto it : arr[next]){
			int nextcost = cost + it.second;
			if(visited[it.first] > nextcost) continue;
			visited[it.first] = nextcost;
			q.push({nextcost,it.first});
		}
	}
}

int main(){
	int N, M;
	cin >> N >> M;
	int start_point, end_point;
	arr[0].push_back({0,0});
	memset(visited, 98765432, sizeof(visited));
	for(int i=0;i<M;i++){
		int from, to, cost;
		cin >> from >> to >> cost;
		arr[from].push_back({to,cost});
	}
	cin >> start_point >> end_point;
	cacu(start_point);
	cout << visited[end_point];
	return 0;
}