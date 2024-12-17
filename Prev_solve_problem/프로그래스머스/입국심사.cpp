#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long solution(int n, vector<int> times) {
    //시간을 기준으로 이분탐색을 진행한다.
    //1. 최솟값: 1 최대값:times[times.size()-1] * n
    sort(times.begin(),times.end());
    long long answer = 0;
    long long start = 1;
    long long end = (long long)times[times.size()-1] * n;
    while(start <= end){
        long long count = 0;
        long long mid = (start + end) / 2;
        for(int i=0;i<times.size();i++){
            count += mid/times[i];
        }
        if(count < n){
            start = mid + 1;
        }else{
            if(mid<=end){
                answer = mid;
            }
            end = mid - 1;
        }
        
    }
    return answer;
}