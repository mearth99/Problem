#include<iostream>
#include<algorithm>
#include<string>
#include<queue>
#include<unordered_map>
#include<map>
#define MAX 0x7fffffff
using namespace std;
map<int, int> Q;
void solution() {
	int T;
	cin >> T;
	while (T--) {
		Q.clear();
		int N;
		cin >> N;
		for (int i = 0; i < N; i++) {
			char cmd;
			int v;
			cin >> cmd >> v;
			if (cmd == 'I') {
				Q[v]++;
			}
			else {
				if (Q.empty()) continue;
				auto it = (v == 1) ? Q.rbegin()->first : Q.begin()->first;
				Q[it]--;
				if (!Q[it]) Q.erase(it);
			}
		}
		if (Q.empty()) cout << "EMPTY\n";
		else cout << Q.rbegin()->first << " " << Q.begin()->first << '\n';
	}
}

int main() {
	cout.tie(nullptr);
	cin.tie(nullptr); ios_base::sync_with_stdio(false);
	solution();
	return 0;
}