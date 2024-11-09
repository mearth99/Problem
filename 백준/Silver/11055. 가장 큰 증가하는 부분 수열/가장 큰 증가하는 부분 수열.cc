#include <bits/stdc++.h>
using namespace std;

int DP[1001];


void solution(){
	int N,MAV=0;
	int ARR[1001];
	cin >> N;
	for(int i=0;i<N;i++){
		cin >> ARR[i];
	}
	for(int i=0;i<N;i++){
		DP[i] = ARR[i];
		for(int j=0;j<i;j++){
			if(ARR[j] < ARR[i] && DP[i] < DP[j] + ARR[i]){
				DP[i] = DP[j] + ARR[i];
			}
		}
		if(MAV<DP[i]) MAV = DP[i];
	}
	cout << MAV;
}

int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	solution();
    return 0;
}