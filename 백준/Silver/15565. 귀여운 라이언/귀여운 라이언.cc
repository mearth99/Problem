#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N,k,output=987654321;
    cin >> N >> k;
    vector<int> T(N);
    vector<int> one;

    for(int i=0;i<N;i++){
        cin >> T[i];
        if(T[i]==1) one.push_back(i);
    }
    if(one.size()<k){ 
        cout << -1;
        return 0;
    }
    for(int i=k-1;i<one.size();i++){
        int cur = one[i];
        int pre = one[i-k+1];
        output = min(output, cur-pre+1);
    }
    cout << output;
    return 0;
}