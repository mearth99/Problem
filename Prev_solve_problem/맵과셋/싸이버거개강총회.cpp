#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<unordered_map>

using namespace std;

string S, E, Q;
string times, name;
unordered_map<string, int> maps;
void solution() {
	int cnt = 0;
	cin >> S >> E >> Q;
	while (cin >> times >> name) {
		if (times <= S) {
			maps[name] = 1;
		}
		else if (times >= E && times <= Q) {
			if (maps[name]==1) {
				maps[name] = 2;
				cnt++;
			}
		}
	}
	cout << cnt;
}

int main() {
	cout.tie(nullptr);
	cin.tie(nullptr); ios_base::sync_with_stdio(false);
	solution();
	return 0;
}