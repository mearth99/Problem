#include <bits/stdc++.h>
using namespace std;

int N,K;
int arr[151];
int DP[151];
int minv = INT32_MAX;
int DFSDP(int idx,int value){
	if(idx == N){
		if(value > K) minv = min(minv, value);
		return;
	}
	if(DP[idx]!=-1) return DP[idx];
	

}
void solution(){
	cin >> N;
	for(int i=0;i<N;i++){
		cin >> arr[i];
	}
	cin >> K;
	DFSDP(0);
}

int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	solution();
    return 0;
}