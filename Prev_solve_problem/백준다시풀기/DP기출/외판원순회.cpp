#include <bits/stdc++.h>
using namespace std;
#define MAX 16
#define INF 987654321
int arr[MAX][MAX];
int DP[MAX][1<<MAX];
int N;
int DFS(int cur, int visit){
	if(visit == (1<<N)-1){
		if(arr[cur][0]==0) return INF;
		return DP[cur][0];
	}
	if(DP[cur][visit]!=-1) return DP[cur][visit];

	for(int i=0;i<N;i++){
		if(arr[cur][i]==0) continue;
		if(visit & (1 << i)) continue;
		DP[cur][visit] = min(DP[cur][visit], arr[cur][i] + DFS(i, visit|(1 << i)));
	}
	return DP[cur][visit];
}

void solution(){
	
	cin >> N;
	for(int i=0;i<N;i++){

	}
	
}


int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	solution();
    return 0;
}

