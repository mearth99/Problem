#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>


using namespace std;
bool output = true;
struct Trie {
	map<char, Trie*> next;
	bool is_end = false;
	void insert(string str, int strsize, int index) {
		if (strsize <= index) return;
		auto iter = next.find(str[index]);
		if (iter == next.end()) {
			Trie* newTrie = new Trie;
			if (index == strsize - 1) {
				is_end = true;
			}
			next[str[index]] = newTrie;
			newTrie->insert(str, strsize, index + 1);
		}
		else {
			if (is_end) 
				output = false;
			iter->second->insert(str, strsize, index + 1);
		}
		return;
	}
};

int N, K;
vector<string> vect;
void solution() {
	cin >> N;
	Trie* root = new Trie;
	output = true;
	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		vect.push_back(str);
	}
	sort(vect.begin(), vect.end(), [](const string& p1, const string& p2) {return p1.size() < p2.size(); });
	for (auto it : vect) {
		if(output)
			root->insert(it, it.size(), 0);
	}
	if (output) cout << "YES\n";
	else cout << "NO\n";
	delete root;
	vect.clear();
}

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	while(T--)
		solution();
	return 0;
}