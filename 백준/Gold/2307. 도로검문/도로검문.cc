/*
그래프에서 연결된 모든 노드를 확인해보고 최소 경로를 찾는다.
이후 방문하지 않았던 노드를 확인해, 기존 비용보다 저렴한 경로를 확인하여 갱신해나간다.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define INF 987654321
using namespace std;


int graph[1001][1001];
vector<int> node(1001,INF);
vector<int> road[1001];
void dijk(int n){
    priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> q;
    q.push({0,1});
    node[1] = 0; //출발지점의 비용은 0이다.
    while(!q.empty()){
        int cost = q.top().first;
        int target = q.top().second;
        q.pop();
        if(node[target]<cost) continue; //현재 탐사하고 있는 비용이 기존 비용보다 많으면 탐사할 필요가 없다.
        for(int i=1;i<=n;i++){
            if(graph[target][i]==0) continue;
            int nextcost = graph[target][i] + cost; //현재 노드까지 탐사 비용과 다음 노드로 향하는 비용을 덧셈한다.
            if(nextcost<node[i]) //현재 탐사 비용이 기존 비용보다 더 저렴하다면 탐사한다.
            {
                road[i].clear();
                road[i].push_back(target);
                node[i] = nextcost;
                q.push({nextcost,i}); 
            }
        } 
    }
    return;
}
int main(){
    int n,m;
    cin >> n >> m;
    
    for(int i=0;i<m;i++){
        int from, to, cost;
        cin >> from >> to >> cost;
        graph[from][to]=cost;
        graph[to][from]=cost;
    }
    dijk(n);
    int first = node[n];
    int second =0;
    queue<int> q;
    q.push(n);
    while(!q.empty()){
        int target = q.front(); q.pop();
        for(auto it : road[target]){
            int temp = graph[it][target];
            graph[it][target] = 0;
            node.assign(n+1,INF);
            dijk(n);
            second = max(second,node[n]);
            graph[it][target] = temp;
            q.push(it);
        }
    }
    // cout << first << " " << second;
    if(second==INF)
        cout << -1;
    else
        cout << second - first;
    return 0;
}