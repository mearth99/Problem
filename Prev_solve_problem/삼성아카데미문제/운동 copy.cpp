#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <string>


using namespace std;

vector<int> outputs;


#define INF 20000000

int main(int argc, char** argv)
{
	int test_case,T;
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case){
		int v,e,minv=INF;
		cin >> v >> e;
		vector<vector<pair<int,int>>> city(v+1);
		vector<int> nodes(v+1, INF);
		for(int i=0;i<e;i++){
			int from,to,cost;
			cin >> from >> to >> cost;
			city[from].push_back({to,cost});
		}
		priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> q;
		q.push({0,1});
		while(!q.empty()){
			pair<int,int> cur = q.top(); q.pop();
			if(nodes[cur.second]< cur.first) continue;
			for(auto it: city[cur.second]){
				int nextcost = it.second + cur.first;
				if(nextcost < nodes[it.first]){
					nodes[it.first] = nextcost;
					q.push({it.first, nextcost});
				}
			}

		}
		for(int i=1; i<=v;i++){
			minv = min(minv, nodes[i]);
		}
		if(minv == INF) 
			outputs.push_back(-1);
		else
			outputs.push_back(minv);
		city.clear();
		nodes.clear();
	}
	int a = 1;
	for(auto &it : outputs){
		cout << '#' << a++ << ' ' << it << '\n';
	}

	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}