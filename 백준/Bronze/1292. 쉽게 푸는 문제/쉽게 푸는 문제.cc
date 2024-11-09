#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#define INF 0x7fffffff
using namespace std;

void solution() {
    int from, to;
    cin >> from >> to;
    //1. to 까지 수열의 합 - from까지 수열의 합
    int sum = 0;
    for (int i = 1, level = 1, cnt = 0; i <= to; i++) {
        if (i >= from) {
            sum += level;
        }
        cnt++;
        if (cnt == level) {
            level++;
            cnt = 0;
        }
    }
    cout << sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solution();

    return 0;
}