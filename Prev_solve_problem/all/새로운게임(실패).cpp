#include <bits/stdc++.h>
using namespace std;

struct chess{
    int x,y,d;
};

int main(){
	int N, K;
    cin >> N >> K;
    vector<vector<int>> arr(N,vector<int>(N));
    vector<chess> unit;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin >> arr[i][j];
        }
    }
    for(int i=0;i<K;i++){
        int x,y,d;
        cin >> x >> y >> d;
        
    }
    return 0;
}