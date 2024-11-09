#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#define INF 0x7fffffff
using namespace std;


void solution() {
    int N;
    deque<pair<int, int>> dq;
    cin >> N;
    for (int i = 0; i < N; i++) {
        int cur;
        cin >> cur;
        while (!dq.empty() && dq.front().first < cur) {
            dq.pop_front();
        }
        if (!dq.empty()) {
            cout << dq.front().second+1 << ' ';
        }
        else {
            cout << 0 << ' ';
        }
        dq.push_front({ cur,i });

    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solution();

    return 0;
}