#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };
int arr[31][31];
int visited[31][31];
int	end_v = 0;
int min_levels;
void DFS(int sy, int sx, int levels, int sum, int dir) {
	// 먼저, sum를 확인한다.
	if (sum == end_v) {
		min_levels = min(min_levels, levels);
		return;
	}
	int ny = sy + dy[dir];
	int nx = sx + dx[dir];
	if (ny >= 0 && ny < N && nx >= 0 && nx < M && !visited[ny][nx] && arr[ny][nx]==1) {
		visited[ny][nx] = 1;
		DFS(ny, nx, levels, sum + 1, dir);
		visited[ny][nx] = 0;
	}
	else
		for (int i = 0; i < 4; i++) {
			if (i == dir) continue;
			ny = sy + dy[i];
			nx = sx + dx[i];
			if (ny >= 0 && ny < N && nx >= 0 && nx < M && !visited[ny][nx] && arr[ny][nx] == 1) {
				visited[ny][nx] = 1;
				DFS(ny, nx, levels + 1, sum + 1, i);
				visited[ny][nx] = 0;
			}
		}
	return;
}
int Solution() {
	end_v = 0;
	min_levels = INT32_MAX;

	vector<pair<int, int>> coord;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			char temp;
			cin >> temp;
			visited[i][j] = 0;
			if (temp == '*') {
				arr[i][j] = 0;
			}
			else {
				arr[i][j] = 1;
				coord.push_back({ i,j });
				end_v++;
			}
		}
	}
	if (end_v == 1) {
		return 0;
	}
	for (auto it : coord) {
		for (int i = 0; i < 4; i++) {
			visited[it.first][it.second] = 1;
			DFS(it.first, it.second, 1, 1, i);
			visited[it.first][it.second] = 0;
		}
	}
	if (min_levels == INT32_MAX)
		return -1;
	else
		return min_levels;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int i = 1;
	while(cin >> N >> M){
		cout << "Case " << i++ << ": " << Solution() << '\n';
	}
	return 0;
}