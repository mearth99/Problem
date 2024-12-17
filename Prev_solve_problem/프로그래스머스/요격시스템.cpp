#include <string>
#include <vector>
#include <algorithm>
using namespace std;
bool cmp(vector<int> &p1,vector<int> &p2){
  return p1[1] < p2[1]; 
}
int solution(vector<vector<int>> targets) {
    int answer = 1;
    sort(targets.begin(),targets.end(),cmp);
    int last = targets[0][1];
    for(auto idx : targets){
      if(idx[0]<last)
        continue;
      else{
        last = idx[1];
        answer++;
      }
    }
    return answer;
}