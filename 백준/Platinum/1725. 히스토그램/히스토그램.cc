#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<algorithm>
using namespace std;

/*
* 문제 설명 및 링크
https://www.acmicpc.net/problem/6549
구간별 히스토그램의 넓이를 구해놓는다면? root에 올라올때 이미 계산된 상태라면?
히스토그램의 넓이를 구하는 방법: 범위내 최소값 * 구간 길이이 가장 큰 구간을 구해야한다.
이 중 가장 큰 녀석을 써야하는데 어떻게 하지?

구간 탐색을 어떻게 해야 잘 했다고 소문이 날까?
정렬이 안되어 있으니 twopoint는 사용할 수 없다.
이분탐색으로 모두 탐색할까? -> 괜찮은거같긴한데..
nlon이 나오면 문제없다.
*/
/*
* 소감
*/

long long arr[100001];
pair<long long, long long> tree[400004];
int N;
//최소힙 만드는 시간: N.
void init(int start, int end, int node) {
	if (start == end) {
		tree[node].first = arr[start];
		tree[node].second = start;
		return;
	}
	int mid = (start + end) / 2;
	init(start, mid, node * 2);
	init(mid + 1, end, node * 2 + 1);
	if (tree[node * 2].first < tree[node * 2 + 1].first) {
		tree[node].first = tree[node * 2].first;
		tree[node].second = tree[node * 2].second;
	}
	else {
		tree[node].first = tree[node * 2 + 1].first;
		tree[node].second = tree[node * 2 + 1].second;
	}
	return;
}
pair<long long, long long> getheight(int start, int end, int node, int left, int right) {
	if (right< start || left > end) {
		//영향을 끼치면 안된다.
		return { 1e18,1e18 };
	}
	if (left <= start && end <= right) return tree[node];
	int mid = (start + end) / 2;
	pair<long long, long long> lefttree = getheight(start, mid, node * 2, left, right);
	pair<long long, long long> righttree = getheight(mid + 1, end, node * 2 + 1, left, right);
	return min(lefttree, righttree);
}
long long getarea(int start, int end) {
	pair<long long, long long> state = getheight(0, N - 1, 1, start, end);
	long long area = (end - start + 1) * state.first;
	if (start < state.second) {
		long long value = getarea(start, state.second - 1);
		area = max(value, area);
	}
	if (end > state.second) {
		long long value = getarea(state.second + 1, end);
		area = max(value, area);
	}
	return area;
}


void solution() {
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	init(0, N - 1, 1);
	cout << getarea(0, N - 1) << endl;
}

int main() {

	cin.tie(NULL); ios_base::sync_with_stdio(false);
	cin >> N;
	solution();
	return 0;
}

