#include <bits/stdc++.h>
using namespace std;
int N,M;
int arr[8][8];
int visited[8][8];
vector<pair<int,int>> cctv;
//1은 4번 회전가능, 2는 두번 회전, 3은  4번 회전, 4는 4번 회전 5는 1번 회전 => 의미 없음.
void check(int y, int x, int arr[][8]){
	for(int i=y+1;i<N;i++){
		if(arr[i][x]==6) break;
	}
}

void solution(){
	int output = 0;
	cin >> N >> M;
	output = N*M;
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			cin >> arr[i][j];
			if(arr[i][j]<=4 && arr[i][j]>=1){
				cctv.push_back({i,j});
			}else if(arr[i][j]==5){
				check(i,j,arr);
			}
		}
	}

}

int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	solution();
    return 0;
}