#include <iostream>
#include<cmath>
using namespace std;
#define MAX 100001
#define MOD 1000000009
long long DP[MAX][4];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    DP[1][1] = 1;
    DP[2][2] = 1;
    DP[3][1] = 1;
    DP[3][2] = 1;
    DP[3][3] = 1;
    for(int i=4;i<MAX;i++){
      DP[i][1] = (DP[i-1][2]+DP[i-1][3])%MOD;
      DP[i][2] = (DP[i-2][1] + DP[i-2][3])%MOD;
      DP[i][3] = (DP[i-3][1] + DP[i-3][2])%MOD;
    }
    int N,T;
    cin >> T;
    while(T--){
      cin >> N;
      cout << (DP[N][3]+DP[N][2]+DP[N][1])%MOD  << '\n';
    }
    
    
  return 0;
}
