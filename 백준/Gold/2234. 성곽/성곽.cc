#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<algorithm>
using namespace std;

/*
* 문제 설명 및 링크
https://www.acmicpc.net/problem/2234
방의 이동을 상하좌우 벽이 있는지 확인하는 문제이며
1. 이 성에 있는 방의 갯수
2. 가장 넓은 방의 넓이
3. 하나의 벽을 제거하여 얻을 수 있는 가장 넓은 방의 크기
를 구하면 된다.
=> BFS를 통해 방을 구역별로 나눈다.
=> 구역별로 나눈다면 1번과 2번을 수행할 수 있다.
=> 구역별로 나눈 방의 갯수를 전부 구해두고
=> 인접한 방이라면 2방을 더해 3번을 수행한다.
*/
/*
* 소감
*/

int N, M;
int arr[51][51];
int rooms[51][51] = { 0 };
int visited[51][51];
int rooms_size[10000] = { 0 };
//서북동남
int dy[4] = { 0,-1,0,1 };
int dx[4] = { -1,0,1,0 };

void BFS(int sy, int sx, int value) {
	queue<pair<int, int>> q;
	q.push({ sy,sx });
	visited[sy][sx] = 1;
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		rooms[y][x] = value;
		for (int i = 0; i < 4; i++) {
			if ((arr[y][x] & (1 << i))) continue;
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny >= 0 && nx >= 0 && ny < N && nx < M && !visited[ny][nx]) {
				visited[ny][nx] = 1;
				q.push({ ny,nx });
			}
		}
	}
}
void solution() {
	cin >> M >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}
	int room = 1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (visited[i][j]) continue;
			BFS(i, j, room++);
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			rooms_size[rooms[i][j]]++;
		}
	}
	int mmaaxx = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			for (int k = 0; k < 4; k++) {
				int ni = i + dy[k];
				int nj = j + dx[k];
				if (ni >= 0 && ni < N && nj >= 0 && nj < M && rooms[i][j] != rooms[ni][nj]) {
					mmaaxx = max(mmaaxx, rooms_size[rooms[i][j]] + rooms_size[rooms[ni][nj]]);
				}
			}
		}
	}
	int maxv = 0;
	for (int i = 1; i < room; i++) {
		maxv = max(maxv, rooms_size[i]);
	}
	cout << room - 1 << endl;
	cout << maxv << endl;
	cout << mmaaxx;
}

int main() {

	cin.tie(NULL); ios_base::sync_with_stdio(false);
	solution();
	return 0;
}

