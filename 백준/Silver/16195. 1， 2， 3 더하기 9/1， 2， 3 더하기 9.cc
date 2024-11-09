#include <iostream>
#include<cmath>
using namespace std;
#define MAX 1001
#define MOD 1000000009
long long DP[MAX][MAX];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    DP[1][1] = 1;
    DP[2][1] = 1;
    DP[2][2] = 1;
    DP[3][1] = 1;
    DP[3][2] = 2;
    DP[3][3] = 1;

    for(int i=4;i<MAX;i++){
      for(int j=1;j<=i;j++){
        //이전것에서 1을 더하는 방법
        DP[i][j] = (DP[i-1][j-1] + DP[i-2][j-1] + DP[i-3][j-1])%MOD;
      }
    }
    int N,T,M;
    cin >> T;
    while(T--){
      cin >> N >> M;
      long long sum = 0;
      for(int i=1;i<=M;i++)
        sum = (sum+ DP[N][i])%MOD;
      cout << sum << '\n';
    }
    
  return 0;
}
