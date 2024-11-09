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

struct codes{
  int x;
  int y;
  int count;
}; 
codes make_codes(int y, int x , int count){
  codes re_code;
  re_code.count = count;
  re_code.x = x;
  re_code.y = y;
  return re_code;
}
queue<codes> q;
int dx[8]= {1,2,2,1,-1,-2,-2,-1};
int dy[8]= {2,1,-1,-2,-2,-1,1,2};

int BFS(){
    int length, start_x, start_y, end_x, end_y,minvalue = 999999;
    cin >> length;
    cin >> start_x >> start_y;
    cin >> end_x >> end_y;
    vector<vector<bool>> chess(length,vector<bool>(length));
    q.push(make_codes(start_y,start_x,0));
    chess[start_y][start_x] = true;
    while(!q.empty()){
        codes target = q.front();
        q.pop();
        if(target.y==end_y && target.x == end_x)
            minvalue = min(minvalue, target.count);
        else{
            for(int i=0;i<8;i++){
                int nx = target.x + dx[i];
                int ny = target.y + dy[i];
                if(nx>=0 && nx<length && ny>=0 && ny<length && !chess[ny][nx]){
                    q.push(make_codes(ny,nx,target.count+1));
                    chess[ny][nx] = true;
                }
                    
            }
        }
    }
    chess.clear();
    return minvalue;
}


int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t>0){
        cout << BFS() << '\n';
        t--;
    }
    return 0;
}