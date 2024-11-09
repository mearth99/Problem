//LCA 기본

#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<algorithm>
using namespace std;

/*
* 문제 설명 및 링크
https://www.acmicpc.net/problem/11437
LCA 기본으로 풀어보도록 하자.
*/
/*
* 소감
*/

vector<int> graph[10001];
vector<int> depth;
vector<int> parents;
int N, M;

int LCA_BASE(int a, int b) {
    if (depth[a] < depth[b]) {
        swap(a, b);
    }
    while (depth[a] > depth[b]) {
        a = parents[a];
    }
    while (a != b) {
        a = parents[a];
        b = parents[b];
    }
    return a;

}

void DFS(int cur, int par, int dep) {
    depth[cur] = dep;
    for (auto it : graph[cur]) {
        if (it != par) {
            DFS(it, cur, dep + 1);
        }
    }
}

void solution() {
    cin >> N;
    depth.resize(N+1,0);
    parents.resize(N+1,0);
    for (int i = 0; i < N-1; i++) {
        int par, chi;
        cin >> par >> chi;
        parents[chi] = par;
        graph[chi].push_back(par);
        graph[par].push_back(chi);
    }
    int root = -1;
    for (int i = 1; i <= N; i++) {
        if (parents[i] == 0) root = i;
    }
    DFS(root, -1, 0);
    int from, to;
    cin >> from >> to;
    cout << LCA_BASE(from, to) << '\n';
    for (int i = 0; i <= N; i++) graph[i].clear();
    depth.clear();
    parents.clear();
}

int main() {
    cout.tie(0);
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    while(T--)
        solution();

    return 0;
}

