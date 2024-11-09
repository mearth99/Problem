/*
입력
첫째 줄에는 컴퓨터의 수가 주어진다. 컴퓨터의 수는 100 이하인 양의 정수이고 각 컴퓨터에는 1번 부터 차례대로 번호가 매겨진다. 둘째 줄에는 네트워크 상에서 직접 연결되어 있는 컴퓨터 쌍의 수가 주어진다. 이어서 그 수만큼 한 줄에 한 쌍씩 네트워크 상에서 직접 연결되어 있는 컴퓨터의 번호 쌍이 주어진다.

출력
1번 컴퓨터가 웜 바이러스에 걸렸을 때, 1번 컴퓨터를 통해 웜 바이러스에 걸리게 되는 컴퓨터의 수를 첫째 줄에 출력한다.
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n,m,answer=0;
    cin >> n >> m;
    vector<vector<int>> computer(n+1,vector<int>(n+1));
    vector<bool> visited(n+1);
    visited[1] = true;
    queue<int> q;
    for(int i=0;i<m;i++){
      int from, to;
      cin >> from >> to;
      computer[from][to] = 1;
      computer[to][from] = 1;
    }
    q.push(1);
    while(!q.empty()){
      int target = q.front();
      q.pop();
      for(int i=1;i<=n;i++){
        if(computer[target][i]==1 && !visited[i]){
          q.push(i);
          visited[i] = true;
          answer++;
        }
      }
    }
    cout << answer;
    return 0;
}