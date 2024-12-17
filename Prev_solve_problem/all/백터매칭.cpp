#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
#include<math.h>
using namespace std;


double output;
vector<pair<int,int>> graph;
bool visit[21];
int N;
double cacu(){
    int x=0,y=0;
    for(int i=0;i<N;i++){
        if(visit[i]){
            x -= graph[i].first;
            y -= graph[i].second;
        }else{
            x += graph[i].first;
            y += graph[i].second;
        }
    }
    return sqrt(pow(x, 2) + pow(y, 2));
}
void DFS(int cur, int cnt){
    if(cnt==N/2) {
        output = min(output,cacu());
        return;
    }
    for(int i=cur;i<N;i++){
        visit[i] = true;
        DFS(i+1,cnt+1);
        visit[i] = false;
    }
}

int main(){
    int T;
    cin >> T;
    while(T--){
        graph.clear();
        output = 1e9+7;
        memset(visit,0,sizeof(visit));
        cin >> N;
        for(int i=0;i<N;i++){
            int x,y;
            cin >> x >> y;
            graph.push_back({x,y});
        }
        DFS(0,0);
        printf("%.7f\n",output);
    }

    return 0;
}