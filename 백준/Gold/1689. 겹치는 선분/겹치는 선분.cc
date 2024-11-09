#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#define INF 0x7fffffff
using namespace std;

void solution() {
    int N;
    cin >> N;
    vector<pair<int, int>> arr;
    for (int i = 0; i < N; i++) {
        int from, to;
        cin >> from >> to;
        arr.push_back(make_pair(from, 1));
        arr.push_back(make_pair(to, 0));
    }
    sort(arr.begin(), arr.end());
    int cnt = 0;
    int maxv = 0;
    for (auto it : arr) {
        if (it.second == 1)
            cnt++;
        else
            cnt--;
        maxv = max(maxv, cnt);
    }
    cout << maxv;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solution();

    return 0;
}