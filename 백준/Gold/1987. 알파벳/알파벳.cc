#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#define INF 0x7fffffff
using namespace std;

int visit[26];
int R, C;
vector<vector<int>> arr;
int maxv = 1;
int dy[4] = { 0,0,-1,1 };
int dx[4] = { -1,1,0,0 };
void DFS(int y, int x, int cost) {
    maxv = max(maxv, cost);
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < R && ny >= 0 && nx >= 0 && nx < C && !visit[arr[ny][nx]]) {
            visit[arr[ny][nx]] = 1;
            DFS(ny, nx, cost + 1);
            visit[arr[ny][nx]] = 0;
        }
    }
}

void solution() {
    
    cin >> R >> C;
    arr.resize(R, vector<int>(C));
    for (int i = 0; i < R; i++) {
        string str;
        cin >> str;
        for (int j = 0; j < C; j++) {
            arr[i][j] = str.at(j) - 'A';
        }
    }
    visit[arr[0][0]]= 1;
    DFS(0, 0, 1);
    cout << maxv;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solution();

    return 0;
}