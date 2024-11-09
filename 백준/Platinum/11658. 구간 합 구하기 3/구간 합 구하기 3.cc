#include <iostream>
#include <vector>
using namespace std;

const int MAX_N = 1025;
int arr[MAX_N][MAX_N];
int tree[MAX_N * 4][MAX_N * 4];
int N, M;

void Update_Tree_X(int start, int end, int node, int Ynode, int X, int v) {
    if (start > X || end < X) return;
    if (start == end) {
        tree[Ynode][node] = v;
        for (int i = Ynode >> 1; i > 0; i >>= 1) {
            tree[i][node] = tree[i * 2][node] + tree[i * 2 + 1][node];
        }
        return;
    }
    int mid = (start + end) / 2;
    Update_Tree_X(start, mid, node * 2, Ynode, X, v);
    Update_Tree_X(mid + 1, end, node * 2 + 1, Ynode, X, v);
    tree[Ynode][node] = tree[Ynode][node * 2] + tree[Ynode][node * 2 + 1];
    for (int i = Ynode >> 1; i > 0; i >>= 1) {
        tree[i][node] = tree[i * 2][node] + tree[i * 2 + 1][node];
    }
}

void Update_Tree_Y(int start, int end, int node, int Y, int X, int v) {
    if (start > Y || end < Y) return;
    if (start == end) {
        Update_Tree_X(0, N - 1, 1, node, X, v);
        return;
    }
    int mid = (start + end) / 2;
    Update_Tree_Y(start, mid, node * 2, Y, X, v);
    Update_Tree_Y(mid + 1, end, node * 2 + 1, Y, X, v);
}

int Query_X(int start, int end, int node, int Ynode, int left, int right) {
    if (left > end || right < start) return 0;
    if (left <= start && end <= right) return tree[Ynode][node];
    int mid = (start + end) / 2;
    return Query_X(start, mid, node * 2, Ynode, left, right) +
        Query_X(mid + 1, end, node * 2 + 1, Ynode, left, right);
}

int Query_Y(int start, int end, int node, int y1, int y2, int x1, int x2) {
    if (y1 > end || y2 < start) return 0;
    if (y1 <= start && end <= y2) return Query_X(0, N - 1, 1, node, x1, x2);
    int mid = (start + end) / 2;
    return Query_Y(start, mid, node * 2, y1, y2, x1, x2) +
        Query_Y(mid + 1, end, node * 2 + 1, y1, y2, x1, x2);
}

void solution() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
            Update_Tree_Y(0, N - 1, 1, i, j, arr[i][j]);
        }
    }

    for (int i = 0; i < M; i++) {
        int cmd, x1, y1, x2, y2, c;
        cin >> cmd;
        if (cmd == 0) {
            cin >> y1 >> x1 >> c;
            Update_Tree_Y(0, N - 1, 1, y1 - 1, x1 - 1, c);
        }
        else {
            cin >> y1 >> x1 >> y2 >> x2;
            cout << Query_Y(0, N - 1, 1, y1 - 1, y2 - 1, x1 - 1, x2 - 1) << '\n';
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    solution();
    return 0;
}