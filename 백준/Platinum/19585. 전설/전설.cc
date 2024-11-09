#include<iostream>
#include<algorithm>
#include<unordered_map>

using namespace std;


unordered_map<string, bool> Name;

struct Trie {
	Trie* next[26] = {};
	bool is_end = false;

	void insert(const string& s) {
		Trie* node = this;
		for (char it : s) {
			if (!node->next[it - 'a']) node->next[it - 'a'] = new Trie();
			node = node->next[it - 'a'];
		}
		node->is_end = true;
	}
	bool search(const string& s) {
		Trie* node = this;
		int v = -1;
		for (char it : s) {
			if (!node->next[it - 'a']) return false;
			node = node->next[it - 'a'];
			v++;
			if (node->is_end && Name[s.substr(v + 1)]) return true;
		}
		return false;
	}
};

int C, N, Q;
string str;

void solution() {
	cin >> C >> N;
	Trie *trie = new Trie();
	for (int i = 0; i < C; i++) {
		cin >> str;
		trie->insert(str);
	}
	for (int i = 0; i < N; i++) {
		cin >> str;
		Name[str] = true;
	}
	cin >> Q;
	for (int i = 0; i < Q; i++) {
		cin >> str;
		if (trie->search(str)) cout << "Yes\n";
		else cout << "No\n";
	}

}

int main() {
	cout.tie(nullptr);
	cin.tie(nullptr); ios_base::sync_with_stdio(false);
	solution();
	return 0;
}