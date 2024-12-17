#include <string>
#include <vector>

using namespace std;

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    //A와 B가 같이갈 수 있는 최단 거리, A에서 목적지까지 갈 수 있는 최단 거리, B에서 목적지까지 갈 수 있는 최단거리, AB에서 목적지까지 가는 최단거리
    // => 목적지에서 A, 목적지에서 B, 목적지에서 AB
    vector<vector<int>> graph(n+1, vector<int> (n+1,INT_MAX/2-1));
    for(auto i : fares){
        graph[i[0]][i[1]] = i[2]; 
        graph[i[1]][i[0]] = i[2]; 
    }
    for(int k=0;k<n;k++){
      for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
          if(graph[i][k]+graph[k][j] < graph[i][j]){
            graph[i][j] = graph[i][k]+graph[k][j];
          }
        }
      } 
    }
    int answer = 0;
    return answer;
}