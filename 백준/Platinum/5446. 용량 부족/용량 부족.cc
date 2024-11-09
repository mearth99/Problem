#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
#include <set>
using namespace std;

int cnt = 0;
struct Trie {
	unordered_map<char, Trie*> next;
	bool OK = false;
	bool OK_End = false;
	bool Not_Delete = false;
	~Trie() {
		for (auto& pair : next)
			delete pair.second;
	}
	void Insert(const string& cur, bool flag) {
		Trie* node = this;
		for (char it : cur) {
			if (!node->next[it]) {
				flag ? node->OK = true : node->Not_Delete = true;
				node->next[it] = new Trie();
				node = node->next[it];
			}
			else {
				flag ? node->OK = true : node->Not_Delete = true;
				node = node->next[it];
			}
		}
		flag ? node->OK = true : node->Not_Delete = true;
		if(flag) node->OK_End = true;
	}
	void Seek() {
		if (OK_End) cnt++;
		else if (!Not_Delete) cnt++;
		if (Not_Delete) {
			for (auto it : next)
				if (it.second->OK) it.second->Seek();
		}
	}
};


void solution() {
	int T;
	cin >> T;
	string str;
	while (T--) {
		int N, M;
		cin >> N;
		cnt = 0;
		Trie* root = new Trie();
		for (int i = 0; i < N; i++) {
			cin >> str;
			root->Insert(str,1);
		}
		cin >> M;
		for (int i = 0; i < M; i++) {
			cin >> str;
			root->Insert(str, 0);
		}
		root->Seek();
		cout << cnt << '\n';
		delete root;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	solution();
	return 0;
}