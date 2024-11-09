#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<cstring>

using namespace std;

int n;
int work[16][16];
int dp[16][1<<16];
int inf = 987654321;
int stopbit;
void make_works()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) 
			cin >> work[i][j];
	stopbit = (1<<n) -1;	
}

// bitmask 이용한 dp (초기화 : inf)
// 수행한 작업(i)을 n 길이의 bit의 1로 켠다.
// i번째 비트 켜기 : bit | (1<<i)
// i번째 비트 끄기 : bit & ~(1<<i)
// i번째 비트 켜져 있는 지 확인 : bit & (1<<i)


int DFS(int cur, int city){
    if(city == stopbit){ //모두 방문했을 때, city에서 0으로 갈 수 있는지 따지게 된다.
        if(work[cur][0]==0) return inf;
        else return work[cur][0];
    }
    if(dp[cur][city]!=-1) return dp[cur][city]; //이미 방문한 곳이므로 넘긴다.
    dp[cur][city] = inf; //처음 방문한 곳은 가장 큰 값을 넣어줘, min값을 찾도록 돕는다.
    
    for(int i=0;i<n;i++){
        if(work[cur][i]==0) continue; //갈수없는 도시이므로 넘어간다.
        if(((1<<i)&city)==(1<<i)) continue; //이미 방문한 도시이므로 무시한다.

        dp[cur][city] = min(dp[cur][city], work[cur][i]+ DFS(i, (city|1<<i)));
    }
    return dp[cur][city];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
	make_works();
    memset(dp,-1,sizeof(dp));
	cout << DFS(0,1);
    return 0;
}