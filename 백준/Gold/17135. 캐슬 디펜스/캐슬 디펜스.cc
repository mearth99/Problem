#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<algorithm>
using namespace std;

/*
* 문제 설명 및 링크
https://www.acmicpc.net/problem/17135
1. N*M임
2. 궁수를 잘 배치하여 적을 겹치지 않고 최대한 잘 잡을 수 있는가?
3. 거리가 가장 가까우면서, 동일하다면 가장 왼쪽임.
4. 궁수의 위치를 DFS를 통해 배치하며 결과를 진행해보자!
*/
/*
* 소감
*/
int N, M, D;
vector<vector<int>> arr(16, vector<int>(16, 0));
vector<vector<int>> arr_play(16, vector<int>(16, 0));

int dy[3] = { 0,-1,0 };
int dx[3] = { -1,0,1 };

int output = -1;

pair<int, int> attack(int arrow, int height) {
	int sy = height + 1;
	int sx = arrow;
	pair<int, int> shot;
	int minv = 987654;
	queue<pair<int, pair<int, int>>> q;
	q.push({ 0,{sy,sx} });
	int visited[16][16] = { 0 };
	while (!q.empty()) {
		int distan = q.front().first;
		int y = q.front().second.first;
		int x = q.front().second.second;
		q.pop();
		if (distan >= D) continue;
		for (int i = 0; i < 3; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny >= 0 && ny <= height && nx >= 0 && nx < M && !visited[ny][nx]) {
				if (arr[ny][nx] == 1) {
					return { ny,nx };
				}
				else {
					visited[ny][nx] = 1;
					q.push({ distan + 1, {ny,nx} });
				}
			}
		}
	}
	return { -1,-1 };
}

vector<int> anchor(3);
void Game() {
	int kills = 0;
	vector<pair<int, int>> atk_wait;
	for (int i = N - 1; i >= 0; i--) {
		for (int idx = 0; idx < 3; idx++) {
			pair<int, int> t = attack(anchor[idx], i);
			if (t.first == -1) continue;
			atk_wait.push_back(t);
		}
		for (auto it : atk_wait) {
			if (arr[it.first][it.second] == 1) {
				kills++;
				arr[it.first][it.second] = 0;
			}
		}
	}

	output = max(kills, output);
}
void solution() {
	cin >> N >> M >> D;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr_play[i][j];
		}
	}
	vector<int> arrow(M, 0);
	vector<int> temp(M, 0);

	for (int i = 0; i < M; i++)
		arrow[i] = i;

	temp[0] = temp[1] = temp[2] = 1;
	do {
		int anchor_idx = 0;
		for (int i = 0; i < M; ++i) {
			if (temp[i] == 1)
				anchor[anchor_idx++] = i;
		}
		arr = arr_play;
		Game();
	} while (prev_permutation(temp.begin(), temp.end()));
	cout << output;
}

int main() {

	cin.tie(NULL); ios_base::sync_with_stdio(false);
	solution();
	return 0;
}

