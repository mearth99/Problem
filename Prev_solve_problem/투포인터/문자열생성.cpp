#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n,l,r,output_idx=0;
    cin >> n;
    char arr[2001];
    char output[2001];
    for(int i=0;i<n;i++)
        cin >> arr[i];
    l=0,r=n-1;
    while(l<=r){
        if(arr[l]<arr[r]){
            output[output_idx++] = arr[l++];
        }else if(arr[l]==arr[r]){
            int nl = l+1, nr = r-1;
            if(arr[nl]<=arr[nr])
                output[output_idx] = arr[l++];
            else
                output[output_idx] = arr[r--];
        }
        else{
            output[output_idx++] = arr[r--];
        }
    }
    for(int i=0;i<n;i++){
        if(i!=0&&i%80==0) cout << endl;
        cout << output[i];
        
    }
    return 0;
}