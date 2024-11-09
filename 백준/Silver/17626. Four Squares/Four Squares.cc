#include <bits/stdc++.h>
using namespace std;
//BFS를 통한 문제 해결.
int DP[50001];

//N이 있다. N보다 낮은 제곱수의 집합을 P'라고 하자.
//N-P' 값의 모임을 S라 하자.
//DP[N] = min(DP[S]) +1 이다.

void solution(){
	memset(DP,10,sizeof(DP));
	int N;
	cin >> N;
	for(int i=1;i*i<=N;i++)
		DP[i*i] = 1;
	for(int i=2;i<=N;i++){
		for(int j=1;j*j<=i;j++){
			//1 4 9 16 ...
			DP[i] = min(DP[i-j*j]+DP[j*j],DP[i]);
		}
	}
	cout << DP[N];
}

int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	solution();
    return 0;
}