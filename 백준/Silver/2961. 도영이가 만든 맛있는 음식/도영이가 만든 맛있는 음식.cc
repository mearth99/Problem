#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <string>
#include <climits>
using namespace std;


vector <pair<long, long>> v;
vector<bool> vis;
int N;
long long minv = LLONG_MAX;
void DFS(pair<long long, long long> value, int level) {
    if (level > 0) {
        minv = min(minv, abs(value.first - value.second));
    }
    for (int i = 0; i < N; i++) {
        if (vis[i]) continue;
        vis[i] = 1;
        DFS({ value.first * v[i].first, value.second + v[i].second }, level + 1);
        vis[i] = 0;
    }
}

void solution() { 
    
    cin >> N;
    v.resize(N);
    vis.resize(N+1, 0);
    for (int i = 0; i < N; i++) {
        cin >> v[i].first >> v[i].second;
    }
    DFS({1,0}, 0);
    cout << minv;
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    solution();
    

    return 0;
}