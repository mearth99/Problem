#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

int DP[1001][1001] = {0};
int main(){

    string A, B;
    int A_index = 0, B_index = 0;
    cin >> A >> B;

    for(int i=0;i<=A.length();i++)
        DP[i][0] = i;
    for(int i=0;i<=B.length();i++)
        DP[0][i] = i;
    for(int i=1;i<=A.length();i++){
        for(int j=1;j<=B.length();j++){
            if(A.at(i-1)==B.at(j-1)){
                DP[i][j] = DP[i-1][j-1]; 
            }else{
                DP[i][j] = min({DP[i-1][j]+1 , DP[i][j-1]+1, DP[i-1][j-1]+1});
            }
        }
    }
    cout << DP[A.length()][B.length()];
    return 0;
}