#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<algorithm>
using namespace std;

/*
* 문제 설명 및 링크
*/
/*
* 소감
*/
int DP[2002][2002];
vector<int> arr;

int N;
int DP_DFS(int th, int left, int right) {
	if (left > right) return 0;

	if (DP[left][right] != 0) return DP[left][right];

	return DP[left][right] = max(DP_DFS(th + 1, left + 1, right) + arr[left] * th, DP_DFS(th + 1, left, right - 1) + arr[right] * th);
}

void solution() {
	cin >> N;
	arr.resize(N + 1);
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}

	cout << DP_DFS(1, 1, N);
}

int main() {

	cin.tie(NULL); ios_base::sync_with_stdio(false);
	solution();
	return 0;
}

