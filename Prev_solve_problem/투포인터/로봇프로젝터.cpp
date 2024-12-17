#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;

// x만큼 떨어진 거리에 있는 얼음의 누적합을 비교하여 최댓값을 출력한다.
// 

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int x,n;
    while(cin >> x >> n){
        int temp;
        vector<int> arr;
        for(int i=0;i<n;i++){
            cin >> temp;
            arr.push_back(temp);
        }
        sort(arr.begin(),arr.end());
        int l,r,v;
        x *= 10000000;
        l=0;
        r=arr.size()-1;
        while(l<r){
            v = arr[r] + arr[l];
            if(v==x) break;   
            else if(v>x) r--;
            else l++;
        }
        if(v==x)
            cout << "yes " << arr[l] << " " << arr[r] << endl;
        else
            cout << "danger" << endl;
        arr.clear();
    }
    return 0;
}