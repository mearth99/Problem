#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<algorithm>
#include<cstring>
using namespace std;

/*
* 문제 설명 및 링크
https://www.acmicpc.net/problem/15971
1. robot1의 갈수있는 곳의 cost 배열
2. robot2의 갈수있는 곳의 cost 배열
3. DFS를 순회화며 Miv 확인.
*/
/*
* 소감
1,2,3대로 풀림
*/

int N, s1, s2, Minv = INT32_MAX;
int robot1[100001];
int robot2[100001];

int visit[100001];

vector<pair<int, int>> child[100001];

void DFSVal(int c, int v, int types) {
	if (!types)
		robot1[c] = v;
	else
		robot2[c] = v;
	for (auto it : child[c]) {
		if (!visit[it.first]) {
			visit[it.first] = 1;
			DFSVal(it.first, v + it.second, types);
		}
	}
}
void DFS(int c) {
	Minv = min(robot1[c] + robot2[c], Minv);
	for (auto it : child[c]) {
		if (!visit[it.first]) {
			visit[it.first] = 1;
			Minv = min(robot1[c] + robot2[it.first], Minv);
			Minv = min(robot2[c] + robot1[it.first], Minv);
			DFS(it.first);
		}
	}
}
void solution() {
	cin >> N >> s1 >> s2;
	for (int i = 0; i < N - 1; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		child[from].push_back({ to,cost });
		child[to].push_back({ from,cost });
	}
	visit[s1] = 1;
	DFSVal(s1, 0, 0);
	memset(visit, 0, sizeof(visit));
	visit[s2] = 1;
	DFSVal(s2, 0, 1);
	memset(visit, 0, sizeof(visit));
	DFS(s1);
	cout << Minv;
}

int main() {

	cin.tie(NULL); ios_base::sync_with_stdio(false);
	solution();
	return 0;
}

