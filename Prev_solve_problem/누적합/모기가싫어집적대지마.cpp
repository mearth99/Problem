
/*
입력
첫째 줄에 지동이의 방에 출입한 모기의 마릿수 N(1 ≤ N ≤ 1,000,000)가 주어진다.
다음 N개의 줄에 모기의 입장 시각 TE과 퇴장 시각 TX이 주어진다. (0 ≤ TE < TX ≤ 2,100,000,000)
모기는 [TE, Tx)동안 존재한다.

출력
첫째 줄에 지동이 방에 모기가 가장 많이 있는 시간대의 모기 마릿수를 출력한다.
지동이 방에 모기가 가장 많이 있는 시간대의 연속 구간 전체를 [TEm, TXm)이라고 할 때,
둘째 줄에 TEm, TXm을 공백으로 구분하여 출력한다. 단, 여러 가지 방법이 있으면 가장 빠른 시작 시각을 기준으로 출력한다.
*/
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int main()
{
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  map<int,int> count;
  int n,te,tx,pre=0;
  cin >> n;
  for(int i=0;i<n;i++){
      cin >> te >> tx;
      count[te]++;
      count[tx]--;
  }
  for(auto &idx: count){
    idx.second+=pre;
    pre = idx.second;
  }
  auto start = *max_element(count.begin(),count.end(),[](const auto &x, const auto &y) {
                    return x.second < y.second;
                });
  for(auto idx: count){
    if(idx.first>start.first&&idx.second!=start.second){
      cout << start.second<<'\n'<<start.first << ' ' << idx.first;
      break;
    }
  }
  return 0;
}