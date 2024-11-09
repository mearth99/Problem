#include<cstring>
#include<iostream>
#include<vector>
#include<queue>

#define INF 987654321

using namespace std;

int n,m,w;

int node[501];
struct bell{
    int from;
    int to;
    int cost;
};
vector<bell> graph;

bool Bellman(){
    for(int i=1;i<=n;i++)
        node[i] = INF;
    node[1] = 0;
    for(int i=1;i<n;i++){
        for(int j=0;j<graph.size();j++){
            int from = graph[j].from;
            int to = graph[j].to;
            int cost = graph[j].cost;
            if(node[to]>node[from]+cost)
                node[to] = node[from] + cost;
        }
    }
    for(int j=0;j<graph.size();j++){
            int from = graph[j].from;
            int to = graph[j].to;
            int cost = graph[j].cost;
            if(node[to]>node[from]+cost)
                return true;
        }
    return false;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T,count,maxvalue;
    cin >> T;
    while(T--){
        cin >> n >> m >> w;
        graph.clear();
        for(int i=0;i<m;i++){
            int from, to, cost;
            cin >> from >> to >> cost;
            graph.push_back({from, to , cost});
            graph.push_back({to, from , cost});
        }
        for(int i=0;i<w;i++){
            int from, to, cost;
            cin >> from >> to >> cost;
            graph.push_back({from, to , -cost});
        }
        if(Bellman()) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}