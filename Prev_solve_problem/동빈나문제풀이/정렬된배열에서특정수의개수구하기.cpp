#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

int main(){
    int n,k;
    cin >> n >> k;
    int from,to;
    vector<int> space(n);
    for(int i=0;i<n;i++){
        cin >> space[i];
    }
    int start = 0, end = *max_element(space.begin(),space.end()), mid;
    while(start<=end){
        mid = (start + end) / 2;
        if(space[mid]>=k)
            end = mid-1;
        else
            start = mid+1;
    }
    from = start;
    while(start<=end){
        mid = (start + end) / 2;
        if(space[mid]==k){
            if(mid==n-1 || space[mid+1]!=k)
                break;
            else
                start = mid+1;
        }
        else if(space[mid]<k)
            end = mid-1;
        else
            start = mid+1;
    }
    to = mid;
    cout << to - from;
    return 0;
}