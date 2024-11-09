/*
입력
입력의 첫째 줄에는 테스트 케이스의 개수가 주어진다.

각 테스트 케이스는 세 줄로 이루어져 있다. 첫째 줄에는 체스판의 한 변의 길이 l(4 ≤ l ≤ 300)이 주어진다. 
체스판의 크기는 l × l이다. 체스판의 각 칸은 두 수의 쌍 {0, ..., l-1} × {0, ..., l-1}로 나타낼 수 있다.
둘째 줄과 셋째 줄에는 나이트가 현재 있는 칸, 나이트가 이동하려고 하는 칸이 주어진다.

출력
각 테스트 케이스마다 나이트가 최소 몇 번만에 이동할 수 있는지 출력한다.
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int field[101]={0};
int main()
{
    queue<pair<int,int>> q;
    ios::sync_with_stdio(0); cin.tie(0);
    int ladder, snake,maxvalue = 999999;
    cin >> ladder >> snake;
    for(int i=0;i<ladder+snake;i++){
      int position, cost;
      cin >> position >> cost;
      field[position] = cost;
    } 
    q.push(make_pair(1,0));
    while(!q.empty()){
      int position = q.front().first;
      int trys = q.front().second;
      q.pop();

      for(int i=1;i<=6;i++){
        int next_p = position + i;
        if(next_p==100){
          cout << trys+1;
          return 0;
        }
        else if(next_p<100){
          while(field[next_p]>0)
            next_p = field[next_p];
          
          if(field[next_p]==0){
            q.push(make_pair(next_p,trys+1));
            field[next_p] = -1;
          }
        }
      }
    }
    cout << maxvalue;
    return 0;
}