#include <bits/stdc++.h>
using namespace std;
#define MAX 987654321
//오른쪽, 아래로 본다는 것은, 왼쪽 -> 오른쪽 이후 한칸 내려가는 식으로 탐색하면 전부 탐색할 수 있다.
//즉, i, j칸에 있는 다음 DP값에 추가하면서 이동하면 된다.

int DP[21][2];
pair<int,int> ARR[21];

void solution(){
	
	int N,K;
	cin >> N;
	for(int i=0;i<N;i++){
		DP[i][0] = MAX;
		DP[i][1] = MAX;
	}
	for(int i=1;i<N;i++){
		int v1,v2;
		cin >> v1 >> v2;
		ARR[i] = {v1,v2};
	}
	cin >> K;
	DP[1][0] = 0;
	DP[2][0] = ARR[1].first;
	DP[3][0] = min(DP[2][0] + ARR[2].first, ARR[1].second);
	for(int i=4;i<=N;i++){
		DP[i][0] = min(DP[i-1][0]+ARR[i-1].first, DP[i-2][0]+ARR[i-2].second);
		DP[i][1] = min(min(DP[i-1][1]+ARR[i-1].first, DP[i-2][1]+ARR[i-2].second),DP[i-3][0]+K);
	}
	cout << min(DP[N][0],DP[N][1]);
}

int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	solution();
    return 0;
}