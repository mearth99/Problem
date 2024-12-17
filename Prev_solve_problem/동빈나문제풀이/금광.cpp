#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

int main(){

    int T;
    cin >> T;

    while(T>0){
        int n,m,maxv=0;
        cin >> n >> m;
        vector<vector<int>> gold(n,vector<int>(m));
        vector<vector<int>> DP(n,vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++)
                cin >> gold[i][j];
            DP[i][0] = gold[i][0];
        }
        for(int j=0;j<m-1;j++)
            for(int i=0;i<n;i++){
            if(i>0 && i<n-1){
                DP[i][j+1] = max({DP[i][j]+gold[i][j+1],DP[i-1][j]+gold[i][j+1],DP[i+1][j]+gold[i][j+1]});
            }else if(i==0){
                DP[i][j+1] = max({DP[i][j]+gold[i][j+1],DP[i+1][j]+gold[i][j+1]});
            }else{
                DP[i][j+1] = max({DP[i][j]+gold[i][j+1],DP[i-1][j]+gold[i][j+1]});
            }
        }
        for(int i=0;i<n;i++)
            maxv = max(maxv,DP[i][m-1]);
        cout << maxv << '\n';
        maxv=0;
        gold.clear();
        DP.clear();
        T--;
    }
    return 0;
}