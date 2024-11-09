#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<vector<int>> arr;

int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};
struct robot{
	int y,x,d,cnt;
};

int outcnt = 0;
// ofstream file("output.txt");
// void outfile(vector<vector<int>> arr, robot r){
// 	if(file.is_open()){
// 		file << "----------------------------- " << outcnt++ << " 단계-----------------------------\n\n";
// 		for(int i=0; i<arr.size();i++){
// 			for(int j=0;j<arr[i].size();j++){
// 				file << arr[i][j] << ' ';
// 			}
// 			file << '\n';
// 		}
// 		file << r.y  <<' '<< r.x <<' '<< r.d << '\n';
// 	}else{
// 		cout << "파일 에러.";
// 		return;
// 	}
// }

void solution(){
	cin >> N >> M;
	robot r;
	cin >> r.y >> r.x >> r.d;
	r.cnt = 0;
	arr.resize(N,vector<int>(M));
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++)
			cin >> arr[i][j];
	}
	while(1){
		bool clean = true;
		// outfile(arr, r);
		if(arr[r.y][r.x]==0){
			arr[r.y][r.x] = -1; //1. 현재칸을 청소한다.
			r.cnt++;
		}
		for(int i=0;i<4;i++){ //2. 3. 을 확인한다. (주변 4칸)
			int nx = r.x + dx[i];
			int ny = r.y + dy[i];
			if(nx>=0 && ny >=0 && ny<N && nx<M && arr[ny][nx] == 0){
				clean = false;
			}
		}
		if(clean){ //2.의 조건을 만족한 경우
			int nx;
			int ny;
			switch(r.d){
				case 0:
					nx = r.x + dx[2];
					ny = r.y + dy[2];
					break;
				case 1:
					nx = r.x + dx[3];
					ny = r.y + dy[3];
					break;
				case 2:
					nx = r.x + dx[0];
					ny = r.y + dy[0];
					break;
				case 3:
					nx = r.x + dx[1];
					ny = r.y + dy[1];
					break;
			}
			if(nx>=0 && ny>=0 && ny<N && nx<M && arr[ny][nx]!=1){
				r.x = nx;
				r.y = ny;
				continue;
			}else{
				cout << r.cnt;
				break;
			}
		}else{
			r.d-=1;
			if(r.d<0) r.d = 3;
			int nx = r.x + dx[r.d];
			int ny = r.y + dy[r.d];
			if(nx>=0 && ny>=0 && ny<N && nx<M && arr[ny][nx]==0){
				r.x = nx;
				r.y = ny;
			}
		}
	}
}

int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	solution();
	// file.clear();
    return 0;
}

