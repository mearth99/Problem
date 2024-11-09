
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;



int main() {
	int maxv = 0;
	int cur = 0;
	int A, B;
	while (cin >> A) {
		cin >> B;
		cur -= A;
		cur += B;
		maxv = max(maxv, cur);
	}
	cout << maxv;
	return 0;
}
