/*
그래프에서 연결된 모든 노드를 확인해보고 최소 경로를 찾는다.
이후 방문하지 않았던 노드를 확인해, 기존 비용보다 저렴한 경로를 확인하여 갱신해나간다.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include<string.h>
#define INF 987654321
using namespace std;
struct road{
    int cur;
    int cost;
};
struct cmp{
    bool operator()(road a, road b){
        return a.cost > b.cost;
    }
};

int graph[501][501];
vector<int> node(501,INF);
int n,m,s,d;
vector<int> minroads[501];
void dijk(int start, int end){
    
    priority_queue<road, vector<road>, cmp> q;
    q.push({start,0});
    node[start] = 0; //출발지점의 비용은 0이다.
    while(!q.empty()){
        int cost = q.top().cost;
        int cur = q.top().cur;
        q.pop();

        if(node[cur]<cost) continue; //현재 탐사하고 있는 비용이 기존 비용보다 많으면 탐사할 필요가 없다.

        for(int i=0;i<n;i++){
            if(graph[cur][i]==0) continue;
            int nextcost = graph[cur][i] + cost; //현재 노드까지 탐사 비용과 다음 노드로 향하는 비용을 덧셈한다.
            if(nextcost<node[i]) //현재 탐사 비용이 기존 비용보다 더 저렴하거나 같다면 (여러개의 최소비용을 탐사해야함) 탐사한다.
            {
                    node[i] = nextcost;
                    minroads[i].clear();
                    minroads[i].push_back(cur);
                    q.push({i,nextcost});
    
            }else if(nextcost==node[i])
                minroads[i].push_back(cur);
        } 
    }
    return;
}
void BFS(int start, int end){
    bool visit[501] = {0};
    queue<int> q;
    q.push(end);
    while(!q.empty()){
        int target = q.front(); q.pop();
        visit[target] = true;
        for(auto it : minroads[target]){
            graph[it][target] = 0;
            if(!visit[it])
                q.push(it);
        }
    }
    return;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    while(1){
        cin >> n >> m;
        if(n==0 && m==0) break;
        cin >> s >> d;
        for(int i=0;i<m;i++){
            int from, to, cost;
            cin >> from >> to >> cost;
            graph[from][to]=cost;
        }
        dijk(s,d);
        BFS(s,d);
        node.assign(501,INF);
        dijk(s,d);
        if(node[d]==INF)
            cout << -1 << '\n';
        else 
            cout << node[d] << '\n';
        for(int i=0; i<n; i++){
            memset(graph[i], 0, sizeof(int)*n);
        }
        for(int i=0; i<n; i++){
            minroads[i].clear();
        }
        node.assign(501,INF);
    }
    return 0;
}