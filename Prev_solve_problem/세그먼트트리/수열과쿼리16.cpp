#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#define MAX 100001

using namespace std;



int arr[MAX];
pair<int,int> tree[MAX * 4];  //value, index

pair<int,int> init(int start, int end, int node) {
	if (start == end) return tree[node] = make_pair(arr[start],start);
	int mid = (start + end) / 2;
	pair<int, int> L = init(start, mid, node * 2);
	pair<int, int> R = init(mid + 1, end, node * 2 + 1);
	//부모는 L과 R을 비교하여, 그 중 작은값, 인덱스도 작은걸 찾는다.
	if (L.first < R.first) return tree[node] = L;
	else if (L.first == R.first) return L.second > R.second ? tree[node] = R : tree[node] = L;
	else return tree[node] = R;

}
pair<int, int> query(int start, int end, int node, int left, int right) {
	if (left > end || right < start) return make_pair((int)0x7fffffff,(int)0x7fffffff);
	if (left <= start && end <= right) return tree[node]; 
	int mid = (start + end) / 2;
	pair<int, int> L = query(start, mid, node * 2, left, right);
	pair<int, int> R = query(mid + 1, end, node * 2 + 1, left, right);
	if (L.first < R.first) return L;
	else if (L.first == R.first) return L.second > R.second ? R : L;
	else return R;
}

pair<int,int> update_tree(int start, int end, int node, int index, int diff) {
	if (index < start || index > end) return tree[node];
	if (start == end) return tree[node] = make_pair(diff,index);
	int mid = (start + end) / 2;
	pair<int, int> L =  update_tree(start, mid, node * 2, index, diff);
	pair<int, int> R = update_tree(mid + 1, end, node * 2 + 1, index, diff);
	if (L.first < R.first) return tree[node] = L;
	else if (L.first == R.first) return L.second > R.second ? tree[node] = R : tree[node] = L;
	else return tree[node] = R;
}
int N;
void solution() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	init(0, N - 1, 1);
	int M;
	cin >> M;
	for (int i = 0; i < M; i++) {
		int cmd, a, b;
		cin >> cmd >> a >> b;
		if (cmd == 1) {
			update_tree(0, N - 1, 1, a-1, b);
		}
		else {
			pair<int, int> result = query(0, N - 1, 1, a - 1, b - 1);
			cout << result.second+1 << '\n';
		}
	}
}

int main() {
    cout.tie(nullptr);
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    solution();
    return 0;
}