#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;
#define INF 2100000000

    
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,p1,p2;
    int maxvalue = INF;
    cin >> n;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
        cin >> arr[i];
    sort(arr.begin(),arr.end());
    int l=0,r=n-1;
    while(l<r){
        if(abs(arr[l]+arr[r])<maxvalue){
            maxvalue = abs(arr[l]+arr[r]);
            p1 = l;
            p2 = r;
            if(arr[l]+arr[r]==0) break;
        }
        if(arr[l]+arr[r]<0) l++;
        else r--;
    }
    cout << arr[p1] << " " << arr[p2];
    return 0;
}