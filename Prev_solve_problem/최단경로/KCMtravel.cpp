/*
그래프에서 연결된 모든 노드를 확인해보고 최소 경로를 찾는다.
이후 방문하지 않았던 노드를 확인해, 기존 비용보다 저렴한 경로를 확인하여 갱신해나간다.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define INF 123456789
using namespace std;
struct plane{
    int dest;
    int cost;
    int times;
    plane(int d, int c, int t){
        dest = d;
        cost = c;
        times = t;
    }
};
struct cmp{
    bool operator()(plane p1, plane p2){
        return p1.times > p2.times;
    }
};

vector<plane> airport[101];
vector<int> node[101];

void dijk(int n,int m){
    priority_queue<plane,vector<plane>,cmp> q;
    for(int i=0;i<=n;i++)
        node[i].assign(m+1,INF);

    q.push(plane(1,0,0));

    while(!q.empty()){
        plane target = q.top(); q.pop();

        if(node[target.dest][target.cost]<target.times) continue;

        for(int i=0; i<airport[target.dest].size();i++){
            int next = airport[target.dest][i].dest;
            int nextcost = airport[target.dest][i].cost + target.cost; //현재 노드까지 탐사 비용과 다음 노드로 향하는 비용을 덧셈한다.
            int nexttime = airport[target.dest][i].times + target.times;

            if(nextcost>m) continue;

            if(nexttime < node[next][nextcost]){

                for(int j=nextcost+1; j<=m; j++){
                    if(node[next][j] <= nexttime) break;
                    node[next][j] = nexttime;
                }

                node[next][nextcost] = nexttime;
                q.push(plane(next,nextcost,nexttime));
            }
        } 
    }

    int value = INF;
    for(int i=0;i<=m;i++)
        value = min(value,node[n][i]);

    if(value==INF)
        cout <<"Poor KCM" << '\n';
    else
        cout << value << '\n';
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int T,n,m,k;
    cin >> T;
    while(T-->0){
        cin >> n >> m >> k;
        for(int i=0;i<k;i++){
            int from,to,cost,delay;
            cin >> from >> to >> cost >> delay;
            airport[from].push_back(plane(to,cost,delay));
        }
        dijk(n,m);

        for(int i=1;i<=n;i++)
            airport[i].clear();
    }
    return 0;
}