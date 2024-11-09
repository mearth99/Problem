#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
#define MAX 1e18
vector<vector<pair<int,long long>>> arr;
long long node[100005] = {0};
priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;
void Cacu(){
	while(!pq.empty()){
		long long cost = pq.top().first;
		int idx = pq.top().second;
		pq.pop();
		if(node[idx] >= cost){
			for(auto it: arr[idx]){
				long long nextcost = cost + it.second;
				int nextidx = it.first;
				if(nextcost < node[nextidx]){
					node[nextidx] = nextcost;
					pq.push({nextcost, nextidx});
				}
			}
		}
	}
}

int main(){
	int N,M,K,max_idx=-1;
	long long maxv = 0;
	cin >> N >> M >> K;
	fill(node,node+N+2,MAX);
	arr.resize(N+1);
	vector<int> check;
	for(int i=0;i<M;i++){
		int from, to;
		long long cost;
		cin >> from >> to >> cost;
		arr[to].push_back({from,cost});
	}
	for(int i=0;i<K;i++){
		int start_point;
		cin >> start_point;
		check.push_back(start_point);
		node[start_point] = 0;
		pq.push({0,start_point});
	}
	Cacu();
	for(int i=1;i<=N;i++){
		if(maxv < node[i]){
			maxv = node[i];
			max_idx = i;
		}
	}
	cout << max_idx << '\n' << maxv;
	return 0;
}