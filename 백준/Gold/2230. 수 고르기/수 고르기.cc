#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N,M,left=0,right=0,output= 2000000001;
    cin >> N >> M;
    vector<int> T(N);
    for(int i=0;i<N;i++){
        cin >> T[i];
    }
    sort(T.begin(),T.end());
    while(left<N && right<N){
        int v = T[right] - T[left];
        if(v>=M){
            output = min(output,v);
            left++;
        }else{
            right++;
        }
    }
    cout << output;
    return 0;
}