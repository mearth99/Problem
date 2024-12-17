/*
일반적인 다익스트라 -> 최소비용 탐색 알고리즘은 시간이 [ E log V ]  소요 된다. 
이는 우선순위 큐 알고리즘에 따라 자체적으로 log 만큼 걸리기 떄문이다.

이를 [[특별한 상황]]에서 개선할 수 있는게 0-1 BFS 알고리즘이다.

모든 간선에서 가중치가 0과 1만 존재하는 상황에서 사용할 수 있으며 특이한 점으로 Deck를 사용한다.

최소비용을 탐색하는 경우 (우선 순위 알고리즘으로 비용별 정렬할 때)
-> 언제나 낮은 비용순으로 탐색하게 된다.
그런데, 0과 1만 가중치로 가지게 된다면 
0은 앞에서 삽입하고 1은 뒤로 삽입하여 높은 가중치는 뒤로 보낼 수 있다.

이 경우 우선순위 큐 만큼의 시간이 걸리지 않기 때문에 훨씬 빠른 시간이 소오되며

이 경우 E + V 만큼의 시간 복잡도가 나타난다.

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <deque>
#define INF 2100000000
using namespace std;

void BFS01(int start, vector<vector<pair<int,int>>> &graph, vector<int> &node){
    deque<pair<int,int>> deq;
    node[start] = 0;
    deq.push_front({0,start});
    while(!deq.empty()){
        int cost = deq.front().first;
        int idx = deq.front().second;
        deq.pop_front();
        if(node[idx] > cost){
            for(auto it : graph[idx]){
                int nextcost = cost + it.second;
                if(node[it.first] > nextcost){
                    node[it.first] = nextcost;
                    if(nextcost == cost)
                        deq.push_front({nextcost,it.first});
                    else
                        deq.push_back({nextcost,it.first});
                }
            }
        }
    }
    
}
int main(){
    int n,m;
    cin >> n >> m;
    vector<vector<pair<int,int>>> graph;
    vector<int> node(n,INF);

    // cost값이 전부 0이거나 1이여야만 한다.
    for(int i=0;i<m;i++){
        int from, to, cost;
        cin >> from >> to >> cost;
        graph[from].push_back({to,cost});
        graph[to].push_back({from,cost});
    }
    BFS01(0,graph,node);
    return 0;
}