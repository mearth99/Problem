#include <iostream>
#include <vector>
#include <set>
#include <cstring>
#include <queue>
#include <unordered_map>
#include <algorithm>
using namespace std;

int visit[4][4];
int sum = 0;
string target = "";
unordered_map<string, bool> svisit;
vector<vector<char>> arr(4, vector<char>(4));

int dy[8] = { 0,0,-1,1,-1,-1,1,1 };
int dx[8] = { -1,1,0,0,-1,1,-1,1 };

int GetScore(int len) {
    if (len == 1 || len == 2) return 0;
    if (len == 3 || len == 4) return 1;
    if (len == 5) return 2;
    if (len == 6) return 3;
    if (len == 7) return 5;
    if (len == 8) return 11;
    return -1;
}

int mmpcnt = 0;
struct Trie {
    static Trie mmp[300001*7];
    Trie* next[26];
    bool isword;
    int score;

    Trie() {
        memset(next, 0, sizeof(next));
        isword = false;
        score = 0;
    }

    void insert(const string& str) {
        Trie* cur = this;
        for (auto it : str) {
            int idx = it - 'A';
            if (!cur->next[idx]) {
                cur->next[idx] = &mmp[mmpcnt++];
            }
            cur = cur->next[idx];
        }
        cur->isword = true;
        cur->score = GetScore(str.length());
    }
    bool search(const string& str) {
        Trie* cur = this;
        for (auto it : str) {
            int idx = it - 'A';
            if (!cur->next[idx]) {
                return false;
            }
            cur = cur->next[idx];
        }
        return cur->isword;
    }
};
Trie Trie::mmp[300001*7];
Trie root;

void DFS(int y, int x, string &cur) {
    if (cur.length() >= 9) return;
    bool result = root.search(cur);
    if (result)
        if (!svisit[cur]) {
            svisit[cur] = true;
            sum += GetScore(cur.length());
            if (target.length() < cur.length())
                target = cur;
            else if (target.length() == cur.length() && target > cur)
                target = cur;
        }
    for (int i = 0;i < 8;i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny >= 0 && ny < 4 && nx >= 0 && nx < 4 && !visit[ny][nx]) {
            visit[ny][nx] = 1;
            cur.push_back(arr[ny][nx]);
            DFS(ny, nx, cur);
            cur.pop_back();
            visit[ny][nx] = 0;
        }
    }

}


void solution() {
	int W;
    cin >> W;
    string str;
    for (int i = 0;i < W;i++) {
        cin >> str;
        root.insert(str);
    }
    int T;
    cin >> T;
    while (T--) {
        target = "";
        sum = 0;
        svisit.clear();
        for(auto &it: arr)
            for (auto& i : it) 
                cin >> i;
            
        for (int i = 0;i < 4;i++) {
            for (int j = 0; j < 4;j++) {
                memset(visit, 0, sizeof(visit));
                visit[i][j] = 1;
                string str(1, arr[i][j]);
                DFS(i, j, str);
            }
        }
        cout << sum << ' ' << target << ' ' << svisit.size() << '\n';
    }

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solution();
	return 0;
}