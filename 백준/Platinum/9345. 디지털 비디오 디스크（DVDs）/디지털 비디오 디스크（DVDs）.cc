#include <cstdio>
#include <algorithm>

using namespace std;
using pii = pair<int, int>;

pii tree[400005];
int loc[100005];

pii init(int node, int s, int e) {
    if (s == e) return tree[node] = {s, s};
    int mid = (s + e) >> 1;
    pii left = init(2 * node, s, mid);
    pii right = init(2 * node + 1, mid + 1, e);
    return tree[node] = {min(left.first, right.first), max(left.second, right.second)};
}

pii query(int node, int s, int e, int qs, int qe) {
    if (e < qs || qe < s) return {1e9, -1e9};
    if (qs <= s && e <= qe) return tree[node];
    int mid = (s + e) >> 1;
    pii left = query(2 * node, s, mid, qs, qe);
    pii right = query(2 * node + 1, mid + 1, e, qs, qe);
    return {min(left.first, right.first), max(left.second, right.second)};
}

pii update(int node, int s, int e, int idx, int num) {
    if (idx < s || idx > e) return tree[node];
    if (s == e) return tree[node] = {num, num};
    int mid = (s + e) >> 1;
    pii left = update(2 * node, s, mid, idx, num);
    pii right = update(2 * node + 1, mid + 1, e, idx, num);
    return tree[node] = {min(left.first, right.first), max(left.second, right.second)};
}

void solve() {
    int n, k; scanf("%d %d", &n, &k);
    init(1, 0, n - 1);
    for (int i = 0; i < n; i++) loc[i] = i;
    while (k--) {
        int q, a, b; scanf("%d %d %d", &q, &a, &b);
        if (!q) {
            update(1, 0, n - 1, loc[a], b);
            update(1, 0, n - 1, loc[b], a);
            swap(loc[a], loc[b]);
        } else {
            auto [m, M] = query(1, 0, n - 1, a, b);
            if (a == m && b == M) printf("YES\n");
            else printf("NO\n");
        }
    }
}

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        solve();
    }
}