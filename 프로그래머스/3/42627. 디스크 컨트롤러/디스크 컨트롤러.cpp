#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;
struct cmp{
    bool operator()(pair<int,int>&p1,pair<int,int>&p2){
        return p1.second > p2.second;
    }
};

int solution(vector<vector<int>> jobs) {
    //1. 작업이 요청되는 시점으로 정렬하라.
    //2. 모두 작업을 할 수 있는 경우, 작업의 소요시간이 작은 순서대로 정렬하라.
    int answer = 0;
    int times = 0;
    priority_queue<pair<int, int>,vector<pair<int, int>>,greater<pair<int, int>>> queues;
    priority_queue<pair<int, int>,vector<pair<int, int>>,cmp> nextqueues;
    
    for(int i=0;i<jobs.size();i++){
        queues.push(make_pair(jobs[i][0],jobs[i][1]));
    }
    while(!queues.empty()||!nextqueues.empty()){
        if(!queues.empty()&&nextqueues.empty()&&times<queues.top().first)
            times = queues.top().first;
        while(times>=queues.top().first&&!queues.empty()){
            nextqueues.push(queues.top());
            queues.pop();
        }
        times += nextqueues.top().second;
        answer += (times - nextqueues.top().first);
        cout << answer << endl;
        nextqueues.pop();  
    }
    return answer/jobs.size();
}