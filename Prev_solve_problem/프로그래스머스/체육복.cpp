#include <string>
#include <vector>
#include <algorithm>
using namespace std;
bool lost_bool[32];
int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = n-lost.size();
    sort(lost.begin(),lost.end());
    sort(reserve.begin(),reserve.end());
    for(int i=0;i<lost.size();i++){
        lost_bool[lost[i]] = true;
    }
    for(int i=0;i<reserve.size();i++){
        if(lost_bool[reserve[i]]){
            answer++;
            lost_bool[reserve[i]] = false;
            reserve[i] = -1;
        }
    }
    for(int i=0;i<reserve.size();i++){
        if(reserve[i]==-1)
            continue;
        if(lost_bool[reserve[i]-1]){
            answer++;
            lost_bool[reserve[i]-1] = false;
            continue;
        }
        else if(lost_bool[reserve[i]+1]){
            answer++;
            lost_bool[reserve[i]+1] = false;
            continue;
        }    
    }
    return answer;
}