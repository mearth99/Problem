#include<iostream>
#include<vector>
#include<string>
#include<queue>
using namespace std;

/*
* 문제 설명 및 링크
https://www.acmicpc.net/problem/16929
점 색과 동일한 사이클이 있는지 판별하는 문제다.
4개 이상의 동일한 점이 사이클을 만드는지 판별하고
이를 확인하기 위해서 DFS를 통해 검사하면 될 것 같다.
시간 제한은 2초이며 N과 M은 50, 50이 최대이다.
*/
/*
* 소감
*/

int N, M;
int arr[51][51];
int visited[51][51];
int flag = false;

int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

void DFS(int sy, int sx, int y, int x, int color, int levels) {
	if (flag) return;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny >= 0 && nx >= 0 && ny < N && nx < M && arr[ny][nx] == color) {
			if (ny == sy && nx == sx && levels >= 4) {
				flag = true;
				return;
			}
			if (!visited[ny][nx]) {
				visited[ny][nx] = 1;
				DFS(sy, sx, ny, nx, color, levels + 1);
				visited[ny][nx] = 0;
			}
		}
	}
}

void solution() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			char temp;
			cin >> temp;
			arr[i][j] = temp - 'A';
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			visited[i][j] = 1;
			DFS(i, j, i, j, arr[i][j], 1);
			visited[i][j] = 0;
		}
	}
	if (flag) cout << "Yes";
	else cout << "No";
}

int main() {

	cin.tie(NULL); ios_base::sync_with_stdio(false);
	solution();
	return 0;
}

