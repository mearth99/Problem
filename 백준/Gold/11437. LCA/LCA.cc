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

vector<int> graph[50001];
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
    parents[cur] = par;
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
        int from, to;
        cin >> from >> to;
        graph[from].push_back(to);
        graph[to].push_back(from);
    }
    DFS(1, -1, 0);
    cin >> M;
    for (int i = 0; i < M; i++) {
        int from, to;
        cin >> from >> to;
        cout << LCA_BASE(from, to) << '\n';
    }
}

int main() {
    cout.tie(0);
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    solution();

    return 0;
}

