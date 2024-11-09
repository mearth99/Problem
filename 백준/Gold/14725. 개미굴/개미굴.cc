#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>


using namespace std;

struct Trie {
	map<string, Trie*> next;

	void insert(vector<string>& str, int strsize, int index) {
		if (strsize <= index) return;
		auto iter = next.find(str[index]);

		if (iter == next.end()) {
			Trie* newTrie = new Trie;
			next[str[index]] = newTrie;
			newTrie->insert(str, strsize, index + 1);
		}
		else {
			iter->second->insert(str, strsize, index + 1);
		}
	}
	void Print(int level) {
		for (auto& it : next) {
			for (int i = 0; i < level; i++) {
				cout << "--";
			}
			cout << it.first << "\n";
			it.second->Print(level + 1);
		}
	}
};

int N,K;

void solution() {
	cin >> N;
	Trie* root = new Trie;
	for (int i = 0; i < N; i++) {
		cin >> K;
		vector<string> vect(K);
		for (int i = 0; i < K; i++) cin >> vect[i];
		root->insert(vect, K, 0);
	}
	root->Print(0);
		

}

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	solution();
	return 0;
}