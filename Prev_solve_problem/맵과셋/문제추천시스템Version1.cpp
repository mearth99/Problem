#include<iostream>
#include<algorithm>
#include<set>
#include<unordered_map>
using namespace std;
int N;


struct Code {
	int id, difficult;
	Code(int _id, int _diff) : id(_id), difficult(_diff) {}
	bool operator<(const Code& opp) const {
		return difficult == opp.difficult ? id < opp.id : difficult < opp.difficult;
	}
};
unordered_map<int, int> unmap;
set<Code> sets;
void solution() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int num, v;
		cin >> num >> v;
		sets.insert(Code(num, v));
		unmap[num] = v;
	}
	int M;
	cin >> M;
	for (int i = 0; i < M; i++) {
		string cmd;
		int num, v;
		cin >> cmd;
		if (cmd == "add") {
			cin >> num >> v;
			sets.insert(Code(num, v));
			unmap[num] = v;
		}
		else if (cmd == "recommend") {
			cin >> num;
			auto it = num == 1 ? *sets.rbegin() : *sets.begin();
			cout << it.id << '\n';
		}
		else {
			cin >> num;
			int v = unmap[num];
			sets.erase(Code(num, v));
		}
	}
}

int main() {
	cout.tie(nullptr);
	cin.tie(nullptr); ios_base::sync_with_stdio(false);
	solution();
	return 0;
}