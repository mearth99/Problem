#include <string>
#include <vector>
#include <iostream>

using namespace std;

int check(){
    int answer = 0;
    char room[5][5] = {0};
    int dx[4] = {0,0,-1,1}; // 상 하 좌 우
    int dy[4] = {-1,1,0,0};

    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            cin >> room[i][j];
        }
    }
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            if(room[i][j]!='P')
                continue;
            else{
                for(int k=0;k<4;k++){
                    int nx = j+dx[k];
                    int ny = i+dy[k];
                    if(nx<0 || ny < 0 ||nx > 4 || ny > 4 || room[ny][nx]=='X') 
                        continue;
                    for(int u=0;u<4;u++){
                        int nx2 = nx+dx[k];
                        int ny2 = ny+dy[k];
                        if(nx2<0 || ny2< 0 ||nx2 > 4 || ny2 > 4 || room[ny2][nx2]!='P')
                            continue;
                        else{
                            return 0;
                        }
                    }
                }
            }
        }
    }
    return 1;
}
int main() {
    //1. 대기실은 5개, 각 대기실은 5*5
    //2. 거리두기를 위해 응시자들끼리는 맨해튼거리가 2 이하 ( |r1-r2| + |c1-c2|)
    //3. 응시자가 앉아있는 자리 사이가 파티션으로 막히면 가능.
    // P는 응시자, O는 빈테이블, X는 파티션.
    int answer[5] = {0};
    for(int i=0;i<5;i++){
        answer[i] = check();
        cout << endl;
        cout << answer[i] << endl;
    }
}