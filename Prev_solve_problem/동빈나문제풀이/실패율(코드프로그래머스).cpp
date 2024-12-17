#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
double clear_state[502] = {0};

bool cmp(pair<double,int> &p1,pair<double,int> &p2){
    if(p1.first==p2.first){
        return p1.second < p2.second;
    }else
        return p1.first < p2.first;
}
vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    for(auto it : stages)
        clear_state[it]++;
    vector<pair<double,int>> result;
    double people = stages.size();
    for(int i=1;i<=N;i++){
        result.push_back({clear_state[i]/people,i});
        cout << clear_state[i]/people << endl;
        people-=clear_state[i];
    }
    sort(result.begin(),result.end(),cmp);
    for(auto it : result)
        answer.push_back(it.second);
    return answer;
}