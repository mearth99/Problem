#include <algorithm>
#include <iostream>

using namespace std;

int dp[1001];
int v[1001];
int main()
{
    int n;
    cin >> n;
    for(int i=0;i<n;i++)
        cin >> v[i];
    
    for(int i=0;i<n;i++){
        dp[i] = 1;
        for(int j=0;j<n;j++)
            if(v[i]<v[j] && dp[j]+1>dp[i])
                dp[i] = dp[j]+1;
    }
    cout << *max_element(&dp[0],&dp[1001]);
    return 0;
}
