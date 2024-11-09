#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> arr;
int dy[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dx[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };

int solution() {
    string S;
    cin >> S;
    int N, M;
    cin >> N >> M;
    arr.resize(N);
    for (auto &it : arr) {
        cin >> it;
    }
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            for (int k = 0; k < 8; k++) {
                int cnt = 0;
                int ny = i;
                int nx = j;
                while (ny >= 0 && ny < N && nx >= 0 && nx < M && cnt < S.length() && S[cnt] == arr[ny][nx]) {
                    cnt++;
                    if (cnt == S.length()) {
                        return 1;
                    }
                    ny += dy[k];
                    nx += dx[k];
                }
            }
        }
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout << solution();
    return 0;
}

