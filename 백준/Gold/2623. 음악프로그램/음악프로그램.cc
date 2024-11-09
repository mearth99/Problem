#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<queue>
using namespace std;


int N, M;
vector<int> arr[1001];
vector<int> output;
int cnt[1001];
void solution() {
	queue<int> singer;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int cmd, from, to;
		cin >> cmd;
		cin >> from;
		for (int i = 1; i < cmd; i++) {
			cin >> to;
			arr[from].push_back(to);
			cnt[to]++;
			from = to;
		}
	}
	for (int i = 1; i <= N; i++) {
		if (!cnt[i]) singer.push(i);
	}
	if (singer.empty()) cout << 0;
	while (!singer.empty()) {
		int cur = singer.front();
		output.push_back(cur);
		singer.pop();
		for (auto it : arr[cur]) {
			cnt[it]--;
			if (!cnt[it]) singer.push(it);
		}
	}
	if (output.size() != N) cout << 0;
	else {
		for (auto it : output) {
			cout << it << '\n';
		}
	}
}

int main() {
	cout.tie(nullptr);
	cin.tie(nullptr); ios_base::sync_with_stdio(false);
	solution();
	return 0;
}