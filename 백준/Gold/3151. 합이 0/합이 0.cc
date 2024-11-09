#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;

/*
1. 정렬
2. 선택한 대상보다 반드시 높은 곳에서 시작. => 이래야 중복 X
*/



int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N;
    cin >> N;
    vector<int> arr;
    for(int i=0;i<N;i++){
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }
    sort(arr.begin(),arr.end());
    long long ans = 0;
    for(int i=0;i<N-2;i++){
        for(int j=i+1;j<N-1;j++){
            long long cnt = (arr[i] + arr[j])*-1;
            int low = lower_bound(arr.begin()+j+1,arr.end(),cnt) - arr.begin();
            int upp = upper_bound(arr.begin()+j+1,arr.end(),cnt) - arr.begin();
            ans += upp-low;
        }
    }
    cout << ans;
}