#include <iostream>
#include <vector>
#include <deque>
#define INF 0x7fffffff
using namespace std;

int N, K;
string str;
void solution() {
    cin >> N >> K;
    cin >> str;
    deque<int> dq;
    for (auto& it : str) {
        while (!dq.empty() && K && dq.front() < (it - '0')) {
            dq.pop_front();
            K--;
        }
        dq.push_front((it - '0'));
    }
    while (!dq.empty() && dq.size() > K) {
        cout << dq.back();
        dq.pop_back();
    }

    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solution();

    return 0;
}