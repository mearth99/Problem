#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <stack>
#include <functional>
using namespace std;

int idx = 0;
int pos = 0;
int maxlen = 0;
int strpos = 0;
int flag = false;
int l = 0, r = 0;
vector<unsigned char> arr;
string cmd;
string str;
vector<int> cmdloop(4097);

void funct(char c){
    switch (c) {
    case '<': idx = idx - 1 < 0 ? maxlen : idx - 1; break;
    case '>': idx = idx + 1 > maxlen ? 0 : idx + 1; break;
    case '+': arr[idx]++; break;
    case '-': arr[idx]--; break;
    case '[':
        if (arr[idx] == 0) {
            l = pos;
            pos = cmdloop[pos];
            r = pos;
        }
        break;
    case ']':
        if (arr[idx] != 0) {
            r = pos;
            pos = cmdloop[pos];
            l = pos;
        }
        break;
    case '.': return;
    case ',': arr[idx] = strpos < str.length() ? str[strpos++] : 255; break;
    }
}
void solution() {
    int t;
    cin >> t;
    while (t--) {
        // 초기화
        flag = false;
        arr.clear();
        cmd.clear();
        str.clear();
        cmdloop.clear();
        cmdloop.resize(4097, 0);
        l = r = idx = pos = strpos = 0;

        int sm, sc, si, cnt = 0;
        cin >> sm >> sc >> si;
        cin >> cmd >> str;

        stack<int> st;
        for (int i = 0; i < cmd.length(); i++) {
            if (cmd[i] == '[') st.push(i);
            else if (cmd[i] == ']') {
                int source = st.top();
                st.pop();
                cmdloop[source] = i;
                cmdloop[i] = source;
            }
        }

        arr.resize(sm, 0);
        maxlen = sm - 1;

        // 첫 번째 실행
        for (; pos < cmd.length() && !flag; pos++) {
            funct(cmd[pos]);
            if (cnt++ > 50000000) flag = true;
        }

        if (!flag) {
            cout << "Terminates\n";
            continue;
        }

        // 루프 찾기
        int minv = pos, maxv = pos;
        cnt = 0;
        for (pos; pos < cmd.length(); pos++) {
            funct(cmd[pos]);
            if (cmd[pos] == '[' || cmd[pos] == ']') {
                minv = min(minv, min(l, pos));
                maxv = max(maxv, max(r, pos));
            }
            if (cnt++ > 50000000) break;
        }
        cout << "Loops " << minv << " " << maxv << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solution();
    return 0;
}