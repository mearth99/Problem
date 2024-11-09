#include<iostream>
#include<vector>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;

int N, M;

int arr[11][11];
int visited[11][11][2];
int dy[4] = { 0,0,-1,1 };
int dx[4] = { -1,1,0,0 };
struct moves {
	int y, x, times, change, cans; // y, x, 시간, 오작교를 탈 수 있는 기회
};
int minv = INT32_MAX;
void BFS() {
	queue<moves> q;
	q.push({ 0,0,0,1,1 });
	visited[0][0][1] = 0;
	while (!q.empty()) {
		int y = q.front().y;
		int x = q.front().x;
		int times = q.front().times;
		int change = q.front().change;
		int cans = q.front().cans;
		q.pop();
		if (y == N - 1 && x == N - 1) {
			minv = min(minv, times);
			continue;
		}
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny >= 0 && ny < N && nx >= 0 && nx < N && times < visited[ny][nx][change]) {
				if (arr[ny][nx] == 1) {
					visited[ny][nx][change] = times;
					q.push({ ny,nx,times + 1,change, 1});
				}
				if (arr[ny][nx] == 0 && change) {
					int nexttime = times + (M - times % M);
					if (nexttime < visited[ny][nx][change]) {
						visited[ny][nx][change] = nexttime;
						q.push({ ny,nx,nexttime,0,0 });
					}
				}
				if (arr[ny][nx] > 1 && cans) {
					int nexttime = times + (arr[ny][nx] - times % arr[ny][nx]);
					if (nexttime < visited[ny][nx][change]) {
						visited[ny][nx][change] = nexttime;
						q.push({ ny,nx,nexttime, change,0 });
					}
				}
			}
		}
	}
}

void solution() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
			visited[i][j][0] = INT32_MAX;
			visited[i][j][1] = INT32_MAX;
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (arr[i][j] == 0) {
				int lr = 0;
				int ud = 0;
				for (int k = 0; k < 4; k++) {
					int ny = i + dy[k];
					int nx = j + dx[k];
					if (ny >= 0 && ny < N && nx >= 0 && nx < N) {
						if (arr[ny][nx] == 0 && (k == 0 || k == 1))
							lr = 1;
						if (arr[ny][nx] == 0 && (k == 2 || k == 3))
							ud = 1;
					}
				}
				if (lr && ud) arr[i][j] = -1;
			}
		}
	}
	BFS();
	cout << minv;
}


int main() {
	solution();
	return 0;
}

