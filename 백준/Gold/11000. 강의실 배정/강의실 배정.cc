#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

//1. N이 20만개이기 떄문에, N2으로 검사하면 오버플로우가 나타난다.

int main() {
	priority_queue<int,vector<int>,greater<int>> pq;
	vector<pair<int, int>> vect;
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		vect.push_back(make_pair(a, b));
	}
	sort(vect.begin(), vect.end());
	pq.push(vect[0].second);

	for (int i = 1; i < N; i++) {
		if (vect[i].first >= pq.top()) {
			pq.pop();
			pq.push(vect[i].second);
		}
		else {
			pq.push(vect[i].second);
		}
	}
	cout << pq.size();
	return 0;
}
