#include <bits/stdc++.h>
using namespace std;


int dice[3][3];
int dy[5] = {0,0,0,-1,1};
int dx[5] = {0,1,-1,0,0};

void move_y(int reverse){
	int temp = 0;
	if(reverse == 0){
		//북쪽
		temp = dice[0][1];
		dice[0][1] = dice[1][1];
		dice[1][1] = dice[2][1];
		dice[2][1] = dice[2][0];
		dice[2][0] = temp; 
	}else{
		//남쪽
		temp = dice[2][1];
		dice[2][1] = dice[1][1];
		dice[1][1] = dice[0][1];
		dice[0][1] = dice[2][0];
		dice[2][0] = temp;
	}
}
void move_x(int reverse){
	int temp = 0;
	if(reverse == 0){
		//동쪽
		temp = dice[1][2];
		dice[1][2] = dice[1][1];
		dice[1][1] = dice[1][0];
		dice[1][0] = dice[2][0];
		dice[2][0] = temp;
	}else{
		//서쪽
		temp = dice[1][0];
		dice[1][0] = dice[1][1];
		dice[1][1] = dice[1][2];
		dice[1][2] = dice[2][0];
		dice[2][0] = temp;
	}
}


void solution(){
	int N,M,x,y,K;
	cin >> N >> M >> x >> y >> K;
	pair<int,int> di = {x,y};
	vector<vector<int>> arr(N, vector<int>(M));
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			cin >> arr[i][j];
		}
	}
	for(int i=0;i<K;i++){
		int cmd;
		cin >> cmd;
		if(di.first + dy[cmd]>=N || di.first + dy[cmd] <0 || di.second + dx[cmd] >= M || di.second + dx[cmd] < 0) continue;
		di.first += dy[cmd];
		di.second += dx[cmd];
		switch(cmd){
			case 1: //동
				move_x(0);
				break;
			case 2: //서
				move_x(1);
				break;
			case 3: //북
				move_y(0);
				break;
			case 4: //남
				move_y(1);
				break;
		}
		if(arr[di.first][di.second]==0) arr[di.first][di.second] = dice[2][0];
		else {
			dice[2][0] = arr[di.first][di.second];
			arr[di.first][di.second] = 0;
		}
		cout << dice[1][1] << endl;
	}
}

int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	solution();
    return 0;
}