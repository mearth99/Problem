#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;
#define INF 2100000000
vector<int> arr;
int sum(int start, int end){
    int sum = 0;
    for(int i=start;i<=end;i++)
        sum += arr[i];
    return sum;
}

    
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,s,p1,p2;
    int maxvalue = INF;
    cin >> n >> s;
    arr.resize(n);
    for(int i=0;i<n;i++)
        cin >> arr[i];
    sort(arr.begin(),arr.end());
    int l=0,r=0;
    int minv = INF;
    while(l<=r && r<n){
       int value = sum(l,r);
       if(value<s) r++;
       else if(value>s) l++;
       else minv = min(minv,r-l);
    }
    cout << l << r;
    return 0;
}