#include <bits/stdc++.h>
using namespace std;
int N;
int DP[1<<15][15][10];

int DP_DFS(int visited, int artist, int price){
	int &ret = DP[visited][artist][price];
	if(ret != -1) return ret;
	ret = 0;
	for(int i=1;i<N;i++){
		if(!)
	}
}


void solution(){
	
	cin >> N;
	memset(DP, -1, sizeof(DP));
	int arr[16][16] = {0};
	for(int i=0;i<N;i++){
		string temp;
		cin >> temp;
		for(int j=0;j<temp.size();j++){
			arr[i][j] = temp.at(j) - '0';
		}
	}
	DP_DFS(1, 0, 0);
}

int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	solution();
    return 0;
}