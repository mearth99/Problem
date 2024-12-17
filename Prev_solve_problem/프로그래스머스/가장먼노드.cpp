#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(int n, vector<vector<int>> edge) {
    queue<int> q;
    vector<int> counts(n+1);
    int answer = 0,maxvalue;
    q.push(1);
    counts[1] = 1;
    while(!q.empty()){
        int target = q.front();
        int opponent;
        q.pop();
        for(int i=0;i<edge.size();i++){
            if(edge[i][0]==target)
                opponent = edge[i][1];
            else if(edge[i][1]==target)
                opponent = edge[i][0];
            else continue;
            if(counts[target]==0 || counts[opponent]!=0) continue;
            counts[opponent] = counts[target] + 1;
            q.push(opponent);
        }
    }
    maxvalue = *max_element(counts.begin(),counts.end());
    for(auto idx : counts)
        if(idx==maxvalue)
            answer++;
    return answer;
}