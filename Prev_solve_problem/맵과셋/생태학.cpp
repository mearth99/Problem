#include<iostream>
#include<algorithm>
#include<string>
#include<map>
using namespace std;

map<string, int> trees;
void solution() {
	string name;
	int cnt = 0;
	while (getline(cin, name)) {
		trees[name]++;
		cnt++;
	}
	cout << fixed;
	cout.precision(4);
	for (auto it : trees) {
		cout << it.first << ' ' << ((double)it.second) * 100 / ((double)cnt) << '\n';
	}
}

int main() {
	cout.tie(nullptr);
	cin.tie(nullptr); ios_base::sync_with_stdio(false);
	solution();
	return 0;
}