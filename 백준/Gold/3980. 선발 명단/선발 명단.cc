#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int t = 0, result = 0;
int arr[11][11] = { 0, };
bool visited[11];

void dfs(int cnt, int sum) {
	if (cnt == 11) {
		result = max(result, sum);
		return;
	}

	for (int i = 0; i < 11; i++) {
		if (arr[cnt][i] == 0)
			continue;
		if (visited[i] == 0) {
			visited[i] = 1;
			dfs(cnt + 1, sum + arr[cnt][i]);
			visited[i] = 0;
		}


	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> t;

	while (t--) {
		for (int i = 0; i < 11; i++)
			for (int j = 0; j < 11; j++)
				cin >> arr[i][j];
		memset(visited, 0, sizeof(visited));
		result = 0;
		dfs(0, 0);
		cout << result << "\n";
	}

}