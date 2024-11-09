#include<cstring>
#include<iostream>
#include<vector>
#include<queue>

#define INF 987654321

using namespace std;



int n, d, c;
int node[10001];
vector<pair<int,int>> computer[10001];

void Di(int start){
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
    q.push({0,start});
    node[start] = 0;
    while(!q.empty()){
        int cost = q.top().first;
        int cur = q.top().second;
        q.pop();
        if(node[cur]<cost) continue;
        for(auto it : computer[cur]){
            int nextcost = cost + it.second;
            if(node[it.first]>nextcost){
                node[it.first] = nextcost;
                q.push({nextcost,it.first});
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T,count,maxvalue;
    cin >> T;
    while(T--){
        cin >> n >> d >> c;
        count = 0;
        maxvalue = 0;
        for(int i=1;i<=n;i++) {
            computer[i].clear();
            node[i] = INF;
        }
        for(int i=0;i<d;i++){
            int from, to, cost;
            cin >> from >> to >> cost;
            computer[to].push_back({from,cost});
        }
        Di(c);
        for(int i=1;i<=n;i++)
            if(node[i]!=INF){
                count++;
                if(node[i]>maxvalue)
                    maxvalue = node[i];
            }
        cout << count << " " << maxvalue << '\n';
    }
    return 0;
}