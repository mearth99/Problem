#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

const int segment[10][10] = {
    {0, 4, 3, 3, 4, 3, 2, 3, 1, 2},
    {4, 0, 5, 3, 2, 5, 6, 1, 5, 4},
    {3, 5, 0, 2, 5, 4, 3, 4, 2, 3},
    {3, 3, 2, 0, 3, 2, 3, 2, 2, 1},
    {4, 2, 5, 3, 0, 3, 4, 3, 3, 2},
    {3, 5, 4, 2, 3, 0, 1, 4, 2, 1},
    {2, 6, 3, 3, 4, 1, 0, 5, 1, 2},
    {3, 1, 4, 2, 3, 4, 5, 0, 4, 3},
    {1, 5, 2, 2, 3, 2, 1, 4, 0, 1},
    {2, 4, 3, 1, 2, 1, 2, 3, 1, 0}
};

int N, K, P, X;
string dest;
int destv = 0;
int cnt = 0;
void DFS(int cur, string v, int cost) {
    if (cur == K) {
        int iv = stoi(v);
        if(iv>0 && iv <= destv && cost !=P)
            cnt++;
        return;
    }
    string nv = v;
    for (int i = 0; i <= 9; i++) {
        nv[cur] = i + '0';
        if(cost - segment[v[cur] - '0'][nv[cur] - '0'] >= 0) {
            DFS(cur + 1, nv, cost - segment[v[cur] - '0'][nv[cur] - '0']);
        }
    }
}


void solution() {
    cin >> N >> K >> P >> X;
    dest = string(K - to_string(N).length(), '0') + to_string(N);
    string start = string(K - to_string(X).length(), '0') + to_string(X);
    destv = stoi(dest);
    DFS(0, start, P);
    cout << cnt;
}



int main() {
    ios_base::sync_with_stdio(NULL);
    cin.tie(0);

    solution();
    return 0;
}