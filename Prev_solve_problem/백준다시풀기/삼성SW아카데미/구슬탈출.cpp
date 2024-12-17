#include <bits/stdc++.h>
using namespace std;
vector<vector<char>> arr;
int minv = 11;

int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,-1,1};

int N, M;
int judge(int dir, pair<int,int> p1, pair<int,int> p2){
	if(dir==0 || dir==1){ //상하
		if(p1.second == p2.second){
				if(p1.first < p2.first)
					return 1;
				else
					return -1;
		}
		return 0;
	}
	else{ //좌우
		if(p1.first == p2.first){
				if(p1.second < p2.second)
					return 1;
				else
					return -1;
		}
		return 0;
	}
}

vector<pair<int,int>> moving(int dir, vector<pair<int,int>> uniq){ // O, R, B;
	int flag = 0;
	int check = 0; // check 1 -> red가 먼저 움직임 -1: blue가 먼저 움직임 0: 서로 엇갈림
	vector<pair<int,int>> output(4);
	//상, 하, 좌, 우
	
	if(dir==0){
		//구슬이 위로 굴러간다
		check = judge(dir, uniq[1],uniq[2]);
	}else if(dir==1){
		check = judge(dir, uniq[2],uniq[1]);
	}else if(dir==2){
		check = judge(dir, uniq[1],uniq[2]);
	}else if(dir==3){
		check = judge(dir, uniq[2],uniq[1]);
	}
	if(check==0){
		
	}
	return output;
}



void DFS(int cnt, vector<pair<int,int>> uniq){
	if(cnt >= minv) return;
	for(int i=0;i<4;i++){
		vector<pair<int,int>> seq = moving(i,uniq);
		if(seq[3].first==1){
			//빨간구슬만 구멍을 통해 뺴낼 수 있다면?
			minv = cnt;
			return;
		}else if(seq[3].first==0){
			//빨간구슬은 아직 구멍 X, 파란구슬도 구멍 X
			DFS(cnt+1,seq);
		}else{
			//파란구슬이 구멍에 들어간 경우: 답도없음
			return;
		}
	}
	return;
}

void solution(){
	vector<vector<char>> arr;
	vector<pair<int,int>> uniq(4); // O, R, B;
	cin >> N >> M;
	arr.resize(N,vector<char>(M));
	uniq[4] = {0,0};
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			cin >>  arr[i][j];
			if(arr[i][j]=='O'){
				uniq[0] = {i,j};
				arr[i][j]='.';
			}else if(arr[i][j]=='R'){
				uniq[1] = {i,j};
				arr[i][j]='.';
			}else if(arr[i][j]=='B'){
				uniq[2] = {i,j};
				arr[i][j]='.';
			}
				
		}
	}

}

int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	solution();
    return 0;
}