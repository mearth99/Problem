#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;

// x만큼 떨어진 거리에 있는 얼음의 누적합을 비교하여 최댓값을 출력한다.
// 

vector<int> sum(1000001);

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n,k,output=0;
    cin >> n >> k;
    for(int i=0;i<n;i++){
        int x, v;
        cin >> v >> x;
        if(x-k>=0)
            sum[x-k] +=v;
        else
            sum[0] += v;
        if(x+k+1<1000001)
            sum[x+k+1] -= v;  
    }
    for(int i=1;i<1000001;i++){
        sum[i] += sum[i-1];
        output = max(sum[i],output);
    } 
    cout << output;
    return 0;
}