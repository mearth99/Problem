#include <bits/stdc++.h>
using namespace std;
int Get_idx(int *idx){
	if(*idx>7) *idx -=8;
	if(*idx<0) *idx += 8;
	return *idx;
}

void solution(){
	int gear[4][8];
	int idx[4] = {0};
	int rota[4];
	int N;
	for(int i=0;i<4;i++){
		for(int j=0;j<8;j++)
			cin >> gear[i][j];
	}
	cin >> N;
	queue<pair<int,int>> q;
	for(int i=0;i<N;i++){
		int number, rotation;
		cin >> number >> rotation;
		q.push({number,rotation});
	}
	while(!q.empty()){
		pair<int,int> cur = q.front(); q.pop();
		for(int i=1;i<=3;i++){
			if(gear[i][Get_idx(&idx[i]+2)] == gear[i+1][Get_idx(&idx[i+1]+6)])
				rota[i] = 1;
			else
				rota[i] = 0;
		}
		queue<pair<int,int>> t;
		int visited[4] = {0};
		t.push(cur);
		while(!t.empty()){
			pair<int,int> cur_t = t.front(); t.pop();
			switch (cur_t.first)
			{
			case 0:
				if(rota[1]){

				}
				break;
			
			default:
				break;
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