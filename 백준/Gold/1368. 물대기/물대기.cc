#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define MAX 500

using namespace std;

bool cmp(pair<int, pair<int, int>>& p1, pair<int, pair<int, int>>& p2) {
    return p1.first < p2.first; //오름차순정렬
}

int node[MAX];
int GetParent(int x) {
    if (x == node[x]) return x;
    else return node[x] = GetParent(node[x]);
}
void UnionParent(int a, int b) {
    a = GetParent(a);
    b = GetParent(b);
    if (a < b) node[b] = a;
    else node[a] = b;
}
bool FindParent(int a, int b) {
    a = GetParent(a);
    b = GetParent(b);
    if (a == b) return true;
    else return false;
}
int main() {
    int N;
    cin >> N;
    for (int i = 0; i < N+1; i++)
        node[i] = i;
    vector<int> wall(N);
    vector<vector<int>> arr(N, vector<int>(N,0));

    vector<pair<int, pair<int, int>>> graph;
    for (int i = 0; i < N; i++) {
        cin >> wall[i];
        graph.push_back({ wall[i],{0,i + 1} });
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (arr[i][j]) graph.push_back({ arr[i][j],{i+1,j+1} });
        }
    }
    sort(graph.begin(), graph.end());
    int costs = 0;
    for (int i = 0; i < graph.size(); i++) {
        if (!FindParent(graph[i].second.first, graph[i].second.second)) {
            costs += graph[i].first;
            UnionParent(graph[i].second.first, graph[i].second.second);
        }
    }
    cout << costs;
    return 0;
}