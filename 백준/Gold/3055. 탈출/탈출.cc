#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<algorithm>
using namespace std;

/*
* 문제 설명 및 링크
https://www.acmicpc.net/problem/3055
BFS를 통해 고슴도치와 물을 넣어 BFS를 하는 문제
물이 찰 예정인 칸으로 이동한 경우 Pop시키면 됨.
순서: 고슴도치, 물
*/
/*
* 소감
*/
struct moves {
	int y, x, times, water;
};
int R, C;
int arr[51][51];
int visited[51][51];

int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };
queue<moves> q;
int minv = INT32_MAX;
void BFS() {
	while (!q.empty())
	{
		/* code */
		int y = q.front().y;
		int x = q.front().x;
		int times = q.front().times;
		int water = q.front().water;
		q.pop();
		if (!water && arr[y][x] == -1) continue;
		if (arr[y][x] == 3) {
			minv = min(minv, times);
			continue;
		}
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny >= 0 && nx >= 0 && ny < R && nx < C && arr[ny][nx] != 0 && !visited[ny][nx]) {
				if (water && arr[ny][nx] != 3) {
					arr[ny][nx] = -1;
					visited[ny][nx] = 1;
					q.push({ ny,nx,times,water });
				}
				if (!water) {
					visited[ny][nx] = 1;
					q.push({ ny,nx,times + 1,water });
				}
			}

		}
	}
}
void solution() {
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			char a;
			cin >> a;
			if (a == '.') arr[i][j] = 1;
			else if (a == '*') {
				arr[i][j] = -1;
				visited[i][j] = 1;
				q.push({ i,j,0,1 });
			}
			else if (a == 'X') arr[i][j] = 0;
			else if (a == 'S') {
				arr[i][j] = 2;
			}
			else if (a == 'D') arr[i][j] = 3;
		}
	}
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (arr[i][j] == 2) {
				q.push({ i,j,0,0 });
				visited[i][j] = 1;
			}
		}
	}
	BFS();
	if (minv == INT32_MAX) {
		cout << "KAKTUS";
	}
	else cout << minv;
}

int main() {
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	solution();
	return 0;
}

