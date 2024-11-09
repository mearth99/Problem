#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int DP[100001];
int main()
{
	int N;
	cin >> N;
	for (int i = 0; i <= N; i++) {
		DP[i] = i;
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j*j <= i; j++) {
			DP[i] = min(DP[i], DP[i - j * j] + 1);
		}
	}
	cout << DP[N];
	return 0;
}