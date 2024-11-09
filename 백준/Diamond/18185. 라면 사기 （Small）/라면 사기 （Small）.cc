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


void solution(){
	int N,cost=0;
	cin >> N;
	vector<int> arr(N+3,0);
	for(int i=1; i<=N;i++){
		cin >> arr[i];
	}
	int i=1;
	while(i<=N){
		if(arr[i+1]>arr[i+2]){
			int target = min(arr[i+1]-arr[i+2],arr[i]);
			cost += target*5;
			arr[i+1]-= target;
			arr[i]-= target;
			target =  min({arr[i],arr[i+1],arr[i+2]});
			cost += target*7;
			arr[i+2]-= target;
			arr[i+1]-= target;
			arr[i]-= target;
		}else{
			int target = min({arr[i],arr[i+1],arr[i+2]});
			cost += target*7;
			arr[i+2]-= target;
			arr[i+1]-= target;
			arr[i]-= target;
			target = min(arr[i+1],arr[i]);
			cost += target*5;
			arr[i+1]-= target;
			arr[i]-= target;
		}
		if(arr[i]>0){
			cost += arr[i]*3;
			arr[i] = 0;
		}
		i++;
	}
	cout << cost;
}

int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	solution();
	// file.clear();
    return 0;
}

