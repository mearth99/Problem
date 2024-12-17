#include <bits/stdc++.h>
using namespace std;

int DP[2001][2001];
int arr[2001];


void solution(){
	memset(DP,0x7f,sizeof(DP));
	int N;
	int minv = INT32_MAX;
	cin >> N;
	for(int i=1;i<=N;i++){
		cin >> arr[i];
	}
	DP[1][0] = DP[0][1] = 0;
	for(int i=0;i<=N;i++){
		for(int j=0;j<=N;j++){
			if(i==j) continue;
			int next = max(i,j)+1;
			if(next > N) continue;
			if(i==0 || j==0)
				arr[0] = arr[next];
			DP[i][next] = max(DP[i][next], DP[i][j]+abs(arr[j]-arr[next]));
			DP[next][j] = max(DP[next][j], DP[i][j]+abs(arr[i]-arr[next]));
		}
		minv = min({minv, DP[N][i],DP[i][N]});
	}
	cout << minv;
}

int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	solution();
    return 0;
}