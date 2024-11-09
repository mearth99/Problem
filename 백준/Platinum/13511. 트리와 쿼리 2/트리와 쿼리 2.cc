
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<algorithm>
#include<cmath>
using namespace std;

/*
* 문제 설명 및 링크
https://www.acmicpc.net/problem/11437
LCA 기본으로 풀어보도록 하자.
*/
/*
* 소감
*/

vector<pair<int, int>> graph[100001];
int parents[100001][20];
int depth[100001];
long long costs[100001];
int N, M;
int maxnode = 20;

int LCA_Upgrade(int a, int b) {
    if (depth[a] < depth[b]) {
        swap(a, b);
    }
    int diff = depth[a] - depth[b];
    for (int i = 0; i <= maxnode; i++) {
        if ((diff >> i) & 1) a = parents[a][i];
    }
    if (a == b) return a;

    for (int i = maxnode-1; i >= 0; i--) {
        if (parents[a][i] != parents[b][i]) {
            a = parents[a][i];
            b = parents[b][i];
        }
    }
    return parents[a][0];
}
void DFS(int cur, int par) {
    parents[cur][0] = par;
    depth[cur] = depth[par] + 1;
    for (auto it : graph[cur]) {
        if (it.first != par) {
            costs[it.first] = costs[cur] + it.second;
            DFS(it.first, cur);
        }
    }
}
int Find(int t, int cnt) {
    for (int i = 0; i <=maxnode; i++) {
        if ((cnt >> i) & 1)
            t = parents[t][i];
    }
    return t;
}
void solution() {
    cin >> N;
    for (int i = 0; i < N - 1; i++) {
        int par, chi, cost;
        cin >> par >> chi >> cost;
        graph[chi].push_back({ par,cost });
        graph[par].push_back({ chi,cost });
    }
    depth[1] = 0;
    costs[1] = 0;
    DFS(1, 0);
    for (int j = 1; j < maxnode; j++) {
        for (int i = 1; i <= N; i++) {
            if (parents[i][j - 1] != -1) {
                parents[i][j] = parents[parents[i][j - 1]][j - 1];
            }
        }
    }
    int M;
    cin >> M;
    for (int i = 0; i < M; i++) {
        int cmd, from, to;
        cin >> cmd;
        if (cmd == 1) {
            cin >> from >> to;
            int common = LCA_Upgrade(from, to);
            cout << costs[from] + costs[to] - 2 * costs[common] << '\n';
        }
        else {
            int k;
            cin >> from >> to >> k;
            k--;
            int common = LCA_Upgrade(from, to);
            int left = depth[from] - depth[common];
            int right = depth[to] - depth[common];
            //left + right 보다는 k가 작음. left 보다 크면 k에서 찾고 left보다 작으면 left에서 찾는다.

            if (left >= k) cout << Find(from,k) << '\n';
            else cout << Find(to, right - (k -left)) << '\n';
        }
    }
}

int main() {
    cout.tie(0);
    cin.tie(NULL); ios_base::sync_with_stdio(false);

    solution();

    return 0;
}
