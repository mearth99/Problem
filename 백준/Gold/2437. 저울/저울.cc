#include <iostream>
#include <vector>
#include <set>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;




void solution() {
	int N;
	cin >> N;
	vector<int> arr(N);
	for (auto& it : arr)
		cin >> it;
	sort(arr.begin(), arr.end());
	//1, 2, 3, 1 3 , 2 3 ... 1, 2, 3 => 합이 7이다.
	//1, 1, 2, 3, 6, 7, 30 => 답이 21
	//이전합이 가능하면 6 이후에도 동일하게 가능할 것.
	//1 2, 4, 7, 13, 20, 49
	/*
	* A에서 K까지 값이 된다면, K+1은 또 A~K까지 될 것.
	*/
	int result = 1;
	for (int i = 0;i < N;i++) {
		if (result < arr[i]) break;
		result += arr[i];
	}
	cout << result;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solution();
	return 0;
}