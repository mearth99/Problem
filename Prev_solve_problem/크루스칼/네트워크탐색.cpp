
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
struct computer{
  int from;
  int to;
  int cost;
};
computer make_computer(int from, int to, int cost){
  computer temp;
  temp.cost = cost;
  temp.to = to;
  temp.from = from;
  return temp;
}
bool cmp(computer &p1, computer &p2){
  return p1.cost < p2.cost;
}
int node[1001];
int Get_Parents(int target){
  if(target==node[target]) return target;
  else return node[target] = Get_Parents(node[target]);
}
void Union_Parents(int first, int second){
  first = Get_Parents(first);
  second = Get_Parents(second);
  if(first>second)
    node[first] = second;
  else
    node[second] = first;
}
bool Find_Parents(int first, int second){
  first = Get_Parents(first);
  second = Get_Parents(second);
  if(first==second) return 1;
  else return 0;
}
int main(){
  int n,m;
  cin >> n >> m;
  vector<computer> graph; 
  for(int i=0;i<m;i++){
    int from, to, cost;
    cin >> from >> to >> cost;
    graph.push_back(make_computer(from,to,cost));
    graph.push_back(make_computer(to,from,cost));
    // graph.push_back(make_computer(to,from,cost));
  }
  for(int i=0;i<1001;i++) node[i] = i;
  sort(graph.begin(),graph.end(),cmp);

  int sum=0;
  for(int i=0;i<graph.size();i++){
    if(!Find_Parents(graph[i].from,graph[i].to)){
      sum += graph[i].cost;
      Union_Parents(graph[i].from,graph[i].to);
    }
  }
  
  cout << sum;
}