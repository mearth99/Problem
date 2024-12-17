#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

vector<int> graph[20];
struct ani{
    int cur;
    int sheep;
    int wolf;
    
};
int solution(vector<int> info, vector<vector<int>> edges) {
    int answer = 0;
    for(auto it : edges)
        graph[it[0]].push_back(it[1]);
    queue<ani> q;
    q.push({0,0,0});
    while(!q.empty()){
        int cur = q.front().cur;
        int sheep = q.front().sheep; 
        int wolf = q.front().wolf; q.pop();
        if(info[cur]==0) sheep++;
        else wolf++;
        if(wolf>=sheep) continue;
        answer = max(answer,sheep);
        for(auto it : graph[cur]){

        }
    }


    return answer;
}

int main(){
    vector<int> info = {0,0,1,1,1,0,1,0,1,0,1,1};
    vector<vector<int>> edges = {{0,1},{1,2},{1,4},{0,8},{8,7},{9,10},{9,11},{4,3},{6,5},{4,6},{8,9}};
    cout << solution(info, edges);
    return 0;	
}