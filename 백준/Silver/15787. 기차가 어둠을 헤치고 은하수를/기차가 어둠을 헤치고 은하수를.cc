#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <string>
#include <climits>
using namespace std;
/*
int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        memset(visit, 0, sizeof(visit));
        int value = 0;
        for (int i = 0; i < 3; i++) {
            string str;
            cin >> str;
            for (int j = 0; j < 3; j++) {
                if (str[j] == '*') {
                    value |= 1 << i * 3 + j;
                }
            }
        }
    }
*/

unordered_map<int, bool> visit;

void solution() { 
    int N,M;
    cin >> N >> M;
    vector<int> train(N+1);
    for (int i = 0; i < M; i++) {
        int cmd, idx, th;
        cin >> cmd >> idx;
        if (cmd == 1) {
            cin >> th;
            train[idx] |= (1 << th-1);
        }
        else if (cmd == 2) {
            cin >> th;
            train[idx] &= ~(1 << th - 1);
        }
        else if (cmd == 3) {
            train[idx] &= ~(1 << 19);
            train[idx] = (train[idx] << 1);
        }
        else if (cmd == 4) {
            train[idx] &= ~(1 << 0);
            train[idx] = (train[idx] >> 1);
        }
    }
    int cnt = 0;
    for (int i = 1; i <= N; i++) {
        if (!visit[train[i]]) {
            visit[train[i]] = 1;
            cnt++;
        }
    }
    cout << cnt;
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    solution();
    

    return 0;
}