#include <bits/stdc++.h>

using namespace std;


/*
탁자 위에 돌 n개가 있다. 상근이가 먼저 가져가며, 마지막 돌을 가져가야 한다.
1:S 2:C 3: S 4: C 5: S 6
*/
int main(){
	int n;
	cin >> n;
	if(n & 1 == 1) cout << "SK";
	else cout << "CY";
	return 0;
}