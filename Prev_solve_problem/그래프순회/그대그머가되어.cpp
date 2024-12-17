#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <deque>
using namespace std;

vector<int> arr[1001];
int visited[1001];
int main(){
	int a,b,N,M,output = -1;
	bool flag = false;
	cin >> a >> b;
	cin >> N >> M;
	for(int i=0;i<M;i++){
		int from, to;
		cin >> from >> to;
		arr[from].push_back(to);
		arr[to].push_back(from);
	}
	deque<pair<int,int>> dq;
	dq.push_back({a,0});
	visited[a] = 1;
	while(!dq.empty()){
		int cur = dq.front().first;
		int cost = dq.front().second;
		dq.pop_front();

		if(cur==b){
			output = cost;
			break;
		}
		for(auto it: arr[cur]){
			if(visited[it]) continue;
			dq.push_back({it,cost+1});
			visited[it] = 1;
		}
	}
	cout << output;
	return 0;
}