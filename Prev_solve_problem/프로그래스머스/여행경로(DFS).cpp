#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;
vector<string> answer;
bool visit[10001];

void dfs(int count, string current,vector<string> route, vector<vector<string>> tickets){
    route.push_back(current);
    if(count==tickets.size()){
        if(answer.empty()) answer = route;
        else{
            for(int i=0;i<route.size();i++){
                int result = answer[i].compare(route[i]);
                if(result>0) answer = route;
                else if(result==0) continue;
                else break;
            }
        }   
    }
    for(int i=0;i<tickets.size();i++){
        if(visit[i])
            continue;
        if(current.compare(tickets[i][0])==0){
            visit[i] = true;
            dfs(count+1,tickets[i][1],route,tickets);
            visit[i] = false;
        }
    }
}
vector<string> solution(vector<vector<string>> tickets) {
    vector<string> route;
    dfs(0,"ICN",route,tickets);
    return answer;
}