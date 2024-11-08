#define MOD 1000000000
#define LL long long int
#include <iostream>
using namespace std;

LL dp[101][11][1025];
int N;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	for (int i = 1; i < 10; i++) {
		dp[1][i][1<<i] = 1; //길이가 1개 일때, 마지막 수 i에 길이가 1임을 확인 즉, 1 , 2, 3 , 4, 5, 6, 7, 8, 9는 계단 수다.
	}
	int next_bit = 0;
	for(int i=0;i<N;i++){
		for(int j=0;j<10;j++){
			for(int bit=0;bit<1024;bit++){
				if(j!=9){
					next_bit = bit | (1 << j+1);
					dp[i+1][j+1][next_bit] = (dp[i+1][j+1][next_bit] + dp[i][j][bit])%MOD;
				}
				if(j!=0){
					next_bit = bit | (1 << j-1);
					dp[i+1][j-1][next_bit] = (dp[i+1][j-1][next_bit] + dp[i][j][bit])%MOD;
				}
				
			}
		}
	}
	int answer = 0;
	for(int i=0;i<10;i++)
		answer = (answer + dp[N][i][1023]) % MOD;
	cout << answer;
}