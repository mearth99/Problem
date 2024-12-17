#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int DP[101][101];
int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;  
    for(int i=0;i<puddles.size();i++){
        DP[puddles[i][1]][puddles[i][0]] = -1;
    }
    for(int i=0;i<=n;i++){
        if(DP[i][1]==-1)
            break;
        DP[i][1] = 1;
    }
    for(int i=0;i<=m;i++){
        if(DP[1][i]==-1)
            break;
        DP[1][i] = 1;
    }
    for(int i=2;i<=n;i++){
        for(int j=2;j<=m;j++){
            if(DP[i][j]==-1) continue;
            DP[i][j] = max({DP[i-1][j],DP[i][j-1],DP[i-1][j]+DP[i][j-1]})%1000000007; 
        }
    }
    return DP[n][m];
}