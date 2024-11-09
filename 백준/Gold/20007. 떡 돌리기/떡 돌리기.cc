#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <deque>
#include <algorithm>
#define INF 1e9
using namespace std;
int N,M,X,Y;
vector<pair<int,int>> arr[1001];
int node[1001] = {0};
int visit_sum = 1;
void solution(){
	cin >> N >> M >> X >> Y;
	fill_n(node,1001,(int)INF);
	for(int i=0;i<M;i++){
		int from, to, cost;
		cin >> from >> to >> cost;
		arr[from].push_back({to,cost});
		arr[to].push_back({from,cost});
	}
	priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;
	pq.push({0,Y});
	node[Y] = 0;
	while(!pq.empty()){
		int cost = pq.top().first;
		int idx = pq.top().second;
		pq.pop();
		if(cost>node[idx]) continue;
		for(auto it: arr[idx]){
			int nextcost = cost + it.second;
			if(nextcost >= node[it.first]) continue;
			node[it.first] = nextcost;
			pq.push({nextcost,it.first});
		}
	}
	vector<int> outputs;
	for(int i=0;i<N;i++){
		if(i==Y) continue;
		if(node[i]==INF || 2*node[i] > X){
			cout << -1;
			return;
		}
		outputs.push_back(2*node[i]);
	}
	sort(outputs.begin(),outputs.end());
	int remaining_day = X;
	int day = 1;
	for(auto it : outputs){
		if(remaining_day - it >=0){
			remaining_day -= it;
		}else{
			remaining_day = X;
			remaining_day -= it;
			day++;
		}

	}
	cout << day;
	return;
}

int main(){
	ios::sync_with_stdio(false);
  	cin.tie(NULL);
  	cout.tie(NULL);
	solution();
	return 0;
}