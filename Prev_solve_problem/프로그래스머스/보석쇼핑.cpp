#include <string>
#include <vector>
#include <unordered_map>
#include <set>
#include <iostream>
using namespace std;
//진열된 모든 종류의 보석을 적어도 1개 이상 포함하는 가장 짧은 구간을 찾아서 구매

vector<int> solution(vector<string> gems) {
    vector<int> answer;
    set<string> all;
    unordered_map<string,int> current;
    for(auto idx : gems)
      all.insert(idx);
    int start = 0;
    int end = 0;
    answer.push_back(start + 1);
    answer.push_back(end + 1); 
    while(end<gems.size()){
      current[gems[end]]++;
      end++;
    }
    return answer;
}