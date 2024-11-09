#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<queue>
using namespace std;

int N, K;
vector<vector<pair<int, int>>> arr;
int Parent[100001][18];
int depth[100001];
pair<int,int> cost[100001][18];
int A, B, C;


void DFS(int cur, int parent) {
	Parent[cur][0] = parent;
	depth[cur] = depth[parent] + 1;
	for (auto it : arr[cur]) {
		if (it.first ==parent) continue;
		cost[it.first][0] = make_pair(it.second, it.second);
		DFS(it.first, cur);
	}
}

void DP() {
	for (int i = 1; i < 18; i++) {
		for (int j = 1; j <= N; j++) {
			if (Parent[j][i - 1] == -1) continue;
			Parent[j][i] = Parent[Parent[j][i - 1]][i - 1];
			cost[j][i].first = min(cost[j][i-1].first, cost[Parent[j][i - 1]][i - 1].first);
			cost[j][i].second = max(cost[j][i-1].second, cost[Parent[j][i - 1]][i - 1].second);
		}
	}
}

pair<int,int> LCA(int start, int end) {
	pair<int, int> output = { 1e9,0 };
	if (depth[start] > depth[end])
		swap(start, end);
	int diff = depth[end] - depth[start];
	for (int i = 17; i >= 0; i--) {
		if ( diff & ((1 << i))) {	
			output.first = min(output.first, cost[end][i].first);
			output.second = max(output.second, cost[end][i].second);
			end = Parent[end][i];
		}
	}
	if (start == end) return output;
	for (int i = 17; i >= 0; i--) {
		if (Parent[start][i] != Parent[end][i] ) {	
			output.first = min({ output.first, cost[end][i].first, cost[start][i].first });
			output.second = max({ output.second, cost[end][i].second,cost[start][i].second });
			start = Parent[start][i];
			end = Parent[end][i];
		}
	}
	output.first = min({output.first, cost[end][0].first, cost[start][0].first });
	output.second = max({ output.second, cost[end][0].second,cost[start][0].second });
	return output;
}

void solution() {
	cin >> N;
	arr.resize(N+1);
	for (int i = 0; i < N-1; i++) {
		cin >> A >> B >> C;
		arr[A].push_back({ B,C });
		arr[B].push_back({ A,C });
	}
	fill(&Parent[0][0], &Parent[100000][17], -1);
	fill(&cost[0][0], &cost[100000][17], make_pair(0x7fffffff, 0));
	DFS(1,-1);
	DP();
	cin >> K;
	for (int i = 0; i < K; i++) {
		int D, E;
		cin >> D >> E;
		pair<int,int> output = LCA(D, E);
		cout << output.first << " " << output.second << '\n';
	}
	
}

int main() {
	cout.tie(nullptr);
	cin.tie(nullptr); ios_base::sync_with_stdio(false);
	solution();
	return 0;
}