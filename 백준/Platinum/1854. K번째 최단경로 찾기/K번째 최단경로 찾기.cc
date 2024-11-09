/*

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define INF 21000000
using namespace std;


priority_queue<int> prior_down[1001];

void dijk(int count, int start, vector<pair<int,int>> graph[]){
    queue<pair<int,int>> q;
    q.push({0,start});
    prior_down[1].push(0);
    while(!q.empty()){
        int cost = q.front().first;
        int target = q.front().second;
        q.pop();
        for(auto it : graph[target]){ //it -> first는 다음 노드, second는 비용
            int nextcost = it.second + cost; //현재 노드까지 탐사 비용과 다음 노드로 향하는 비용을 덧셈한다.
            if(prior_down[it.first].size()<count || prior_down[it.first].top()>nextcost){
                if(prior_down[it.first].size() == count) prior_down[it.first].pop();
                prior_down[it.first].push(nextcost);
                q.push({nextcost,it.first}); 
            }
        } 
    }
}
int main(){
    int n,m,k;
    cin >> n >> m >> k;
    vector<pair<int,int>> graph[1001];
    vector<int> node(1001,0);

    for(int i=0;i<m;i++){
        int from, to, cost;
        cin >> from >> to >> cost;
        graph[from].push_back({to,cost});
    }
    dijk(k,1,graph);
    for(int i=1;i<=n;i++){
        if(prior_down[i].size()<k)
            cout << -1 << endl;
        else
            cout << prior_down[i].top() << endl;
    }
    return 0;
}