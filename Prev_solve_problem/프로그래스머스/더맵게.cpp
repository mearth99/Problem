#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int,vector<int>,greater<int>> queues;
    for(int i=0;i<scoville.size();i++){
      queues.push(scoville[i]);
    }
    while(queues.size()>1&&queues.top()<K){
      int first = queues.top();
      queues.pop();
      int second = queues.top();
      queues.pop();
      queues.push(first+second*2);
      answer++;
    }
    return answer;
}