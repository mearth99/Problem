#include <iostream>
#include<cmath>
using namespace std;
#define MAX 100001
#define MOD 1000000009
long long DP[MAX];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    DP[1] = 1;
    DP[2] = 2;
    DP[3] = 2;
    DP[4] = 3;
    DP[5] = 3;
    DP[6] = 6;
    for(int i=7;i<MAX;i++){
      DP[i] = (DP[i-2] + DP[i-4] + DP[i-6])%MOD;
    }
    int N,T;
    cin >> T;
    while(T--){
      cin >> N;
      cout << DP[N] << '\n';
    }
    
  return 0;
}
