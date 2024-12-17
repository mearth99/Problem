#include <bits/stdc++.h>
using namespace std;

int cacu(int a, int b){
	if(b==0) return a;
	else return cacu(b, a%b);
}

void solution(){
	int N,input,minv=999999, maxv=-1;
	cin >> N;
	for(int i=0;i<N;i++){
		int value;
		cin >> value;
		minv = min(value, minv);
		maxv = max(value, maxv);
	}
	cout << minv*maxv;
}

int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	solution();
    return 0;
}