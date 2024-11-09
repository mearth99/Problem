#include <iostream>
#include <queue>

using namespace std;

vector<int> D;
vector<int> Prev;
vector<int> Prev_time;
vector<int> graph[1001];
//정점 K까지 접근하는 시간중에 가장 오래걸리는 시간을 기록한다.
int max(int a, int b){
    return a > b ? a : b;
}
int Sol(int N, int K){
    queue<pair<int,int>> q;
    for(int i=1;i<=N;i++)
        if(Prev[i]==0)
            q.push({i,0});
    while(!q.empty()){
        int cur = q.front().first;
        int times = q.front().second;
        q.pop();
        times += D[cur];
        if(cur==K) return times;
        for(auto it : graph[cur]){
            Prev[it]--;
            Prev_time[it] = max(Prev_time[it],times);
            if(Prev[it]==0)
                q.push({it,Prev_time[it]});
        }
    }
    return Prev_time[K];
}
int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
    int T,N,K,Dest;
    int to,from;
    cin >> T;
    while(T--){
        cin >> N >> K;
        D.clear();
        D.resize(N+1);
        Prev.clear();
        Prev.resize(N+1);
        Prev_time.clear();
        Prev_time.resize(N+1);
        for(int i=1;i<=N;i++){
            cin >> D[i];
            graph[i].clear();
        }
        for(int i=1;i<=K;i++){
            cin >> from >> to;
            graph[from].push_back(to);
            Prev[to]++;
        }
        cin >> Dest;
        cout << Sol(N,Dest) << '\n';
    }
    return 0;
}