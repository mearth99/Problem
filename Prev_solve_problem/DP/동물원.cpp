#include <bits/stdc++.h>
using namespace std;

int arr[100001] = {0,3,7,17};

void solution(){
	int N;
	cin >> N;
	for(int i=4;i<=N;i++){
		arr[i] = (arr[i-1]*2+arr[i-2])%9901;
	}
	cout << arr[N];
}

int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	solution();
    return 0;
}