#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<map>

using namespace std;

int N,M;
map<string, int> map1;
map<int, string> map2;
void solution() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		string str;
		cin >> str;
		map1[str] = i;
		map2[i] = str;
	}
	for (int i = 0; i < M; i++) {
		string temp;
		cin >> temp;
		if (temp.at(0) >= 'A' && temp.at(0) <= 'Z') {
			cout << map1[temp] << '\n';
		}
		else {
			cout << map2[stoi(temp)] << '\n';
		}
	}
	
}

int main() {
	cout.tie(nullptr);
	cin.tie(nullptr); ios_base::sync_with_stdio(false);
	solution();
	return 0;
}