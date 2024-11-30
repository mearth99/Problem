#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> scores[4], orig[3];

void solution() {
    cin >> N;
    for (auto& v : orig) v.resize(N);
    for (auto& v : scores) v.resize(N);

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < N; j++) {
            cin >> orig[i][j];
            scores[i][j] = orig[i][j];
        }
    }

    for (int j = 0; j < N; j++)
        scores[3][j] = orig[0][j] + orig[1][j] + orig[2][j];

    for (auto& v : scores) sort(v.begin(), v.end());

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < N; j++)
            cout << N - (upper_bound(scores[i].begin(), scores[i].end(), orig[i][j]) - scores[i].begin()) + 1 << ' ';
        cout << '\n';
    }

    for (int j = 0; j < N; j++)
        cout << N - (upper_bound(scores[3].begin(), scores[3].end(), orig[0][j] + orig[1][j] + orig[2][j]) - scores[3].begin()) + 1 << ' ';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solution();
    return 0;
}