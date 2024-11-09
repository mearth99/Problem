#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;


int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n,output;
    cin >> n;
    vector<int> T(n);
    for(int i=0;i<n;i++)
        cin >> T[i];
    sort(T.begin(),T.end());
    int l=0,r=n-1,d=876543210;
    while(l<r){
        int v = T[l] + T[r];
        if(abs(v)<d){
            d=abs(v);
            output = v;
        }
        if(v>0)
            r--;
        else 
            l++;        
    }
    cout << output;
}