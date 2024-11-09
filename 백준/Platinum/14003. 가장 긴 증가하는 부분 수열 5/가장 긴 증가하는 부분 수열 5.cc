#include<algorithm>
#include<iostream>
#include<vector>

using namespace std;

int main(){
    int n,dp_idx=0,it=1;
    cin >> n;
    vector<int> arr(n);
    vector<int> DP;
    vector<int> output;
    vector<int> sub(n);

    for(int i=0;i<n;i++)
        cin >> arr[i];

    DP.push_back(arr[0]);
    for(int i=1;i<n;i++){
        if(DP.back()<arr[i]){
            DP.push_back(arr[i]);
            sub[i] = DP.size()-1;
            continue;
        }
        int idx = lower_bound(DP.begin(),DP.end(),arr[i])-DP.begin();
        DP[idx] = arr[i];
        sub[i] = idx;
    }
    int maxv = DP.size()-1;
    for(int i=n-1;i>=0;i--){
        if(sub[i]==maxv){
            output.push_back(arr[i]);
            maxv--;
        }
    }
    cout << output.size() << '\n';
    for(int i=output.size()-1;i>=0;i--){
        cout << output[i] << " ";
    }
    return 0;
}