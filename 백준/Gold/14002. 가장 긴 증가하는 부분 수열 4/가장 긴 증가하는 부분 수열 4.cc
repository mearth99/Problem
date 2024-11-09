#include<algorithm>
#include<iostream>
#include<vector>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    vector<int> DP(n+1);
    vector<int> sub;

    for(int i=0;i<n;i++)
        cin >> arr[i];
    for(int i=0;i<n;i++){
        DP[i] = 1;
        for(int j=0;j<n;j++){
            if(arr[i]>arr[j]){
                DP[i] = max(DP[i],DP[j]+1);
            } 
        }
    }
    int maxvalue = *max_element(DP.begin(),DP.end());
    cout << maxvalue << '\n';
    for(int i=n-1;i>=0;i--){
        if(DP[i]==maxvalue){
            sub.push_back(arr[i]);
            maxvalue--;
        }
    }
    for(int i=sub.size()-1;i>=1;i--){
        cout << sub[i] << " ";
    }
    cout << sub[0];
    return 0;
}