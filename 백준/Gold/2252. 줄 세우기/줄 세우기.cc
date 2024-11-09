#include <iostream>
#include <queue>

using namespace std;
vector<int> graph[32001];
vector<int> prev_count;
vector<int> output;

void Sol(int N){
    queue<int> q;
    for(int i=1;i<=N;i++)
        if(prev_count[i]==0)
            q.push(i);
    while(!q.empty()){
        int cur = q.front(); q.pop();
        output.push_back(cur);
        for(int it : graph[cur]){
            if(--prev_count[it]==0)
                q.push(it);
        }
    }
    return;
}
int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
    int N,M;
    cin >> N >> M;
    prev_count.resize(N+1);
    for(int i=0;i<M;i++){
        int from, to;
        cin >> from >> to;
        graph[from].push_back(to);
        prev_count[to]++;
    }
    Sol(N);

    for(auto it : output)
        cout << it << " ";
    return 0;
}