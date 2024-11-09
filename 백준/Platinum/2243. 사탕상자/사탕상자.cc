#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<algorithm>
#include<map>
#include <cmath>
using namespace std;

#define MAX 1000000

int tree[MAX * 4];

void update(int start, int end, int node, int index, int diff) {
	if (index < start || end < index) return;

	if (start == end) {
		tree[node] += diff;
		return;
	}
	tree[node] += diff;
	int mid = (start + end) / 2;
	update(start, mid, node * 2, index, diff);
	update(mid+1, end, node * 2+1, index, diff);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int qury(int start, int end, int node, int rank) {
	//6위라는 것은 이녀석 왼쪽에 5개가 있다는 것이다..
	if (start == end) {
		return start;
	}
	int mid = (start + end) / 2;
	int left = tree[node * 2];
	int right = tree[node * 2 + 1];
	if (left < rank) {
		return qury(mid + 1, end, node * 2 + 1, rank - left);
	}
	else {
		return qury(start, mid, node * 2, rank);
	}

}



void solution() {
	vector<int> output;
	int N;
	cin >> N;
	while (N--) {
		int A, B, C;
		cin >> A;
		if (A == 1) {
			cin >> B;
			// 어떻게든 Node의 순위에 해당하는 idx를 구해서
			int idx = qury(1, MAX, 1, B);
			update(1, MAX, 1, idx, -1);
			output.push_back(idx);
		}
		else {
			cin >> B >> C;
			update(1, MAX, 1, B, C);
		}
	}
	for (auto it : output)
		cout << it << '\n';
}

int main() {

	cin.tie(NULL); ios_base::sync_with_stdio(false);
	solution();
	return 0;
}

