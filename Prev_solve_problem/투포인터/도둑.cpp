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
    int T;
    cin >> T;
    while(T--){
        int n,m,k;
        cin >> n >> m >> k;
        vector<int> house(n);
        vector<int> sum;
        for(int i=0;i<n;i++){
            cin >> house[i];
        }
        sum.push_back(house[0]);
        for(int i=1;i<n;i++)
            sum.push_back(sum[i-1]+house[i]);   
    }
}