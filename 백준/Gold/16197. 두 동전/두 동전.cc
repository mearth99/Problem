#include<iostream>

using namespace std;

int minv = 0x7fffffff;
int N, M;
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };
int arr[21][21];

void Backtracking(pair<int, int> p1, pair<int, int> p2, int dir, int cnt) {
	if (minv <= cnt || cnt > 10) return;
	if ((p1.first == -1 && p2.first != -1) || (p1.first != -1 && p2.first == -1)) {
		minv = cnt;
		return;
	}
	
	if (p1.first != -1) {
		if (p1.first + dy[dir] < 0 || p1.first + dy[dir] >= N || p1.second + dx[dir] < 0 || p1.second + dx[dir] >= M) p1 = { -1,-1 };
		else if (arr[p1.first + dy[dir]][p1.second + dx[dir]] == 0) p1 = { p1.first + dy[dir], p1.second + dx[dir] };
	}
	if (p2.first != -1) {
		if (p2.first + dy[dir] < 0 || p2.first + dy[dir] >= N || p2.second + dx[dir] < 0 || p2.second + dx[dir] >= M) p2 = { -1,-1 };
		else if (arr[p2.first + dy[dir]][p2.second + dx[dir]] == 0) p2 = { p2.first + dy[dir], p2.second + dx[dir] };
	}
	if (p1.first == -1 && p2.first == -1) return;
	for (int i = 0;i < 4;i++) {
		Backtracking(p1, p2, i, cnt + 1);
	}
}

void solution() {
	
	pair<int, int> coin[2] = { {-1,-1},{-1,-1} };
	cin >> N >> M;
	for (int i = 0;i < N;i++) {
			string str;
			cin >> str;
		for (int j = 0;j < M;j++) {
			if (str.at(j) == 'o') {
				if (coin[0].first == -1) coin[0] = { i,j };
				else coin[1] = { i,j };
			}
			else if (str.at(j) == '.') arr[i][j] = 0;
			else arr[i][j] = 1;
		}
	}
	for(int i=0;i<4;i++)
		Backtracking(coin[0], coin[1],i, 0);
	if (minv > 10) cout << -1;
	else cout << minv;
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	solution();

	return 0;
}