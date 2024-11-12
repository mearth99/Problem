#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;

const int MAX_LOOP = 50000000;
int t, sm, m, n;
unsigned char dat[100001];
string op, s;
int j[4097];
vector<int> stack;

int cnt, idx, p, it;
int l, r; // 루프의 시작과 끝을 저장하는 변수 추가

void init() {
    memset(dat, 0, sizeof(dat));
    memset(j, 0, sizeof(j));
    stack.clear();
    cnt = 0, idx = 0, p = 0, it = 0;
    l = r = 0; // l, r 초기화 추가

    for (int i = 0; i < m; i++) {
        if (op[i] == '[') stack.push_back(i);
        else if (op[i] == ']') {
            j[stack.back()] = i;
            j[i] = stack.back();
            stack.pop_back();
        }
    }
}

void solution() {
    bool flag = false;
    // 첫 번째 실행
    while (it < m && !flag) {
        if (op[it] == '-') dat[p]--;
        else if (op[it] == '+') dat[p]++;
        else if (op[it] == '<') {
            if (--p < 0) p = sm - 1;
        }
        else if (op[it] == '>') {
            if (++p == sm) p = 0;
        }
        else if (op[it] == '[') {
            if (!dat[p]) {
                l = it;
                it = j[it];
                r = it;
            }
        }
        else if (op[it] == ']') {
            if (dat[p]) {
                r = it;
                it = j[it];
                l = it;
            }
        }
        else if (op[it] == ',') {
            if (idx < n) dat[p] = s[idx++];
            else dat[p] = 255;
        }
        it++;
        if (cnt++ > MAX_LOOP) flag = true;
    }

    if (!flag) {
        cout << "Terminates\n";
        return;
    }

    // 무한 루프 찾기
    int minv = it, maxv = it;
    cnt = 0;
    
    while (it < m && cnt <= MAX_LOOP) {
        if (op[it] == '-') dat[p]--;
        else if (op[it] == '+') dat[p]++;
        else if (op[it] == '<') {
            if (--p < 0) p = sm - 1;
        }
        else if (op[it] == '>') {
            if (++p == sm) p = 0;
        }
        else if (op[it] == '[') {
            if (!dat[p]) {
                l = it;
                it = j[it];
                r = it;
            }
        }
        else if (op[it] == ']') {
            if (dat[p]) {
                r = it;
                it = j[it];
                l = it;
            }
        }
        else if (op[it] == ',') {
            if (idx < n) dat[p] = s[idx++];
            else dat[p] = 255;
        }
        
        if (op[it] == '[' || op[it] == ']') {
            minv = min(minv, min(l, it));
            maxv = max(maxv, max(r, it));
        }
        
        it++;
        cnt++;
    }
    
    cout << "Loops " << minv << " " << maxv << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    while (t--) {
        cin >> sm >> m >> n >> op >> s;
        init();
        solution();
    }
    return 0;
}