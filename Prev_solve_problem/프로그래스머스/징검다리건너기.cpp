#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> stones, int k) {
    int answer = 0;
    //한번에 건너뛸 수있는 디딤돌의 최대 칸수 K가 주어진다.
    //즉, 돌의 개수와 상관 없이, K-1개의 돌은 무시할 수 있다.
    //하지만, K개의 돌이 연속으로 0인 순간, 건널 수 없다.
    int start = 0;
    int end = *max_element(stones.begin(),stones.end());
    while(start<=end){
        int mid = (start + end) /2;
        int count = 0;
        for(int i=0;i<stones.size();i++){
            if(stones[i]<=mid){
                count++;
            }else{
                count = 0;
            }
            if(count>=k){
                end = mid -1;
                break;
            }
        }
        if(count<k){ //count가 K와 동일한 경우 건널 수 없기 때문에, 건널 수 있는 값 중 가장 큰 mid의 값을 계속 저장시킨다.
            start = mid + 1;
            answer = start;
        }
    }
    return answer;
}