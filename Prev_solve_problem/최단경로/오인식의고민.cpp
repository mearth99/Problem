#include<cstring>
#include<iostream>
#include<vector>
#include<queue>

#define INF -987654321

using namespace std;

int n,s,e,m;

long long node[51];
int weight[51];
struct onin{
    int from;
    int to;
    int cost;
};

vector<onin> graph;
vector<int> cycle;

bool bfs(int start, int end){
    int visit[51];
    memset(visit,0,sizeof(visit));
    visit[start] = true;
    queue<int> q;
    q.push(start);
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(auto it: graph){
            if(it.from==cur && !visit[it.to]){
                visit[it.to] = true;
                q.push(it.to);
            }
        }
    }
    if(visit[e]==true) return true;
    else return false;
}

void Bellman(int start){
    node[start] = weight[start];
    for(int i=0;i<n-1;i++){
        if(node[i]==INF) continue;
        for(int j=0;j<graph.size();j++){
            int from = graph[j].from;
            int to = graph[j].to;
            int cost = graph[j].cost;
            if(node[from]+cost>node[to])
                node[to] = node[from] + cost;
        }
    }
    for(int j=0;j<graph.size();j++){
            int from = graph[j].from;
            int to = graph[j].to;
            int cost = graph[j].cost;
            if(node[to]<node[from]+cost)
                cycle.push_back(from);
    }
    for(auto it : cycle){
        if(bfs(s,it) && bfs(it,e)){
            //둘다 사이클이 있고, 시작에서 끝까지 갈 수 있다면, Gee
            cout << "Gee";
            return;
        }
    }
    if(bfs(s,e)) cout << node[e];
    else cout << "gg";
    return;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<onin> temp;
    cin >> n >> s >> e >> m;
    for(int i=0;i<n;i++)
        node[i] = INF;
    for(int i=0;i<m;i++){
        int from, to, cost;
        cin >> from >> to >> cost;
        temp.push_back({from,to,cost});
    }
    for(int i=0;i<n;i++)
        cin >> weight[i];

    for(auto it : temp)
        graph.push_back({it.from,it.to,weight[it.to]-it.cost});

    Bellman(s);
 
    
    return 0;
}