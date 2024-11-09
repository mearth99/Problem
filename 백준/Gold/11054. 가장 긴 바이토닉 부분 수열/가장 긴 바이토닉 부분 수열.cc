#include <bits/stdc++.h>
using namespace std;

int DP[1001];
int DP2[1001];
int ARR[1001];
void solution(){
	int N;
	cin >> N;
	for(int i=1;i<=N;i++)
		cin >> ARR[i];
	for(int i=1;i<=N;i++){
		DP[i] = 1;
		for(int j=1;j<=i;j++){
			if(ARR[j] < ARR[i] && DP[i] < DP[j]+1)
				DP[i] = DP[j]+1;
		}	
	}
	for(int i=N;i>0;i--){
		DP2[i] = 1;
		for(int j=N;j>=i;j--){
			if(ARR[i] > ARR[j] && DP2[i] < DP2[j]+1)
				DP2[i] = DP2[j]+1;
		}	
	}
	int maxv = 0;
	for(int i=1;i<=N;i++){
		maxv = max(DP[i]+DP2[i]-1,maxv);
	}
	cout << maxv;
}

int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	solution();
    return 0;
}