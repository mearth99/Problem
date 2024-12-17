#include <bits/stdc++.h>
using namespace std;
vector<vector<char>> arr;
int output = 9999;
int dx[4] = {0,0,1,-1};  
int dy[4] = {-1,1,0,0}; //상하좌우  

void DFS(int cur, pair<int,int> red, pair<int,int> blue, pair<int,int> dest){
    //현재 위치에서 4가지의 방향으로 전환할 수 있다.    
    for(int i=0;i<4;i++){
        pair<int,int> cur_red = red;
        pair<int,int> cur_blue = blue;
        bool red_moved = true;
        bool blue_moved = true;
        //둘 다 움직이지 않으면 종료!
        do
        {
            //빨간색 움직이기
            
        } while (red_moved || blue_moved);
        
    }
}

int main(){
    int N,M;
    pair<int,int> red, blue, dest;
    cin >> N >> M;
    arr.resize(N, vector<char>(M));
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin >> arr[i][j];
            if(arr[i][j]=='R'){
                red.first = i;
                red.second = j;
            }else if(arr[i][j]=='B'){
                blue.first = i;
                blue.second = j;
            }else if(arr[i][j]=='O'){
                dest.first = i;
                dest.second = j;
            }
        }
    }

    return 0;
}