#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;
vector<vector<vector<int>>> pulzzes;
vector<vector<vector<int>>> gameboard;
queue<pair<int,int>> making;
int dx[] = {0,0,-1,1};
int dy[] = {1,-1,0,0};
void remove_y(vector<vector<int>> &pulzze){//세로줄을 하나 옆으로 당긴다. |
    for(int i=0;i<pulzze.size();i++){
        for(int j=1;j<pulzze.size();j++)
            pulzze[i][j-1] = pulzze[i][j];
        pulzze[i][pulzze.size()-1] = 0;
    }  
}
void remove_x(vector<vector<int>> &pulzze){//가로줄을 하나 위로 당긴다. -
    for(int i=1;i<pulzze.size();i++){
        for(int j=0;j<pulzze.size();j++)
            pulzze[i-1][j] = pulzze[i][j];
        }
    for(int i=0;i<pulzze.size();i++)
        pulzze[pulzze.size()-1][i] = 0;
}

void turn(vector<vector<int>>& pulzze){
    vector<vector<int>> temp(pulzze.size(),vector<int>(pulzze.size()));
    copy(pulzze.begin(),pulzze.end(),temp.begin());
    for(int i=0; i<temp.size(); i++)
        for(int j=0; j<temp.size(); j++)
            pulzze[i][j] = temp[temp.size() - j -1][i];
}
    
void turn_remove(vector<vector<int>>& pulzze){
    while(true){
        bool fx = false;
        bool fy = false;
        for(int i=0;i<pulzze.size();i++){
            if(pulzze[i][0]) fy = true;
            if(pulzze[0][i]) fx = true;  
        }
        if(fy&&fx) break;
        if(!fx) remove_x(pulzze);
        if(!fy) remove_y(pulzze);
    }
}
void makepulzze(vector<vector<int>> &table,vector<vector<int>> pulzze,int mode){
    //mode = 0 : game, mode = 1 : pulzze
    while(!making.empty()){
        int y = making.front().first;
        int x = making.front().second;
        making.pop();
        if(mode==1){
            table[y][x] = 0;
            pulzze[y][x] = 1;
            for(int i=0;i<4;i++){
                int ny = y + dy[i];
                int nx = x + dx[i];
                if(nx>=0&&nx<table.size()&&ny>=0&&ny<table.size()){
                    if(table[ny][nx])
                        making.push(make_pair(ny,nx));
                }
            }
            
        }else{
            table[y][x] = 1;
            pulzze[y][x] = 1;
            for(int i=0;i<4;i++){
                int ny = y + dy[i];
                int nx = x + dx[i];
                if(nx>=0&&nx<table.size()&&ny>=0&&ny<table.size()){
                    if(!table[ny][nx])
                        making.push(make_pair(ny,nx));
                }
            }
        }
    }
    if(mode==1){
        turn_remove(pulzze);
        pulzzes.push_back(pulzze);
    }else{
        turn_remove(pulzze);
        gameboard.push_back(pulzze);
    }
}
pair<bool,int> check(vector<vector<int>> game, vector<vector<int>> pul){

    int count = 0;
    for(int i=0;i<game.size();i++){
        for(int j=0;j<game.size();j++){
            if(game[i][j]) count++;
            if(game[i][j]!=pul[i][j])
                return make_pair(false,count);
        }
    }
    return make_pair(true,count);
}
int solution(vector<vector<int>> game_board, vector<vector<int>> table) {
    int answer = 0;
    for(int i=0;i<table.size();i++){
        for(int j=0;j<table.size();j++){
            if(table[i][j]==1){
                vector<vector<int>> pulzze(table.size(),vector<int>(table.size()));
                making.push(make_pair(i,j));
                makepulzze(table,pulzze,1);
            }
        }
    }
    for(int i=0;i<table.size();i++){
        for(int j=0;j<table.size();j++){
            if(game_board[i][j]==0){
                vector<vector<int>> pulzze(table.size(),vector<int>(table.size()));
                making.push(make_pair(i,j));
                makepulzze(game_board,pulzze,0);
            }
        }
    }
    for(int i=0;i<gameboard.size();i++){
        pair<bool,int> flag;
        for(int j=0;j<pulzzes.size();j++){
            if(pulzzes[j][0][0]==-1) continue;
            for(int k=0;k<4;k++){
                flag = check(gameboard[i],pulzzes[j]);
                if(flag.first){ 
                    pulzzes[j][0][0] = -1;
                    answer+=flag.second;
                    break;
                }else{
                    turn(pulzzes[j]);
                    turn_remove(pulzzes[j]);
                }
            }
            if(flag.first) break;
        }
    }
    return answer;
}