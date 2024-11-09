#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;


    
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,x,count=0;
    cin >> n;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
        cin >> arr[i];
    cin >> x;
    sort(arr.begin(),arr.end());
    int l=0,r=n-1;
    while(1){
        if(l>=r) break;
        if(arr[l]+arr[r]==x){
            count++;
            l++; r--;
        }
        else if(arr[l]+arr[r]>x) r--;
        else l++;
    }
    cout << count;
    return 0;
}