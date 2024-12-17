#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    while(!progresses.empty()){
        int value=1;
        int count=0;
        for(value;progresses[0]+speeds[0]*value<100;value++){
            value=value;
        }
        for(int i=0;i<progresses.size();i++){
            progresses[i] += speeds[i]*value;
        }
        while(*progresses.begin()>=100){
            progresses.erase(progresses.begin() + 0);
            count++;
        }
        answer.push_back(count);
    }
    return answer;
}