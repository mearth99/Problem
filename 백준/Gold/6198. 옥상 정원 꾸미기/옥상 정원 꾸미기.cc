#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<int> heights(N);
    for (int i = 0; i < N; i++) {
        cin >> heights[i];
    }

    vector<long long> result(N, 0);
    stack<int> st;

    for (int i = N - 1; i >= 0; i--) {
        while (!st.empty() && heights[st.top()] < heights[i]) {
            result[i] += result[st.top()] + 1;
            st.pop();
        }
        st.push(i);
    }

    long long total = 0;
    for (int i = 0; i < N; i++) {
        total += result[i];
    }

    cout << total << '\n';

    return 0;
}