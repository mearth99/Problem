#include <bits/stdc++.h>
using namespace std;


void solution(){
	int N;
	cin >> N;
	vector<int> arr(N);
	vector<int> DP;
	for(int i=0;i<N;i++){
		cin >> arr[i];
	}
	DP.push_back(arr[0]);
	for(int i=1;i<N;i++){
		if(DP.back() < arr[i]){
			DP.push_back(arr[i]);
		}else{
			auto it = lower_bound(DP.begin(),DP.end(), arr[i]);
			*it = arr[i];
		}
	}
	cout << DP.size();	
}


int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	solution();
    return 0;
}

