#include <bits/stdc++.h>
using namespace std;
int K;
int DP[1<<13][13];
int arr[13];

int DFS_DP(int visit, int cur){
	int &target = DP[visit][cur];
	if(target != -1) return target;
	target = 0;
	
}

void solution(){
	cin >> K;
	memset(DP, -1, sizeof(DP));
	for(int i=0;i<K;i++)
		cin >> arr[i];
	DFS_DP(1,0);
}

int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	solution();
    return 0;
}