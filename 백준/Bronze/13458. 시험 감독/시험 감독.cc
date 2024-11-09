#include <bits/stdc++.h>
using namespace std;


int ARR[1000001];

void solution(){
	long long int N, B, C,output;
	cin >> N;
	output = N;
	for(int i=0;i<N;i++)
		cin >> ARR[i];
	cin >> B >> C;
	for(int i=0;i<N;i++){
		if(ARR[i]-B>0){
			output += (ARR[i]-B)/C;
			if((ARR[i]-B)%C) output++;

		}
	}
	cout << output;
}

int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	solution();
    return 0;
}