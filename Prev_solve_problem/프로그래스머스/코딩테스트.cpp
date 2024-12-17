#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int alp, int cop, vector<vector<int>> problems) {
    vector<vector<int>> dp(152,vector<int>(152,1000000));
    int max_alp = -1;
    int max_cop = -1;
    for(auto i : problems){
        max_alp = max(max_alp,i[0]);
        max_cop = max(max_cop,i[1]);
    }
    max_alp = max(alp,max_alp);
    max_cop = max(cop,max_cop);
    dp[alp][cop] = 0;
    for(int i=alp;i<=max_alp;i++){
        for(int j=cop;j<=max_cop;j++){
            int ni = i+1<=max_alp ? i+1 : max_alp;
            int nj = j+1<=max_cop ? j+1 : max_cop;
            dp[ni][j] = min(dp[ni][j],dp[i][j]+1);
            dp[i][nj] = min(dp[i][nj],dp[i][j]+1);
            for(auto p: problems){
                if(i>=p[0] && j>=p[1]){
                    ni = i+p[2]<=max_alp ? i+p[2] : max_alp; 
                    nj = j+p[3]<=max_cop ? j+p[3] : max_cop; 
                    dp[ni][nj] = min(dp[ni][nj],dp[i][j]+p[4]);
                }
            }
        }
    }

    return dp[max_alp][max_cop];
}