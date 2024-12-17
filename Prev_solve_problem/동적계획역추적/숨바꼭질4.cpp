/*
입력
첫 번째 줄에 수빈이가 있는 위치 N과 동생이 있는 위치 K가 주어진다. N과 K는 정수이다.

출력
수빈이가 동생을 찾는 가장 빠른 시간을 출력한다.
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
struct seek{
    int cur;
    int cost;
};
int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n,k,times = 9999999;
    bool visited[100001] = {false};
    int course[100001] = {0};
    queue<seek> q;
    cin >> n >> k;
    q.push({n,0});
    visited[n] = true;
    while(!q.empty()){
      int cur = q.front().cur;
      int cost = q.front().cost;
      
      q.pop();
      if(cur==k){
        times = min(times,cost);
        break;
      }
      else{
        if(cur-1>=0 && !visited[cur-1]){
          q.push({cur-1,cost+1});
          course[cur-1] = cur;  
          visited[cur-1] = true;
        }
        if(cur+1<=k && !visited[cur+1]){
          q.push({cur+1,cost+1});
          course[cur+1] = cur;
          visited[cur+1] = true;
        }
        if(cur*2<100001 && !visited[cur*2])
          q.push({cur*2,cost+1});
          course[cur*2] = cur;
          visited[cur*2] = true;
      }
    }
    cout << times << '\n';
    return 0;
}