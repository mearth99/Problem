

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define INF 987654321
#define MAXV 10000001
using namespace std;
int DP[MAXV];

int main(){
    for(int i=1;i<MAXV;i++)
        DP[i] = INF;
    vector<int> output;
    int n;
    cin >> n;
    DP[n] = 1;
    for(int i=n;i>=1;i--){
        if(i%3==0)
            DP[i/3] = min(DP[i/3], DP[i]+1);
        if(i%2==0)
            DP[i/2] = min(DP[i/2], DP[i]+1);
        DP[i-1] = min(DP[i]+1,DP[i-1]);
    }
    int idx=1;
    output.push_back(idx);
    while(idx!=n){
        if(DP[idx*3]==DP[idx]-1)
            idx*=3;
        else if(DP[idx*2]==DP[idx]-1)
            idx*=2;
        else
            idx+=1;
        output.push_back(idx);
        
    }
    cout << DP[1]-1 << endl;
    for(int i=output.size()-1;i>=0;i--)
        cout << output[i] << " ";
}