#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t,N,K;
    vector<int> output;
    cin >> t;
    while(t-->0){
        cin >> N >> K;
        int left=0,right=N-1,dis=987654321,out=0;
        vector<int> T(N);
        for(int i=0;i<N;i++){
            cin >> T[i];
        }
        sort(T.begin(),T.end());
        while(left<right){
            int v = T[right] + T[left];
            if(abs(K-v) < dis){
                dis = abs(K-v);
                out = 1;
            }
            else if(abs(K-v) == dis)
                out++;
            
            if(v<K)
                left++;
            else if(v==K){
                left++;
                right--;
            }else
                right--;    
        }
        output.push_back(out);
        T.clear();
    }
    for(auto it : output)
        cout << it << '\n';
    return 0;
}