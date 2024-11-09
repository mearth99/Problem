/*
그래프에서 연결된 모든 노드를 확인해보고 최소 경로를 찾는다.
이후 방문하지 않았던 노드를 확인해, 기존 비용보다 저렴한 경로를 확인하여 갱신해나간다.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include<string.h>
#define INF 1e15
using namespace std;
struct road{
    int cur;
    long long cost;
    int pack;
};
struct cmp{
    bool operator()(road a, road b){
        return a.cost > b.cost;
    }
};

vector<pair<int,int>> graph[10001];
long long node[10001][21];
int n,m,k;

void dijk(){
    for(int i=1;i<=n;i++)
        for(int j=0;j<=k;j++)
            node[i][j] = INF;
    priority_queue<road, vector<road>, cmp> q;
    q.push({1,0,0});
    node[1][0] = 0; //출발지점의 비용은 0이다.
    while(!q.empty()){
        int cur = q.top().cur;
        long long cost = q.top().cost;
        int pack = q.top().pack;
        q.pop();

        if(node[cur][pack]<cost) continue; //현재 탐사하고 있는 비용이 기존 비용보다 많으면 탐사할 필요가 없다.

        for(auto it : graph[cur]){
            long long nextcost = it.second + cost;
            if(nextcost<node[it.first][pack]){
                node[it.first][pack] = nextcost;
                q.push({it.first,nextcost,pack});
            }
            if(cost<node[it.first][pack+1] && pack+1<=k){
                node[it.first][pack+1] = cost;
                q.push({it.first,cost,pack+1});
            }
        }
    }
    return;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> m >> k;
    
    for(int i=0;i<m;i++){
        int from, to, cost;
        cin >> from >> to >> cost;
        graph[from].push_back({to,cost});
        graph[to].push_back({from,cost});
    }
    dijk();
    long long minv = INF;
    for(int i=0;i<=k;++i){
        minv = min(minv, node[n][i]);
    }
    cout << minv;

    return 0;
}