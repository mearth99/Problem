#include <iostream>
#include<cmath>
using namespace std;
#define MAX 100001
#define MOD 1000000009
long long DP[MAX][2];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    DP[1][1] = 1;
    DP[2][0] = 1;
    DP[2][1] = 1;
    DP[3][0] = 2;
    DP[3][1] = 2;
    
    for(int i=4;i<MAX;i++){
      DP[i][0] = (DP[i-1][1] + DP[i-2][1] + DP[i-3][1])%MOD;
      DP[i][1] = (DP[i-1][0] + DP[i-2][0] + DP[i-3][0])%MOD;
    }
    int N,T,M;
    cin >> T;
    while(T--){
      cin >> N;
      cout << DP[N][1] << " " << DP[N][0] << '\n';
    }
    
  return 0;
}
