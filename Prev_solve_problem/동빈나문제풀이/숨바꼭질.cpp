#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
#define INF 200000

struct ship{
    int node;
    int cost;
    ship(int n, int c) : node(n), cost(c) {}
};

void Di(int n,vector<vector<int>> &space, vector<int> &distance){
    queue<ship> q;
    q.push(ship(1,0));
    distance[1] = 0;
    while (!q.empty())
    {
        int node = q.front().node;
        int cost = q.front().cost;
        q.pop();
        if(distance[node]<cost) continue;
        for(auto it : space[node]){ //it: 연결된 노드들.
            if(distance[it]<cost+1) continue;

            distance[it] = cost +1;
            q.push(ship(it,cost+1));
        }
    }
    
    return;
}
int main(){
    int n,m;
    cin >> n >> m;
    vector<vector<int>> space(n+1);
    vector<int> distance(n+1,INF);

    for(int i=0;i<m;i++){
        int from, to;
        cin >> from >> to;
        space[from].push_back(to);
        space[to].push_back(from);
    }
    Di(n,space,distance);
    int maxv=0;
    cout << *max_element(distance.begin()+1,distance.end()) << " " << max_element(distance.begin()+1,distance.end()) - distance.begin();  
    return 0;
}