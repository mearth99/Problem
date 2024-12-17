#include <bits/stdc++.h>
using namespace std;



void solution(){
	int N,M;
	int start=0, end=0,sum=0,cnt=0;
	cin >> N >> M;
	vector<int> arr(N);
	for(int i=0;i<N;i++)
		cin >> arr[i];
	while(end<N || sum >= M){
		if(sum < M){
			sum += arr[end++];
		}else if(sum == M){
			cnt++;
			sum -= arr[start++];
		}else{
			sum -= arr[start++];
		}
	}
	cout << cnt;
}

int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	solution();
    return 0;
}