#include<iostream>
#include<vector>

using namespace std;

int N, maxv=0;

int Go(vector<vector<int>>& t, int dir) {
	int output = 0;
	int h = 0;
	bool flag = false;
	if (dir == 0) { //상
		for (int j = 0; j < N; j++) {
			h = 0;
			flag = false;
			while (1) {
				int nh = h + 1;
				if (nh == N) break;
				while (!t[nh][j]) {
					nh++;
					if (nh == N) {
						flag = true;
						break;
					}
				}
				if (flag) break;
				if (t[h][j] == t[nh][j]) {
					t[h][j] += t[nh][j];
					output = max(output, t[h][j]);
					t[nh][j] = 0;
				}
				if (t[h][j] == 0) {
					t[h][j] += t[nh][j];
					output = max(output, t[h][j]);
					t[nh][j] = 0;
					h--;
				}
				h++;
			}
		}
	}
	else if (dir == 1) { //하
		for (int j = 0; j < N; j++) {
			h = N-1;
			flag = false;
			while (1) {
				int nh = h -1;
				if (nh == -1) break;
				while (!t[nh][j]) {
					nh--;
					if (nh == -1) {
						flag = true;
						break;
					}
				}
				if (flag) break;
				if (t[h][j] == t[nh][j]) {
					t[h][j] += t[nh][j];
					output = max(output, t[h][j]);
					t[nh][j] = 0;
				}
				if (t[h][j] == 0) {
					t[h][j] += t[nh][j];
					output = max(output, t[h][j]);
					t[nh][j] = 0;
					h++;
				}
				h--;
			}
		}
	}
	else if (dir == 2) {//좌
		for (int j = 0; j < N; j++) {
			h = 0; //h를 W 처럼 사용
			flag = false;
			while (1) {
				int nh = h + 1;
				if (nh == N) break;
				while (!t[j][nh]) {
					nh++;
					if (nh == N) {
						flag = true;
						break;
					}
				}
				if (flag) break;
				if (t[j][h] == t[j][nh]) {
					t[j][h] += t[j][nh];
					output = max(output, t[j][h]);
					t[j][nh] = 0;
				}
				if (t[j][h] == 0) {
					t[j][h] += t[j][nh];
					output = max(output, t[j][h]);
					t[j][nh] = 0;
					h--;
				}
				h++;
			}
		}
	}
	else if (dir == 3) { // 우
		for (int j = 0; j < N; j++) {
			h = N-1; //h를 W 처럼 사용
			flag = false;
			while (1) {
				int nh = h - 1;
				if (nh == -1) break;
				while (!t[j][nh]) {
					nh--;
					if (nh == -1) {
						flag = true;
						break;
					}
				}
				if (flag) break;
				if (t[j][h] == t[j][nh]) {
					t[j][h] += t[j][nh];
					output = max(output, t[j][h]);
					t[j][nh] = 0;
				}
				if (t[j][h] == 0) {
					t[j][h] += t[j][nh];
					output = max(output, t[j][h]);
					t[j][nh] = 0;
					h++;
				}
				h--;
			}
		}
	}
	return output;
}



void DFS(vector<vector<int>> arr, int level) {
	if (level == 5) return;
	for (int i = 0; i < 4; i++) {
		vector<vector<int>> temp = arr;
		maxv = max(Go(temp, i),maxv);
		DFS(temp, level + 1);
	}
}


void solution() {
	cin >> N;
	vector<vector<int>> arr(N, vector<int>(N));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}
	if (N == 1) {
		cout << arr[0][0];
		return;
	}
	DFS(arr,0);
	cout << maxv;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	solution();
	return 0;
}