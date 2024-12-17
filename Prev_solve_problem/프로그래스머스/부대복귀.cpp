#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;
vector<int> distances[100001];

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
    vector<int> answer;
    vector<int> value(n+1,-1);
    queue<pair<int,int>> q;
    for(int i=0;i<roads.size();i++){
      distances[roads[i][0]].push_back(roads[i][1]);
      distances[roads[i][1]].push_back(roads[i][0]);
    }
    q.push(make_pair(destination,0));
    /*
    목적지에서 각 sources에 도착했을 때 최소 비용을 갱신하는 식으로 탐사.
    저장된 최소비용을 이용. 
    최소비용이 0이면 -1을 반환
    BFS로 탐색. 양방향임.
    */
    while(!q.empty()){
      int target = q.front().first;
      int count = q.front().second;
      q.pop();
      for(auto idx : distances[target]){
        if(value[idx]==-1 || value[idx]>count+1){
          q.push({idx,count + 1});
          value[idx] = count + 1;
        }
      }
    }
    value[destination] = 0;
    for(auto idx : sources)
      answer.push_back(value[idx]);
    return answer;
}