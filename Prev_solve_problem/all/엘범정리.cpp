#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
using namespace std;


struct ALBUM {
	map<string, ALBUM> album;
	set<string> Photo;
	string name;
	ALBUM* parent;
	ALBUM(string _name) : album({}), Photo({}), name(_name), parent(NULL) {};
	ALBUM() : album({}), Photo({}), parent(NULL), name("") {};
};

ALBUM album;
ALBUM *current;

vector<string> outputs;
pair<int,int> DFSDelect(ALBUM cur) {
	if (cur.album.size() == 0) {
		int v = cur.Photo.size();
		cur.Photo.clear();
		return { 1,v };
	}
	else {
		pair<int, int> sum = { 0,0 };
		for (auto it : cur.album) {
			pair<int, int> temp = DFSDelect(it.second);
			sum.first += temp.first;
			sum.second += temp.second;
		}
		cur.album.clear();
		sum.first += 1;
		sum.second += cur.Photo.size();
		cur.Photo.clear();
		return sum;
	}
}


void mkalb() {
	string S;
	cin >> S;
	if (current->album.find(S) == current->album.end()) {
		current->album[S] = ALBUM(S);
		current->album[S].parent = current;
	}
	else
		outputs.push_back("duplicated album name");
}
void rmalb() {
	string S;
	cin >> S;
	int a = 999;
	if (S.at(0) == '-' || S.at(0) == '0' || S.at(0) == '1')
		a = stoi(S);
	if (a == -1) {
		if (current->album.empty()) {
			outputs.push_back("0 0");
			return;
		}
		pair<int,int> output = DFSDelect(current->album.begin()->second);
		current->album.erase(current->album.begin());
		outputs.push_back(to_string(output.first) + ' ' + to_string(output.second));
	}
	else if (a == 0) {
		pair<int, int> sum = { 0,0 };
		while (!current->album.empty()) {
			pair<int, int> output = DFSDelect(current->album.begin()->second);
			sum.first += output.first;
			sum.second += output.second;
			current->album.erase(current->album.begin());
		}
		outputs.push_back(to_string(sum.first) + ' ' + to_string(sum.second));
	}
	else if (a == 1) {
		if (current->album.empty()) {
			outputs.push_back("0 0");
			return;
		}
		pair<int, int> output = DFSDelect(current->album.rbegin()->second);
		current->album.erase(current->album.rbegin()->first);
		outputs.push_back(to_string(output.first) + ' ' + to_string(output.second));
	}
	else {
		if (current->album.find(S) != current->album.end()) {
			pair<int, int> output = DFSDelect(current->album[S]);
			current->album.erase(S);
			outputs.push_back(to_string(output.first) + ' ' + to_string(output.second));
		}
		else {
			outputs.push_back("0 0");
			return;
		}
	}
}
void insert() {
	string S;
	cin >> S;
	if (current->Photo.find(S) == current->Photo.end()) {
		current->Photo.insert(S);
	}
	else {
		outputs.push_back("duplicated photo name");
	}
}
void Delete() {
	string S;
	cin >> S;
	int a = 999;	
	if(S.at(0) == '-' || S.at(0) == '0' || S.at(0) == '1')
		a = stoi(S);
	if (a == -1) {
		if (current->Photo.empty()) {
			outputs.push_back("0");
			return;
		}
		auto key = current->Photo.begin();
		current->Photo.erase(key);
		outputs.push_back("1");
	}
	else if (a == 0) {
		outputs.push_back(to_string(current->Photo.size()));
		current->Photo.clear();
	}
	else if (a == 1) {
		if (current->Photo.empty()) {
			outputs.push_back("0");
			return;
		}
		auto key = current->Photo.rbegin();
		current->Photo.erase(*key);
		outputs.push_back("1");
	}
	else {
		if (current->Photo.find(S) != current->Photo.end()) {
			current->Photo.erase(S);
			outputs.push_back("1");
		}
		else {
			outputs.push_back("0");
		}
	}
}
void ca() {
	string S;
	cin >> S;
	if (S.compare("..") == 0) {
		if (current->parent)
			current = current->parent;

	}
	else if (S.compare("/") == 0) {
		current = &album;
	}
	else {
		if (current->album.find(S) != current->album.end())
			current = &current->album[S];
	}
	outputs.push_back(current->name);
}
void solution() {
	int N;
	cin >> N;
	string cmd;
	album = ALBUM("album");
	current = &album;
	for (register int i = 0; i < N; i++) {
		cin >> cmd;
		if (cmd == "mkalb") {
			mkalb();
		}
		else if (cmd == "rmalb") {
			rmalb();
		}
		else if (cmd == "insert") {
			insert();
		}
		else if (cmd == "delete") {
			Delete();
		}
		else if (cmd == "ca") {
			ca();
		}
	}
	for (auto& it : outputs)
		cout << it << '\n';
}

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	solution();
	return 0;
}