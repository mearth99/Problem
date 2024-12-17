#include <iostream>
#include <queue>

using namespace std;
vector<int> graph[501];
vector<int> prev_rank;
vector<int> prev_rank;
vector<int> output;

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
    int T, N, M;
    cin >> T;
    while(T--){
        cin >> N;
        prev_rank.clear();
        prev_rank.resize(N+1);
        for(int i=1;i<=N;i++){
            cin >> prev_rank[i];
        }
        cin >> M;
        for(int i=0;i<M;i++){
            int from, to;
            cin >> from >> to;
            graph[from].push_back(to);
            prev_count[to]++;
        }
        Sol(N);
    }
    

    for(auto it : output)
        cout << it << " ";
    return 0;
}