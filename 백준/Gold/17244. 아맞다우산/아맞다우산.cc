#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <cmath>
using namespace std;
int N, M;
int arr[51][51] = { 0 };
int visited[51][51][32] = { 0 };
int ex, ey;
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };
int minv = INT32_MAX;
int end_items = 0;
struct items {
	int y, x, bit, times;
};

void BFS(int sy, int sx) {
	queue<items> q;
	q.push({ sy,sx,0,0 });
	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int bit = q.front().bit;
		int times = q.front().times;
		q.pop();
		if (y == ey && x == ex && bit == (1 << end_items) - 1) {
			minv = min(minv, times);
			continue;
		}
 		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
 			int nx = x + dx[i];
			if (ny >= 0 && nx >= 0 && ny < N && nx < M && !visited[ny][nx][bit]) {
				if (arr[ny][nx] == -2) continue;
				if (arr[ny][nx] == -1) {
					visited[ny][nx][bit] = 1;
					q.push({ ny,nx,bit,times + 1 });
				}
				else {
					int v = arr[ny][nx];
					int newbit = bit | (1 << v);
					if (!visited[ny][nx][newbit]) {
						visited[ny][nx][newbit] = 1;
						q.push({ ny,nx,newbit,times + 1 });
					}
				}

			}
		}
	}
}

void Solution() {
	int sx=0, sy=0;
	int seqence = 0;
	cin >> M >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			char temp;
			cin >> temp;
			if (temp == '#')
				arr[i][j] = -2;
			else if (temp == '.')
				arr[i][j] = -1;
			else if (temp == 'X') {
				arr[i][j] = seqence++;
				end_items++;
			}
			else if (temp == 'E') {
				ey = i;
				ex = j;
				arr[i][j] = -1;
			}
			else {
				sy = i;
				sx = j;
				arr[i][j] = -1;
			}
		}
	}
	visited[sy][sx][0] = 1;
	BFS(sy, sx);
	cout << minv;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	Solution();
	return 0;
}