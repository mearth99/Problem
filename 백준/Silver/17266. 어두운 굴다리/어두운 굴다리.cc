#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <cmath>
using namespace std;
int arr[100002] = { 0 };

void Solution() {
	int N, M, distan = 0;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> arr[i];
	}
	if (distan < arr[0] - 0) {
		distan = arr[0] - 0;
	}
	for (int i = 1; i < M; i++) {
		if(distan < (arr[i] - arr[i-1]+1)/2)
		distan = (arr[i]-arr[i-1]+1)/2;
	}
	if (distan < N - arr[M - 1]) {
		distan = N - arr[M - 1];
	}
	cout << distan;

}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	Solution();
	return 0;
}