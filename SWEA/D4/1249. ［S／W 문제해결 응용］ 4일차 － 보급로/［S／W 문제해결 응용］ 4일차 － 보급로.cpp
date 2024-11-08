#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;
int N;
vector<vector<int>> arr;
int visited[101][101];

int dy[4] = { 0,0,-1,1 };
int dx[4] = { -1,1,0,0 };

void Di() {
    priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    pq.push({ 0,{0,0} });
    visited[0][0] = 0;
    while (!pq.empty()) {
        int cost = pq.top().first;
        int y = pq.top().second.first;
        int x = pq.top().second.second;
        pq.pop();
        if (visited[y][x] < cost) continue;
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny >= 0 && ny < N && nx >= 0 && nx < N) {
                int nextcost = cost + arr[ny][nx];
                if (visited[ny][nx] <= nextcost) continue;
                visited[ny][nx] = nextcost;
                pq.push({ nextcost, {ny,nx} });
            }
        }
    }
}

void solution() {
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        fill(&visited[0][0], &visited[100][100], 0x7fffffff);
        cin >> N;
        arr.resize(N, vector<int>(N,0));
        for (int h = 0; h < N; h++) {
            string str;
            cin >> str;
            for (int j = 0; j < str.size(); j++) {
                arr[h][j] = str[j] - '0';
            }
        }
        Di();
        cout << "#" << i << ' ' << visited[N - 1][N - 1] << '\n';
        arr.clear();
    } 
}



int main() {
    ios_base::sync_with_stdio(NULL);
    cin.tie(0);

    solution();
    return 0;
}