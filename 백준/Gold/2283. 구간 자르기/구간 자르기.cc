#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fastIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define endl '\n'
#define X first
#define Y second
int n, k;
int arr[1000005];
int main(void) {
	fastIO;
	cin >> n >> k;
	for (int i = 0;i < n;i++) {
		int st, en;
		cin >> st >> en;
		for (;st+1 <= en;st++) arr[st]++;
	}
	int st = 0; int en = 0;
	int sum = 0;
	while (st <= en && en<=1000000 ) {
		if (sum == k) {
			cout << st << " " << en;
			return 0;
		}
		else if (sum < k) sum += arr[en++];
		else sum -= arr[st++];
	}
	cout << 0 << " " << 0;
    return 0;
}