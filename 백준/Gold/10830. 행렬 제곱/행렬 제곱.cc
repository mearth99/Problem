#include <bits/stdc++.h>
using namespace std;

// ofstream file("output.txt");
// void outfile(vector<vector<char>> arr){
// 	if(file.is_open()){
// 		for(int i=0;i<N;i++){
// 			for(int j=0;j<M;j++){
// 				file << arr[i][j] << ' ';
// 			}
// 			file << '\n';
// 		}
// 	}else{
// 		cout << "파일 에러.";
// 		return;
// 	}
// }
long long int ans[5][5];
long long int arr[5][5];
long long int temp[5][5];
long long int N, B;
void Muitple(long long int A[5][5], long long int B[5][5]){
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			temp[i][j] = 0;
			for(int k=0;k<N;k++){
				temp[i][j] += A[i][k] * B[k][j];
			}
			temp[i][j] %= 1000;
		}
	}
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			A[i][j] = temp[i][j];
		}
	}
}

void solution(){
	cin >> N >> B;
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cin >> arr[i][j];
			ans[i][i] = 1;
		}
	}
	while(B>0){
		if(B%2==1){
		//홀수
			Muitple(ans,arr);
		}
		Muitple(arr,arr);
		B/=2;
	}
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}
	// outfile(arr);
}

int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	solution();
	// file.clear();
    return 0;
}

