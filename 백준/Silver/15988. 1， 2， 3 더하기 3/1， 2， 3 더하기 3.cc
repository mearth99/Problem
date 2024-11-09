#include <iostream>
#include<cmath>
using namespace std;
#define MAX 1000001
long long DP[MAX];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    DP[1] = 1;
    DP[2] = 2;
    DP[3] = 4;
    for(int i=4;i<MAX;i++)
      DP[i] = (DP[i-1] + DP[i-2] +DP[i-3])%1000000009; 
    int N,T;
    cin >> T;
    while(T--){
      cin >> N;
      cout << DP[N] << '\n';
    }
    
    
  return 0;
}
