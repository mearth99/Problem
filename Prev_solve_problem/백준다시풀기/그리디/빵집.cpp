#include <bits/stdc++.h>
using namespace std;

char arr[10001][501];
int R,C,cnt=0;

ofstream file("output.txt");
void outfile(char arr[10001][501]){
	if(file.is_open()){
		for(int i=0;i<R;i++){
			for(int j=0;j<C;j++)
				file <<  arr[i][j] << ' ' ;
			file << endl;
		}
	}else{
		cout << "파일 에러.";
		return;
	}
}


void Go(int y,int x){
	while(x<C-1){
		if(y-1>=0 && arr[y-1][x+1]!='x'){
			//오른쪽 위로 이동할 수 있을 때.
			arr[y][x] = 'x';
			y-=1;
			x+=1;
		}
		else if(arr[y][x+1]!='x'){
			//오른쪽으로 이동할 수 있을 때
			arr[y][x] = 'x';
			x+=1;
		}
		else if(y+1<R && arr[y+1][x+1]!='x'){
			arr[y][x] = 'x';
			x+=1;
			y+=1;
		}
		else{
			
			break;
		}
		
	}
	if(x==C-1)
		cnt++;
}

void solution(){
	
	cin >> R >> C;
	for(int i=0;i<R;i++){
		for(int j=0;j<C;j++){
			cin >> arr[i][j];
		}
	}
	for(int i=0;i<R;i++){
		Go(i,0);	
	}
	cout << cnt;
	outfile(arr);
}

int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	solution();
	file.clear();
    return 0;
}

