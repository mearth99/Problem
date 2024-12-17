#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N;
int arr[11][11];
int visit[11][11][4];
vector<pair<int, int>> v;
int minv = INT32_MAX;
struct moves {
	int y, x, dir, cnt, idx;
};
int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };

void Search(int y, int x, int dir, int cnt, int idx){
	if(arr[y][x] == idx){
		idx++;
		if (idx == v.size()) {
			minv = min(minv, cnt);
			return;
		}
	}
	int ny = y + dy[dir];
	int nx = x + dx[dir];
	if (ny >= 0 && ny < N && nx >= 0 && nx < N && visit[ny][nx][dir] < idx) {
		int baup = visit[ny][nx][dir];
		visit[ny][nx][dir] = idx;
		Search(ny,nx,dir,cnt,idx);
		visit[ny][nx][dir] = baup;
	}
	int ndir = (dir == 3) ? 0 : dir + 1;
	ny = y + dy[ndir];
	nx = x + dx[ndir];
	if (ny >= 0 && ny < N && nx >= 0 && nx < N && visit[ny][nx][ndir] < idx) {
		int baup = visit[ny][nx][ndir];
		visit[ny][nx][ndir] = idx;
		Search(ny,nx,ndir,cnt+1,idx);
		visit[ny][nx][ndir] = baup;
	}
}

int Search() {
	queue<moves> q;
	q.push({ 0,0,0,0,1 });
	while (!q.empty()) {
		int y = q.front().y;
		int x = q.front().x;
		int dir = q.front().dir;
		int cnt = q.front().cnt;
		int idx = q.front().idx;
		q.pop();
		if (arr[y][x] == idx) {
			idx++;
			if (idx == v.size()) {
				minv = min(minv, cnt);
				continue;
			}
		}
		int ny = y + dy[dir];
		int nx = x + dx[dir];
		if (ny >= 0 && ny < N && nx >= 0 && nx < N && visit[ny][nx][dir] < idx) {
			visit[ny][nx][dir] = idx;
			q.push({ ny,nx,dir,cnt,idx });
		}
		int ndir = (dir == 3) ? 0 : dir + 1;
		ny = y + dy[ndir];
		nx = x + dx[ndir];
		if (ny >= 0 && ny < N && nx >= 0 && nx < N && visit[ny][nx][ndir] < idx) {
			visit[ny][nx][ndir] = idx;
			q.push({ ny,nx,ndir,cnt + 1, idx });
		}
	}
	return minv;
}

int solution() {
	minv = INT32_MAX;
	cin >> N;
	v.push_back({ 0,0 });
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
			if (arr[i][j] > 0) {
				v.push_back({ i,j });
			}
			for (int k = 0; k < 4; k++)
				visit[i][j][k] = 0;
		}
	}
	Search(0,0,0,0,1);
	return minv;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t, th=1;
	cin >> t;

	while (t--) {
		v.clear();
		cout << '#' << th++ << ' ' << solution() << endl;
	}
	return 0;
}

