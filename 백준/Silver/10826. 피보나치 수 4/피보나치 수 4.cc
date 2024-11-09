#include <iostream>
#include <string>
using namespace std;

string DP[10001];

string ADD(string a, string b) {
	string result = "";
	int ai = a.length() - 1;
	int bi = b.length() - 1;
	int carry = 0;
	while (ai >= 0 || bi >= 0 || carry) {
		int sum = carry;
		if (ai >= 0) sum += (a[ai--] - '0');
		if (bi >= 0) sum += (b[bi--] - '0');

		carry = sum / 10;
		result = to_string(sum % 10) + result;
	}
	return result;
}

void solution() {
	DP[0] = "0";
	DP[1] = "1";
	int N;
	cin >> N;
	for (int i = 2; i <= N; i++) {
		DP[i] = ADD(DP[i - 1] , DP[i - 2]);
	}
	cout << DP[N];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	solution();
	return 0;
}