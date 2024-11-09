/*
그래프에서 연결된 모든 노드를 확인해보고 최소 경로를 찾는다.
이후 방문하지 않았던 노드를 확인해, 기존 비용보다 저렴한 경로를 확인하여 갱신해나간다.
*/
#include <string.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
const int INF = 0x3f3f3f3f;
int graph[101][101];
int road[101][101];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        fill(graph[i], graph[i]+1+n, INF);
    for(int i=0;i<m;i++){
        int from, to, cost;
        cin >> from >> to >> cost;
        graph[from][to] = min(graph[from][to],cost);
        road[from][to] = to;  
    }

    for(int i=1;i<=n;i++)  graph[i][i] = 0;

    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++){
                if(graph[i][k]+graph[k][j]<graph[i][j]){
                    graph[i][j] = graph[i][k]+graph[k][j];
                    road[i][j] = road[i][k];
                }
            }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(graph[i][j]==INF)
                cout << "0" << " ";
            else 
                cout << graph[i][j] << " ";
        }
        cout << '\n';
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(graph[i][j]==INF || graph[i][j]==0){
                cout << "0\n";
                continue;
            }
            int target = i;
            vector<int> course;
            while(target!=j){
                course.push_back(target);
                target = road[target][j];
            }
            course.push_back(j);
            cout << course.size() << ' ';
            for(auto it : course){
                cout << it << " ";
            }
            cout << '\n';
        }   
    }
    return 0;
}