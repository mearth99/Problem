#include <iostream>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<int> sticker)
{
   /*조건이 있는 DP문저체럼 보인다.
   1. 현재 이녀석을 선택한다. 선택하지 않는다.
   2. 선택한 경우, 이전과 다음은 사용할 수 없다.
   3. DP[i] = max(DP[i-1],DP[i-2] + A[i]); 의 꼴이며
    A[0]에서 시작과 A[1]에서 시작으로 구분할 수 있다.
   */
    int n = sticker.size();
    vector<int> DP(n);
    vector<int> DP2(n);
    DP[0] = sticker[0];
    DP[1] = sticker[0];
    DP2[0] = 0;
    DP2[1] = sticker[1];
    
    for(int i=2;i<n-1;i++){
        DP[i] = max(DP[i-1],DP[i-2] + sticker[i]);
    }
    for(int i=2;i<n;i++){
        DP2[i] = max(DP2[i-1],DP2[i-2] + sticker[i]);
    }

    
    return max(*max_element(DP.begin(),DP.end()),*max_element(DP2.begin(),DP2.end()));
}