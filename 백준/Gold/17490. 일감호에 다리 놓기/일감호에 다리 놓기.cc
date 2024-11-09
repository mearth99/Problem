#include<iostream>
#include<vector>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;

#define MAX 1000001

int rocks[MAX];
int N, M;
long long K;
vector<pair<int,int>> NoPass;
void solution() {
	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++) {
		cin >> rocks[i];
	}
	for (int i = 0; i < M; i++) {
		int from, to;
		cin >> from >> to;
		if (from > to && from!=N) {
			swap(from, to);
		}
		if (from == 1 && to == N)
			swap(from, to);
		NoPass.push_back({ from,to });
	}
	if (M <= 1) {
		cout << "YES";
		return;
	}
	sort(NoPass.begin(), NoPass.end());
	long long sum = 0;
	for (int i = 0; i < NoPass.size()-1;i++) {
		int it = NoPass[i].second;
		int nextit = NoPass[i + 1].second;
		int minv = 1000001;
		if (nextit == 1) nextit = N+1;
		for (int j = it; j < nextit; j++) {
			minv = min(minv, rocks[j]);
		}
		sum += minv; 
	}
	if (NoPass.back().second != 1) {
		int minv = 1000001;
		for (int i = NoPass.back().second; i <= N; i++) {
			minv = min(minv, rocks[i]);
		}
		for (int i = 1; i < NoPass.front().second; i++) {
			minv = min(minv, rocks[i]);
		}
		sum += minv;
	}
	else {
		int minv = 1000001;
		for (int i = 1; i < NoPass.front().second; i++) {
			minv = min(minv, rocks[i]);
		}
		sum += minv;
	}

	if (sum <= K) cout << "YES";
	else cout << "NO";
	return;

}


int main() {
	solution();
	return 0;
}

