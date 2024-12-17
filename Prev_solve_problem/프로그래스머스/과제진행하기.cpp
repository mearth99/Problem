#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;
struct homework{
    string task;
    int start;
    int process;
};
bool cmp(homework p1, homework p2){
    return p1.start < p2.start;
}

int change_time(string t){
    int h,m,count=0;
    while(count < t.length()){
        if(t.at(count)==':') break;
        count++;
    }
    h = stoi(t.substr(0,count));
    m = stoi(t.substr(count+1));
    return h*60+m;
}

vector<string> solution(vector<vector<string>> plans) {
    vector<string> answer;
    int cur_time = 0,next_time=0;
    vector<homework> curtask;
    stack<homework> stoptask;
    for(auto it : plans){
        curtask.push_back({it[0],change_time(it[1]),stoi(it[2])});
    }
    sort(curtask.begin(),curtask.end(),cmp);
    for(int i=0;i<curtask.size();i++){
        cur_time = curtask[i].start;
        if(i+1<curtask.size())
            next_time = curtask[i+1].start;
        else
            next_time = 987654321; 
        if(cur_time+curtask[i].process <= next_time){
            //다음 과제까지 시간이 겹치지 않는 경우
            answer.push_back(curtask[i].task);
            cur_time = cur_time+curtask[i].process;
            if(cur_time == next_time) continue;
        }else{
            //다음 과제와 시간이 겹치는 경우.
            curtask[i].process = curtask[i].process + cur_time - next_time;
            stoptask.push(curtask[i]);
            continue;  
        }
        //다음과제와 시간이 겹치지 않게 끝난 경우 Stop에서 꺼내서 확인한다.
        while(!stoptask.empty()){
            homework target = stoptask.top();
            if(cur_time + target.process <= next_time){
                answer.push_back(target.task);
                stoptask.pop();
                cur_time += target.process;
            }else{
                target.process = target.process + cur_time - next_time;
                stoptask.pop();
                stoptask.push(target);
                break;
            }
        }
    }
    return answer;
}

int main(){
    vector<vector<string>> plans = {{"korean", "11:40", "30"}, {"english", "12:10", "20"}, {"math", "12:30", "40"}};
    solution(plans);
    return 0;
}