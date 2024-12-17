#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;
struct airplane{
    int count;
    string locate;
    vector<string> visit;
};
bool check[10001];
vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    queue<airplane> q;
    airplane temp;
    temp.count = 0; temp.locate = tickets[0][0]; temp.visit.push_back("ICN");
    q.push(temp);
    while(!q.empty()){
        temp = q.front();
        q.pop();
        if(temp.count == tickets.size()){
            if(answer.empty()){
                answer = temp.visit;
            }else{
                for(int i=1;i<temp.visit.size();i++){
                    int result = answer[i].compare(temp.visit[i]);
                    if(result>0) answer = temp.visit;
                    else if(result==0) continue;
                    else break;
                }
            }
        }
        for(int i=0;i<tickets.size();i++){
            if(temp.locate==tickets[i][0]&&!check[i]){
                airplane nt;
                nt.locate = tickets[i][1];
                nt.count = temp.count + 1;
                nt.visit = temp.visit;
                nt.visit.push_back(tickets[i][1]);
                
                q.push(nt);
            }
        }
    }
    for(int i=0;i<tickets.size();i++)
        cout << check[i] << " ";

    return answer;
}