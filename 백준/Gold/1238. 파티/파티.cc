#include <bits/stdc++.h>
#define INF 987654321
using namespace std;


int main(){
    int N, M, X,Maxv=0;
    cin >> N >> M >> X;
    vector<vector<int>> graph(N+1,vector<int>(N+1,INF));
    for(int i=0;i<M;i++){
        int to, from, costs;
        cin >> to >> from >> costs;
        graph[to][from] = costs;
    }
    for(int i=0;i<N;i++)
        graph[i][i] = 0;

    for(int k=1;k<=N;k++){
        for(int i=1;i<=N;i++){
            for(int j=1;j<=N;j++){
                graph[i][j] = min(graph[i][j],graph[i][k]+graph[k][j]);
            }
        }
    }    
    for(int i=1;i<=N;i++){
        Maxv = max(Maxv,graph[i][X]+graph[X][i]);
    }
    cout << Maxv;
    return 0;
}