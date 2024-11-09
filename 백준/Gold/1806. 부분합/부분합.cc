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
    int N, S;
    cin >> N >> S;
    vector<int> arr(N);
    for(int i=0;i<N;i++)
        cin >> arr[i];
    int start=0, end=0;
    int sum=arr[0];
    int miv = 1e9;
    while(end<N){
        if(sum<S){
            end++;
            if(end<N)
                sum += arr[end];
        }else{
            miv = min(miv, end-start+1);
            sum -= arr[start];
            start++;
        }
    }
    if(miv == (int)1e9) cout << 0;
    else cout << miv;
    return 0;
}