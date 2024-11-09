#include <bits/stdc++.h>
using namespace std;


void solution(){
	int N, K;
	cin >> N >> K;
	vector<int> arr(K+1,100000);
	for(int i=0; i<N;i++){
		int temp;
		cin >> temp;
		if(temp <= K){
			arr[temp] = 1;
		}
	}
	if(arr[K] == 1){
		cout << 1;
	}else{
		for(int i=1;i<=K;i++){
			for(int j=1;i+j<=K;j++){
				arr[i+j] = min(arr[i+j],arr[i]+arr[j]);
			}
		}
		if(arr[K] != 100000) cout << arr[K];
		else cout << -1;
	}
	
}


int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	solution();
    return 0;
}

