/*
입력
첫째 줄에 테스트 케이스의 개수 t가 주어진다. (t ≤ 50)
각 테스트 케이스의 첫째 줄에는 맥주를 파는 편의점의 개수 n이 주어진다. (0 ≤ n ≤ 100).
다음 n+2개 줄에는 상근이네 집, 편의점, 펜타포트 락 페스티벌 좌표가 주어진다. 각 좌표는 두 정수 x와 y로 이루어져 있다. (두 값 모두 미터, -32768 ≤ x, y ≤ 32767)
송도는 직사각형 모양으로 생긴 도시이다. 두 좌표 사이의 거리는 x 좌표의 차이 + y 좌표의 차이 이다. (맨해튼 거리)

출력
각 테스트 케이스에 대해서 상근이와 친구들이 행복하게 페스티벌에 갈 수 있으면 "happy", 
중간에 맥주가 바닥나서 더 이동할 수 없으면 "sad"를 출력한다.

시도: DFS를 시도해보자 //DFS는 성공했는데, 굳이 다시 돌아가서 탐색할 이유가 없었다.
vistied = false를 제거하니 성공적으로 수행하였다.
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool flag = false;
int cacu(int a, int b, int c, int d){
  return abs(a-b) + abs(c-d);
}

void DFS(int x, int y, vector<vector<int>> &position, vector<bool> &visited){
  int dest = position.size()-1;
  if(cacu(x,position[dest][0],y,position[dest][1])<=1000 || flag){
    flag = true;
    return;
  }
  for(int i=0;i<dest;i++){
    if(visited[i])
      continue;
    if(cacu(x,position[i][0],y,position[i][1])<=1000){
      visited[i] = true;
      DFS(position[i][0],position[i][1],position,visited);
    }
  }  
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t,n;
    cin >> t;
    for(int tried = 0; tried < t; tried++){
      cin >> n;
      vector<vector<int>> position(n+2,vector<int> (2));
      vector<bool> visited(n+2);
      for(int i=0;i<n+2;i++){
        int x,y;
        cin >> x >> y;
        position[i][0] = x;
        position[i][1] = y;
      }
      DFS(position[0][0],position[0][1],position,visited);
      if(flag)
        cout << "happy" << endl;
      else
        cout << "sad" << endl;
      position.clear();
      visited.clear();
      flag  = false;
    }
    return 0;
}