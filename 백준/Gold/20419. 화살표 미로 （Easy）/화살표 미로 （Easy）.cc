#include <iostream>
#include <string>
using namespace std;
bool flag = false;
int R, C, K;
char arr[51][51];
int visited[51][51][4];
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };
pair<int, int> rotation(int y, int x, char target, int gap) {
	int ny, nx;
	switch (target) {
	case 'U':
		ny = y + dy[0 + gap == -1 ? 3 : 0 + gap];
		nx = x + dx[0 + gap == -1 ? 3 : 0 + gap];
		break;
	case 'R':
		ny = y + dy[1 + gap];
		nx = x + dx[1 + gap];
		break;
	case 'D':
		ny = y + dy[2 + gap];
		nx = x + dx[2 + gap];
		break;
	case 'L':
		ny = y + dy[3 + gap == 4 ? 0 : 3 + gap];
		nx = x + dx[3 + gap == 4 ? 0 : 3 + gap];
		break;
	}
	return { ny,nx };
}
void DFS(int y, int x, int someL, int someR) {
	if (flag) return;
	if (y == R - 1 && x == C - 1) {
		flag = true;
		return;
	}

	for (int i = -1; i <= 1; i++) {
		int nL = someL;
		int nR = someR;
		if (i == -1) {
			if (nL == 0) continue;
			nL = 0;
		}
		else if (i == 1) {
			if (nR == 0) continue;
			nR = 0;
		}
		pair<int, int> t = rotation(y, x, arr[y][x], i);
		int ny = t.first;
		int nx = t.second;
		if (ny >= 0 && nx >= 0 && ny < R && nx < C && !visited[ny][nx][nL + nR * 2]) {
			visited[ny][nx][nL + nR * 2] = 1;
			DFS(ny, nx, nL, nR);
		}
	}
	return;
}
int main()
{
	cin >> R >> C >> K;
	for (int i = 0; i < R; i++) {
		string temp;
		cin >> temp;
		for (int j = 0; j < C; j++) {
			arr[i][j] = temp.at(j);
		}
	}
	visited[0][0][K + 2 * K] = 1;
	DFS(0, 0, K, K);
	if (flag) cout << "Yes";
	else cout << "No";
	return 0;
}