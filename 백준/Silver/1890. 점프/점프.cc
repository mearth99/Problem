#include <bits/stdc++.h>
using namespace std;

//오른쪽, 아래로 본다는 것은, 왼쪽 -> 오른쪽 이후 한칸 내려가는 식으로 탐색하면 전부 탐색할 수 있다.
//즉, i, j칸에 있는 다음 DP값에 추가하면서 이동하면 된다.

long long int DP[101][101];
int ARR[101][101];

void solution(){
	int N;
	cin >> N;
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cin >> ARR[i][j];
		}
	}
	DP[0][0] = 1;
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			//0이면 점프해서 갈 수 없는 위치다.
			if(DP[i][j]!=0){
				if(ARR[i][j]==0) continue;
				if(i+ARR[i][j]<N){
					DP[i+ARR[i][j]][j]+= DP[i][j];
				}
				if(j+ARR[i][j]<N){
					DP[i][j+ARR[i][j]]+= DP[i][j];
				}
			}
		}
	}
	cout << DP[N-1][N-1];

}

int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	solution();
    return 0;
}