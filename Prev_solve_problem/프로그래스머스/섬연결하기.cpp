#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int cycle[101];

int getParent(int parent[], int x){
  if(parent[x]==x) return x;
  return parent[x] = getParent(parent,parent[x]);
}
void unionParent(int parent[], int a, int b){
  a = getParent(parent, a);
  b = getParent(parent, b);
  if(a<b) parent[b] = a;
  else parent[a] = b;
  return;
}
int findParent(int parent[], int a, int b){
  a = getParent(parent, a);
  b = getParent(parent, b);
  if(a==b) return 1;
  return 0;
}
bool cmp(vector<int>&p1,vector<int>&p2){
  return p1[2] < p2[2];
}
int solution(int n, vector<vector<int>> costs) {
  //크루스칼 알고리즘으로 해결해보자.
    
    int answer = 0;
    for(int i=0;i<101;i++)
      cycle[i] = i;
    //비용[2] 오름차순으로 초기화하였다.
    sort(costs.begin(),costs.end(),cmp);
    for(int i=0;i<costs.size();i++){
      if(!findParent(cycle,costs[i][0],costs[i][1])){
        answer += costs[i][2];
        unionParent(cycle,costs[i][0],costs[i][1]);
      }
    }

    return answer;
}