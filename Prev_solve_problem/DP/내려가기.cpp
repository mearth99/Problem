#include <bits/stdc++.h>
using namespace std;

int DP_MIN[3] = {0};
int DP_MAX[3] = {0};
int MIN_PRE[3];
int MAX_PRE[3];

void solution(){
	int N;
	cin >> N;
	int arr[3];
	for(int i=0;i<3;i++){
		cin >> arr[i];
		DP_MIN[i] = arr[i]; 
		DP_MAX[i] = arr[i]; 
	}
	for(int i=1;i<N;i++){
		for(int j=0;j<3;j++)
			cin >> arr[j];
		MIN_PRE[0] = min(DP_MIN[0]+arr[0],DP_MIN[1]+arr[0]); 
		MAX_PRE[0] = max(DP_MAX[0]+arr[0],DP_MAX[1]+arr[0]);
		MIN_PRE[1] = min({DP_MIN[0]+arr[1],DP_MIN[1]+arr[1],DP_MIN[2]+arr[1]}); 
		MAX_PRE[1] = max({DP_MAX[0]+arr[1],DP_MAX[1]+arr[1],DP_MAX[2]+arr[1]}); 
		MIN_PRE[2] = min(DP_MIN[1]+arr[2],DP_MIN[2]+arr[2]); 
		MAX_PRE[2] = max(DP_MAX[1]+arr[2],DP_MAX[2]+arr[2]);
		DP_MIN[0] = MIN_PRE[0];
		DP_MIN[1] = MIN_PRE[1];
		DP_MIN[2] = MIN_PRE[2];
		DP_MAX[0] = MAX_PRE[0]; 
		DP_MAX[1] = MAX_PRE[1]; 
		DP_MAX[2] = MAX_PRE[2]; 
	}
	cout << max({DP_MAX[0],DP_MAX[1],DP_MAX[2]}) << " " << min({DP_MIN[0],DP_MIN[1],DP_MIN[2]});
}

int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	solution();
    return 0;
}