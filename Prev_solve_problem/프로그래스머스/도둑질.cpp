#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int DP[1000001][2];
int solution(vector<int> money) {

    DP[0][0] = money[0];
    DP[1][0] = money[0];
    DP[1][1] = money[1]; 
    for(int i=2;i<money.size()-1;i++){
        DP[i][0] = max(DP[i-2][0] + money[i], DP[i-1][0]);
    }
    for(int i=2;i<=money.size()-1;i++){
        DP[i][1] = max(DP[i-2][1] + money[i], DP[i-1][1]);
    }
    

    return max(DP[money.size()-2][0],DP[money.size()-1][1]);
}