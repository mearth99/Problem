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

int main()
{
    int n,k,times = 9999999;
    bool visited[200002] = {false};
    ios::sync_with_stdio(0); cin.tie(0);
    queue<pair<int,int>> q;
    cin >> n >> k;
    q.push(make_pair(n,0));
    while(!q.empty()){
      pair<int,int> target = q.front();
      q.pop();
      visited[target.first] = true;
      if(target.first==k) times = min(times, target.second);
      else{
        if(target.first+1<=k && !visited[target.first+1])
          q.push(make_pair(target.first+1,target.second+1));
        if(target.first-1>=0 && !visited[target.first-1])
          q.push(make_pair(target.first-1,target.second+1));
        if(target.first*2<200002 && !visited[target.first*2])
          q.push(make_pair(target.first*2,target.second+1));
      }
    }
    cout << times;
    return 0;
}