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
#define INF 2000000
using namespace std;
vector<int> space(200001,INF);
int main(){
  int N,K,minv = INF;
  cin >> N >> K;
  queue<pair<int,int>> q;
  q.push({N,0});
  space[N] = 0;
  while(!q.empty()){
    int current = q.front().first;
    int times = q.front().second;
    q.pop();
    if(current==K){
      minv = min(minv, times);
      continue;
    }
    if(current<K && times<space[current+1]){
      q.push({current+1,times+1});
      space[current+1] = times+1;
    }
    if(current>0 && times<space[current-1]){
      q.push({current-1,times+1});
      space[current-1] = times+1;
    }
    if(current<100001 && times<space[current*2]){
      q.push({current*2,times});
      space[current*2] = times;
    }
  }
  cout << minv;
}