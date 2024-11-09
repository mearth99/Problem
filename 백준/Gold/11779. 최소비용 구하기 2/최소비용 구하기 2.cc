/*
그래프에서 연결된 모든 노드를 확인해보고 최소 경로를 찾는다.
이후 방문하지 않았던 노드를 확인해, 기존 비용보다 저렴한 경로를 확인하여 갱신해나간다.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define INF 2100000000
using namespace std;

vector<pair<int,int>> graph[1001];
vector<int> node;
int road[1001];
void dijk(int start){
    road[start] = -1;
    priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> q;
    q.push({0,start});
    node[start] = 0; //출발지점의 비용은 0이다.
    while(!q.empty()){
        int cost = q.top().first;
        int target = q.top().second;
        q.pop();
        if(node[target]<cost) continue; //현재 탐사하고 있는 비용이 기존 비용보다 많으면 탐사할 필요가 없다.
        for(auto it : graph[target]){
            int nextcost = it.second + cost; //현재 노드까지 탐사 비용과 다음 노드로 향하는 비용을 덧셈한다.
            if(nextcost<node[it.first]) //현재 탐사 비용이 기존 비용보다 더 저렴하다면 탐사한다.
            {
               road[it.first] = target;
               node[it.first] = nextcost;
               q.push({nextcost,it.first}); 
            }
        } 
    }
    return;
}
int main(){
    int n,m,start,end,target;
    vector<int> course;
    cin >> n;
    cin >> m;
    node.resize(n+1,INF);
    for(int i=0;i<m;i++){
        int from, to, cost;
        cin >> from >> to >> cost;
        graph[from].push_back({to,cost});
    }
    cin >> start >> end;
    target = end;
    dijk(start);
    while(road[target]!=-1){
        course.push_back(target);
        target = road[target];
    }
    course.push_back(start);
    cout << node[end] << '\n';
    cout << course.size() << '\n';
    for(int i=course.size()-1;i>=1;i--)
        cout << course[i] << " ";
    cout << course[0];
    return 0;
}