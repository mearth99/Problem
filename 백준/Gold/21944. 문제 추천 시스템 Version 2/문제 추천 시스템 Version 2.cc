#include<iostream>
#include<algorithm>
#include<set>
#include<map>
#include<unordered_map>
using namespace std;
int N;


struct Code {
	int id, difficult, algorithm;
	Code(int _id, int _diff, int _algorithm) : id(_id), difficult(_diff), algorithm(_algorithm) {}
};

struct cmp {
	bool operator()(const Code& a, const Code& b) const {
		return a.difficult == b.difficult ? a.id < b.id : a.difficult < b.difficult;
	}
};
struct cmp2 {
	bool operator()(const Code& a, const Code& b) const {
		return a.id < b.id;
	}
};
unordered_map<int, pair<int,int>> unmap;
set<Code, cmp> sets;
map<int, set<Code, cmp>> maps;
map<int, set<Code, cmp2>> maps2;
void solution() {
	cin >> N;
	int num, v, diff;
	for (int i = 0; i < N; i++) {
		cin >> num >> v >> diff;
		Code cur = Code(num, v, diff);
		sets.insert(cur);
		maps[diff].insert(cur);
		maps2[v].insert(cur);
		unmap[num] = { v,diff };
	}
	int M;
	cin >> M;
	for (int i = 0; i < M; i++) {
		string cmd;
		cin >> cmd;
		if (cmd == "add") {
			cin >> num >> v >> diff;
			Code cur = Code(num, v, diff);
			sets.insert(cur);
			maps[diff].insert(cur);
			maps2[v].insert(cur);
			unmap[num] = { v,diff };
		}
		else if (cmd == "recommend") {
			cin >> num >> v;
			auto it = v == 1 ? *(maps[num].rbegin()) : *(maps[num].begin());
			cout << it.id << '\n';
		}
		else if (cmd == "recommend2") {
			cin >> num;
			auto it = num == 1 ? *sets.rbegin() : *sets.begin();
			cout << it.id << '\n';
		}
		else if (cmd == "recommend3") {
			cin >> num >> v;
			auto lw = maps2.lower_bound(v);
			if (lw == maps2.end() && num == 1) {
				cout << -1 << '\n';
				continue;
			}
			if (num == -1 && lw == maps2.begin()) {
				cout << -1 << '\n';
				continue;
			}
			if(num == -1) lw--;
			auto it = num == 1 ? *lw->second.begin() : *lw->second.rbegin();
			cout << it.id << '\n';
		}
		else {
			cin >> num;
			pair<int,int> v = unmap[num];
			Code cur = Code(num, v.first, v.second);
			sets.erase(cur);
			maps[cur.algorithm].erase(cur);
			if (maps[cur.algorithm].empty())
				maps.erase(cur.algorithm);
			maps2[cur.difficult].erase(cur);
			if (maps2[cur.difficult].empty())
				maps2.erase(cur.difficult);
			unmap.erase(num);
		}
	}
}

int main() {
	cout.tie(nullptr);
	cin.tie(nullptr); ios_base::sync_with_stdio(false);
	solution();
	return 0;
}