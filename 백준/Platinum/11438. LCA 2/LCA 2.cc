
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

vector<int> graph[100001];
vector<int> depth;
vector<vector<int>> parents;
int N, M;
int maxnode = 0;
int LCA_Upgrade(int a, int b) {
    if (depth[a] < depth[b]) {
        swap(a, b);
    }
    int diff = depth[a] - depth[b];
    for (int i = maxnode; i >= 0; i--) {
        if ((diff & (1 << i)) != 0) {
            a = parents[a][i];
        }
    }
    if (a == b) return a;

    for (int i = maxnode; i >= 0; i--) {
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
        if (it != par) {
            DFS(it, cur);
        }
    }
}

void solution() {
    cin >> N;
    maxnode = ceil(log2(N));
    depth.resize(N + 1, 0);
    parents.resize(N + 1, vector<int>(maxnode + 1, -1));
    for (int i = 0; i < N - 1; i++) {
        int par, chi;
        cin >> par >> chi;
        graph[chi].push_back(par);
        graph[par].push_back(chi);
    }
    depth[1] = 0;
    DFS(1, 0);
    for (int j = 1; j <= maxnode; j++) {
        for (int i = 1; i <= N; i++) {
            if (parents[i][j - 1] != -1) {
                parents[i][j] = parents[parents[i][j - 1]][j - 1];
            }
        }
    }
    int M;
    cin >> M;
    for (int i = 0; i < M; i++) {
        int from, to;
        cin >> from >> to;
        cout << LCA_Upgrade(from, to) << '\n';
    }

    for (int i = 0; i <= N; i++) graph[i].clear();
    depth.clear();
    parents.clear();
}

int main() {
    cout.tie(0);
    cin.tie(NULL); ios_base::sync_with_stdio(false);

    solution();

    return 0;
}
