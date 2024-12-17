
#include <bits/stdc++.h>
using namespace std;

int figure[4][4] = {0};
void rotation(){
	int temp[4][4] = {0};
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			temp[i][j] = figure[4-j-1][i];
		}
	}
	while(temp[0][0]!=1){
		for(int i=0;i<4;i++){
			for(int j=0;j<3;j++){
				temp[i][j] = temp[i][j+1];
				temp[i][j+1] = 0;
			}
		}
	}
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			figure[i][j] = temp[i][j];
		}
	}
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int C, P;
	cin >> C >> P;
	switch (P)
	{
	case 1:
		figure[0][0] = figure[0][1] = figure[0][2] = figure[0][3] = 1; 
		break;
	case 2:
		figure[0][0] = figure[0][1] = figure[1][0] = figure[1][1] = 1;
		break;
	case 3:
		figure[0][0] = figure[0][1] = figure[1][1] = figure[1][2] = 1;
		break;
	case 4:
		figure[1][0] = figure[0][1] = figure[1][1] = figure[0][2] = 1;
		break;
	case 5:
		figure[0][0] = figure[0][1] = figure[1][1] = figure[0][2] = 1;
		break;
	case 6:
		figure[0][0] = figure[0][1] = figure[0][2] = figure[1][2] = 1;
		break;
	case 7:
		figure[0][0] = figure[1][0] = figure[0][1] = figure[0][2] = 1;
		break;
	}
	int arr[200][101] = {0};
	// for(int i=0;i<C;i++){
	// 	int height;
	// 	cin >> height;
	// 	for(int j=0;j<height;j++){
	// 		arr[i][j] = 1;
	// 	}
	// }
	rotation();
	for(int i=3;i>=0;i--){
		for(int j=0;j<4;j++){
			if(figure[i][j]==0)
				cout << "0 ";
			else
				cout << "1 ";
		}
		cout << endl;
	}


	return 0;
}