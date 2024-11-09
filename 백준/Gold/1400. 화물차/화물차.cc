#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<algorithm>
using namespace std;

/*
* 문제 설명 및 링크
https://www.acmicpc.net/problem/1400
화물차가 출발지에서 목적지까지 최단 경로를 구하는 프로그램
1. 화물차가 목적지까지 이동법: 상하 좌우
2. 각 교차로는 시간에 따라 이동할 수 있는 신호가 존재함
3. visited[N][M][2]로 구성하여 2는 교차로 [0] -> 상하 [1] -> 남북으로 구성.
*/
/*
* 소감
*/

int arr[21][21];
int visited[21][21];
int N, M, T = 0;
int sy, sx, ey, ex;
struct direct {
	int start_pos;
	int lr;
	int ud;
};
struct car {
	int y, x, times;
};
int dy[4] = { -1,1,0,0 }; //
int dx[4] = { 0,0,-1,1 };
vector<int> outputs;
direct traff[10];
int output = INT32_MAX;

void BFS() {
	queue<car> q;
	q.push({ sy,sx,0 });
	while (!q.empty()) {
		int y = q.front().y;
		int x = q.front().x;
		int times = q.front().times;
		q.pop();
		if (y == ey && x == ex) {
			output = min(output, times);
			continue;
		}
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny >= 0 && nx >= 0 && nx < M && ny < N && arr[ny][nx] != -1 && times < visited[ny][nx]) {
				if (arr[ny][nx] >= 0 && arr[ny][nx] < 10) {
					//현재 시간에 따른 활성화된 신호를 구해야한다.
					direct cur = traff[arr[ny][nx]];
					int rest = times % (cur.lr + cur.ud);
					if (cur.start_pos == 0) {// 동서 방향이 먼저 시작했을 경우
						if (rest < cur.lr) { // 동서 시간이다.
							if (i == 2 || i == 3) {
								visited[ny][nx] = times;
								q.push({ ny,nx,times + 1 });
							}
							else {
								//동서 시간이니 남북 시간이 올때까지 기다려야한다.
								int nexttime = times + (abs(cur.lr - rest)) + 1;
								if (nexttime < visited[ny][nx]) {
									visited[ny][nx] = nexttime;
									q.push({ ny,nx,nexttime });
								}
							}
						}
						else { //남북 시간이 되버렸다.
							if (i == 0 || i == 1) {
								visited[ny][nx] = times;
								q.push({ ny,nx,times + 1 });
							}
							else {
								//남북 시간이니 다음 동서 시간이 올때까지 기다려야한다.
								int nexttime = times + (abs(cur.ud + cur.lr - rest) + 1);
								if (nexttime < visited[ny][nx]) {
									visited[ny][nx] = nexttime;
									q.push({ ny,nx,nexttime });
								}
							}
						}
					}
					else {
						//남북 방향이 먼저 시작했을 경우
						if (rest < cur.ud) { // 남북 시간이다.
							if (i == 0 || i == 1) {
								visited[ny][nx] = times;
								q.push({ ny,nx,times + 1 });
							}
							else {
								//남북 시간이니 동서 시간이 올때까지 기다려야한다.
								int nexttime = times + abs(cur.ud - rest) + 1;
								if (nexttime < visited[ny][nx]) {
									visited[ny][nx] = nexttime;
									q.push({ ny,nx,nexttime });
								}
							}
						}
						else { //동서 시간이 되버렸다.
							if (i == 2 || i == 3) {
								visited[ny][nx] = times;
								q.push({ ny,nx,times + 1 });
							}
							else {
								//동서 시간이니 다음 남북 시간이 올때까지 기다려야한다.
								int nexttime = times + (abs(cur.ud + cur.lr - rest)) + 1;
								if (nexttime < visited[ny][nx]) {
									visited[ny][nx] = nexttime;
									q.push({ ny,nx,nexttime });
								}
							}
						}
					}
				}
				else {
					visited[ny][nx] = times;
					q.push({ ny,nx,times + 1 });
				}
			}
		}
	}
}

void solution() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			char temp;
			visited[i][j] = INT32_MAX;
			cin >> temp;
			if (temp == 'A') {
				arr[i][j] = 100;
				sy = i;
				sx = j;
				visited[i][j] = 0;
			}
			else if (temp == 'B') {
				arr[i][j] = 100;
				ey = i;
				ex = j;
			}
			else if (temp == '#') {
				arr[i][j] = 100;
			}
			else if (temp == '.') {
				arr[i][j] = -1;
			}
			else {
				arr[i][j] = temp - '0';
				T++;
			}
		}
	}
	for (int i = 0; i < T; i++) {
		int n, a, b;
		char start;
		cin >> n;
		cin >> start;
		cin >> a >> b;
		if (start == '-') {
			traff[i].start_pos = 0;
			traff[i].lr = a;
			traff[i].ud = b;
		}
		else {
			traff[i].start_pos = 1;
			traff[i].lr = a;
			traff[i].ud = b;
		}
	}
	BFS();
	outputs.push_back(output);
}

int main() {

	cin.tie(NULL); ios_base::sync_with_stdio(false);
	while (1) {
		T = 0;
		cin >> N >> M;
		if (N == 0 && M == 0)
			break;
		output = INT32_MAX;
		solution();
	}
	for (auto it : outputs) {
		if (it == INT32_MAX) {
			cout << "impossible\n";
		}
		else {
			cout << it << '\n';
		}
	}
	return 0;
}

