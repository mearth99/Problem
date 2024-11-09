#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
#define INF 1e9
typedef long long ll;
int N,M;

bool seek[100001] = {0};
ll node[100001] = {0};
vector<pair<int,long long>> arr[100001];

void GO(int start){

	priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pq;
	pq.push({0,start});
	while (!pq.empty())	
	{
		ll cost = pq.top().first;
		int	idx = pq.top().second;
		pq.pop();
		if(node[idx] < cost) continue;
		for(auto it : arr[idx]){
			if(seek[it.first] && it.first != N-1) continue;
			ll nextcost = cost + it.second;
			if(node[it.first] > nextcost){
				node[it.first] = nextcost;
				pq.push({nextcost,it.first});
			}
		}
	}
}

int main(){
	fill_n(node,100001,ll(1e18));
	cin >> N >> M;

	for(int i=0;i<N;i++) cin >> seek[i];
	for(int i=0;i<M;i++){
		int from, to;
		ll cost;
		cin >> from >> to >> cost;
		arr[from].push_back({to, cost});
		arr[to].push_back({from, cost});
	}
	GO(0);
	if(node[N-1]==(ll)1e18) cout << -1;
	else cout << node[N-1];
	return 0;
}