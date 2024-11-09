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

struct green{
    int y;
    int x;
    int cost;
};
struct cmp{
    bool operator()(green a, green b){
        return a.cost > b.cost;
    }
};


int graph[126][126];
int node[126][126];
int dx[4] = {0,0,1,-1};
int dy[4] = {-1,1,0,0};

void dijk(int n){
    priority_queue<green, vector<green>, cmp> q;
    q.push({0,0,graph[0][0]});
    node[0][0] = graph[0][0]; //출발지점의 비용은 0이다.
    while(!q.empty()){
        int y = q.top().y;
        int x = q.top().x;
        int cost = q.top().cost;
        q.pop();
        if(node[y][x]<cost) continue; //현재 탐사하고 있는 비용이 기존 비용보다 많으면 탐사할 필요가 없다.
        for(int i=0;i<4;i++){
           int ny = y+dy[i];
           int nx = x+dx[i];
           if(nx>=0 && nx<n && ny>=0 && ny<n){
                int nextcost = cost + graph[ny][nx];
                if(nextcost<node[ny][nx]){
                    node[ny][nx] = nextcost;
                    q.push({ny,nx,nextcost});
                }
           }
        } 
    }
    return;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T=0;
    while(T++>=0){
        int n;
        cin >> n;
        fill(&node[0][0],&node[125][126],INF);
        if(n==0) break;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin >> graph[i][j];
            }
        }
        dijk(n);
        cout << "Problem " << T << ": " << node[n-1][n-1] << "\n";

    }
    return 0;
}