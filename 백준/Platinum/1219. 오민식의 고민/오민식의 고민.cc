#include<iostream>
#include<vector>
#include<cstring>
#include<queue>
using namespace std;
int N, M, from, to, INF = -999999999;
long long minCost[51];
int map[51];
bool visited[51], Geecheck[51];
bool check = false;
vector<vector<pair<int, int>>> Edge;
void bellman(int start) {
	fill(minCost, minCost + N + 1, INF);
	minCost[start] = map[start];

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int current = j;
			for (auto e : Edge[j]) {
				int next = e.first;
				int cost = e.second;
				long long nextCost = cost + minCost[current] + map[next];
				if (minCost[current] != INF && minCost[next] < nextCost) {
					minCost[next] = nextCost;
					if (i == N - 1) Geecheck[j] = true;
				}
			}
		}
	}
}
void bfs() {
	queue<int> q;
	for (int i = 0; i < N; i++) {
		if (Geecheck[i]) {
			visited[i] = true;
			q.push(i);
		}
	}
	while (!q.empty()) {
		int current = q.front();
		q.pop();
		if (current == to) {
			check = true;
			break;
		}

		for (auto e : Edge[current]) {
			int next = e.first;
			if (!visited[next]) {
				q.push(next);
				visited[next] = true;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> from >> to >> M;
	Edge.resize(N);
	for (int i = 0; i < M; i++) {
		int x, y, cost;
		cin >> x >> y >> cost;
		Edge[x].push_back(make_pair(y, -cost));
	}
	for (int i = 0; i < N; i++) {
		cin >> map[i];
	}
	
	bellman(from);
	bfs();

	if (minCost[to] == INF) cout << "gg";
	else {
		if (check) cout << "Gee";
		else cout << minCost[to];
	}

}