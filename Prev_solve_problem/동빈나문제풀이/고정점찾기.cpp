#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> space(n);
    for(int i=0;i<n;i++){
        cin >> space[i];
    }
    int start = 0, end = n-1, mid;
    while(start<=end){
        mid = (start + end) / 2;
        if(space[mid]==mid)
            break;
        else if(space[mid]>mid)
            end = mid-1;
        else
            start = mid+1;
    }
    if(space[mid]==mid)
        cout << mid;
    else cout << -1;
    return 0;
}