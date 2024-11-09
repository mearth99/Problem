#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<algorithm>
#define INF ((1<<31)-1)
using namespace std;

/*
* 문제 설명 및 링크
https://www.acmicpc.net/problem/17836
1. BFS를 돌린다.
2. BFS는 visit가 2개 있다
3. visit2는 그람을 얻었을 때 사용한다.
4. 그람이 없고 있고를 구분하여 세팅한다.
*/
/*
* 소감
*/

int N, M, T;
int arr[101][101];
int visited[101][101][2] = { 0 };
struct princess {
	int y, x, times, magic;
};
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,-1,0,1 };

int minv = INF;
void BFS() {
	queue<princess> q;
	q.push({ 0,0,0,0 });
	visited[0][0][0] = 1;
	while (!q.empty()) {
		int y = q.front().y;
		int x = q.front().x;
		int times = q.front().times;
		int magic = q.front().magic;
		q.pop();
		if (y == N - 1 && x == M - 1) {
			minv = min(minv, times);
			continue;
		}
		if (arr[y][x] == 2)
			magic = 1;
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny >= 0 && nx >= 0 && ny < N && nx < M && !visited[ny][nx][magic]) {
				if (magic == 0 && arr[ny][nx] == 1) continue;
				visited[ny][nx][magic] = 1;
				q.push({ ny,nx,times + 1,magic });
			}
		}
	}
}


void solution() {
	cin >> N >> M >> T;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}
	BFS();
	if (minv > T) {
		cout << "Fail";
	}
	else {
		cout << minv;
	}
}

int main() {

	cin.tie(NULL); ios_base::sync_with_stdio(false);
	solution();
	return 0;
}

