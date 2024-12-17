#include <bits/stdc++.h>
using namespace std;
int N;
int output = 0;
int arr[101];
void DFS(int idx, int sum){
	if(idx==N-2){
		if(sum+arr[idx]==arr[N-1] || sum-arr[idx]==arr[N-1]) output++;
		return;
	}
	if(sum+arr[idx]<=20) DFS(idx+1,sum+arr[idx]);
	if(sum-arr[idx]>=0) DFS(idx+1,sum-arr[idx]);
}


void solution(){
	cin >> N;
	for(int i=0;i<N;i++){
		cin >> arr[i];
	}
	DFS(0,0);
	cout << output;
}

int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	solution();
    return 0;
}