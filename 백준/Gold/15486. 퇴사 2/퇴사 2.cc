
#include <iostream>
#include <algorithm>
using namespace std;

int DP[1500002];
pair<int,int> discuss[15000002]; //first : Ti, Second : Pi
int main()
{
    int n,nowmax=0;
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> discuss[i].first >> discuss[i].second;
    }

    for(int i=1;i<=n+1;i++){
        nowmax = max(nowmax,DP[i]);
        if(i+discuss[i].first>n+1) continue;
        DP[i+discuss[i].first] = max(DP[i+discuss[i].first],nowmax+discuss[i].second);
    }
    cout << DP[n+1];
    return 0;
}
