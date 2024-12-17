#include<iostream>
#include<algorithm>
#include<string>
#include<queue>
#include<unordered_map>
#define MAX 0x7fffffff
using namespace std;
unordered_map<string, bool> visit;
void solution() {
	int N, K;
	cin >> N >> K;
	string v;
	for (int i=0;i<N;i++){
		int a;
		cin >> a;
		v.append(to_string(a));
	}
	string result = v;
	sort(result.begin(), result.end());
	queue<pair<string, int>> q;
	q.push({ v, 0 });
	visit[v] = true;
	int output = MAX;
	while (!q.empty()) {
		string cur = q.front().first;
		int count = q.front().second;
		q.pop();
		if (cur == result)
			output = min(output, count);
		for (int i = 0; i <= N - K; i++) {
			string temp = cur.substr(i,K);
			reverse(temp.begin(), temp.end());
			temp = cur.substr(0, i) + temp + cur.substr(i + K);
			if (!visit[temp]) {
				visit[temp] = true;
				q.push({ temp,count + 1 });
			}
		}

	}
	if (output == MAX) output = -1;
	cout << output;
}

int main() {
	cout.tie(nullptr);
	cin.tie(nullptr); ios_base::sync_with_stdio(false);
	solution();
	return 0;
}