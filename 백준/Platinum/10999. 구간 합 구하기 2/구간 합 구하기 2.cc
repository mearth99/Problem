#include <iostream>

using namespace std;
#define MAX 1000001

long long arr[MAX];
long long tree[MAX * 4]; // tree의 크기를 계산하는 법은 보통, log를 취해 높이를 계산한 후 크기를 따지지만, 어림잡아 *4를 하면 최적화는 아니더라도 메모리 오류는 나지 않는다. 
long long lazy[MAX * 4]; // Lazy 업데이트에 사용할 배열. 

void update_lazy(int start, int end, int node) {
	if (lazy[node]) {
		tree[node] += (end - start + 1) * lazy[node]; // 구간의 크기만큼 lazy 값을 곱해서 더함
		if (start != end) { // 리프 노드가 아니라면 자식에게 lazy 전파
			lazy[node * 2] += lazy[node];
			lazy[node * 2 + 1] += lazy[node];
		}
		lazy[node] = 0; // lazy 값 초기화
	}
}
long long query(int start, int end, int node, int left, int right) {
	update_lazy(start, end, node); // lazy 값 업데이트
	//left, right : 원하는 구간의 범위
	//start , end : 실제 범위로 잡은 구간 크기
	if (left > end || right < start) return 0; // -> 구간에 일치하는 부분이 하나도 없는 경우 당연하게 0을 반환한다.
	if (left <= start && end <= right) return tree[node]; // -> 원하는 구간이 실제 범위로 잡은 구간보다 큰 경우 모든 값의 합을 반환한다.
	int mid = (start + end) / 2;
	return query(start, mid, node * 2, left, right) + query(mid + 1, end, node * 2 + 1, left, right); //재귀로 구간을 탐색하면서 결과를 찾는다.
}

void update_tree(int start, int end, int node, int left,int right, long long diff) {
	update_lazy(start, end, node); // lazy 값 업데이트
	if (left > end || right < start) return; // left와 right가 모두 구간에 없는 경우 더 이상 계산할 필요가 없기 때문에 끝낸다.
	if (left <= start && end <= right) {
		tree[node] += (end - start + 1 ) * diff; //이 구간에 전부 lazy가 적용 될 태니, 그 만큼 적용한다.
		if (start != end) { //리프노드가 아니라면, 자식에게 전파.
			lazy[node * 2] += diff;
			lazy[node * 2 + 1] += diff;
		}
		return;
	}
	int mid = (start + end) / 2;
	update_tree(start, mid, node * 2, left, right, diff); //재귀를 통해 왼쪽, 오른쪽을 가면서 목적지 트리를 찾아나간다.
	update_tree(mid + 1, end, node * 2 + 1, left, right, diff);
	tree[node] = tree[node * 2] + tree[node * 2 + 1]; // 자식 노드의 합을 부모 노드에 반영
}
void init_tree(int start, int end, int node) {
	if (start == end) {
		tree[node] = arr[start];
		return;
	}
	int mid = (start + end) / 2;
	init_tree(start, mid, node * 2);
	init_tree(mid + 1, end, node * 2 + 1);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int N, M, K;
	int A, B, C;
	long long D;
	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}
	init_tree(1, N, 1);
	for (int i = 0; i < M + K; i++) {
		cin >> A >> B >> C;
		if (A == 1) {
			cin >> D;
			update_tree(1, N, 1, B, C, D);
		}
		else {
			cout << query(1, N, 1, B, C) << '\n';
		}
	}
	
	return 0;
}