#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>

using namespace std;


int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N,M,left=0,right=0,count=0;
    vector<int> T;
    cin >> N >> M;
    T.resize(N);
    right=N-1;
    for(int i=0;i<N;i++){
        cin >> T[i];
    }
    sort(T.begin(),T.end());
    while(left<right){
        int v = T[left] + T[right];
        if(v>M)
            right--;
        else if(v==M){
            count++;
            left++;
            right--;
        }
        else
            left++;
    }
    cout << count;
}