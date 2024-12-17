#include <bits/stdc++.h>
using namespace std;

void solution(){
	int N, K;
	cin >> N >> K;
	vector<int> arr(N);
	for(int i=0; i<N;i++)
		cin >> arr[i];
	sort(arr.begin(),arr.end());
	int distance = arr.back() - arr.front();
	int max_count = distance / K;
	while()
}

int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	solution();
    return 0;
}

