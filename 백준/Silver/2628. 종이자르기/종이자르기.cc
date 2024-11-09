#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#define INF 0x7fffffff
using namespace std;


void solution() {
    int W, H,N;
    cin >> W >> H;
    vector<int> lr;
    vector<int> ud;
    lr.push_back(0);
    lr.push_back(W);
    ud.push_back(0);
    ud.push_back(H);
    cin >> N;
    for (int i = 0; i < N; i++) {
        int cmd,v;
        cin >> cmd >> v;
        if (cmd == 0)
            ud.push_back(v);
        else
            lr.push_back(v);
    }
    sort(ud.begin(), ud.end());
    sort(lr.begin(), lr.end());
    int maxv = 0;
    for (int i = 1; i < lr.size(); i++) {
        int height = lr[i] - lr[i - 1];
        for (int j = 1; j < ud.size(); j++) {
            int width = ud[j] - ud[j - 1];
            maxv = max(maxv, height * width);
        }
    }
    cout << maxv;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solution();

    return 0;
}