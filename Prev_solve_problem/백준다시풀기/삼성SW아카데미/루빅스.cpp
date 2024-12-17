#include <bits/stdc++.h>
using namespace std;

enum color {White, Yellow, Red, Orange, Green, Blue};

void Set_qube(color qube[][3][3]){
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			qube[0][i][j] = White;
			qube[2][i][j] = Yellow;
			qube[i][0][j] = Orange;
			qube[i][2][j] = Red;
			qube[i][j][0] = Green;
			qube[i][j][2] = Blue;
		}
	}
}
void Qube_rota(color *qube[3][3], int rota){
	color temp[3][3];
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			if(rota==1)
				temp[i][j] = *qube[j][3-1-i];
			else
				temp[i][j] = *qube[3-1-j][i]; 
		}
	}
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			*qube[i][j] = temp[i][j];
		}
	}
}
char change(int v){
	switch(v){
		case 0:
			return 'w';
		case 1:
			return 'y';
		case 2:
			return 'r';
		case 3:
			return 'o';
		case 4:
			return 'g';
		case 5:
			return 'b';
	}
	return 'A';
}

void Qube(){
	color qube[3][3][3];
	Set_qube(qube);
	color *target[3][3];
	int rota;
	cin >> rota;
	for(int i=0;i<rota;i++){
		char pos, ons;
		cin >> pos >> ons;
		for(int j=0;j<3;j++)
			for(int k=0;k<3;k++)
				switch(pos){
					case 'U':
						target[j][k] = &qube[0][j][k];	
					break;
					case 'D':
						target[j][k] = &qube[2][j][k];	
					break;
					case 'F':
						target[j][k] = &qube[j][2][k];	
					break;
					case 'B':
						target[j][k] = &qube[j][0][k];	
					break;
					case 'L':
						target[j][k] = &qube[j][k][0];	
					break;
					case 'R':
						target[j][k] = &qube[j][k][2];	
					break;
				}
		if(ons=='+')
			Qube_rota(target,1);
		else
			Qube_rota(target,-1);
	}
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			cout << change(qube[0][i][j]);
		}
		cout << '\n';
	}
}

void solution(){
	int T;
	cin >> T;
	while(T--)
		Qube();

}

int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	solution();
    return 0;
}