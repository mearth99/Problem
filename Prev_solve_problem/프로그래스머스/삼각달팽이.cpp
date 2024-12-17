#include <string>
#include <vector>
#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int triangle[1001][1001] = {0};
    int dx[3] = {0,1,-1}; //0 -> 아래가기 1 -> 오른쪽으로 가기 2 -> 위 왼쪽가기 
    int dy[3] = {1,0,-1};
    
    int v = 1;
    int x = 0;
    int y = 0;
    int next = 0;
    //무한 반복을 통해 아래, 오른쪽, 위 왼쪽을 계속 반복하여 0인 숫자를 다 매꿔버린다.
    while(true){
        triangle[y][x] = v++;
        int nx = x + dx[next];
        int ny = y + dy[next];
        if(nx == n || ny == n || nx == -1 || ny == -1 || triangle[ny][nx] != 0){
            next = (next + 1 )  % 3;
            nx = x + dx[next];
            ny = y + dy[next];
            if(nx == n || ny == n || nx == -1 || ny == -1 || triangle[ny][nx] != 0) break;
        }
        x = nx;
        y = ny;
    }
    int index=0;
    vector<int> answer;
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            answer.push_back(triangle[i][j]);
        }
    }
}