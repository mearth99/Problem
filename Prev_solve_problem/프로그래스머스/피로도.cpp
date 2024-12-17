#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool visit[8];
int answer = 0;
void dfs(int energe,int limit,int count,vector<vector<int>> dungeons){
    answer = count > answer ? count : answer; 
    for(int i=0;i<dungeons.size();i++){
      if(visit[i])
        continue;
      if(energe>=dungeons[i][0]){
        visit[i] = true;
        count++;
        energe -=dungeons[i][1];
        dfs(energe,limit,count,dungeons);
        visit[i] = false;
        count--;
        energe += dungeons[i][1];
      }

    }
} 

int solution(int k, vector<vector<int>> dungeons) {
    //dfs를 통해 모든 경우의 수를 탐색한다.
    int limit = (*min_element(dungeons.begin(),dungeons.end()))[0];
    dfs(k,limit,0,dungeons);
    return answer;
}