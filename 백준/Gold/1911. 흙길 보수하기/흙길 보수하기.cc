#include <bits/stdc++.h>
using namespace std;
// ofstream file("output.txt");
// void outfile(char arr[10001][501]){
// 	if(file.is_open()){
// 		for(int i=0;i<R;i++){
// 			for(int j=0;j<C;j++)
// 				file <<  arr[i][j] << ' ' ;
// 			file << endl;
// 		}
// 	}else{
// 		cout << "파일 에러.";
// 		return;
// 	}
// }




/*
1.	
*/

void solution(){
	int N, L,ans=0,prev=-1;
	cin >> N >> L;
	vector<pair<int,int>> arr(N);
	for(int i;i<N;i++){
		cin >> arr[i].first >> arr[i].second;
	}
	sort(arr.begin(),arr.end());
	for(auto it : arr){
		prev = it.first < prev ? prev : it.first;
		int gap = it.second - prev;
		int tiles = (gap + L -1) / L;
		ans += tiles;
		prev += (tiles*L);
	}
	cout << ans;
	return;
	
}

int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	solution();
	// file.clear();
    return 0;
}

