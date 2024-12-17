#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer(2);
    priority_queue<int, vector<int>, greater<int>> minqueue; //오름차순
    priority_queue<int, vector<int>> maxqueue; //내림차순
    int q_idx = 0;
    for(int i=0;i<operations.size();i++){
      if(q_idx==0){
        while(!minqueue.empty()) minqueue.pop();
        while(!maxqueue.empty()) maxqueue.pop();

      }
      size_t found = operations[i].find('I');
      if(found==0){
        //Queue에 삽입합니다.
        int value =  stoi(operations[i].substr(2));
        maxqueue.push(value);
        minqueue.push(value);
        q_idx++;
      }else{
        //Queue에서 삭제합니다.
        found = operations[i].find('-');
        if(found!=string::npos){
          //Queue에서 최솟값을 삭제합니다.
          
          if(minqueue.size()!=0){
            minqueue.pop();
            q_idx--;
          }
        }else{
          //Queue에서 최대값을 삭제합니다.
          if(maxqueue.size()!=0){
            maxqueue.pop();
            q_idx--;
          }
        }
      }
    }
    if(q_idx!=0){
      answer[0] = maxqueue.top(); 
      answer[1] = minqueue.top();
    }
    return answer;
}