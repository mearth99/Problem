#include <bits/stdc++.h>
using namespace std;

char arr[10001][501];
int R,C,cnt=0;

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

bool cmp(pair<int,int> p1, pair<int,int> p2){
	if(p1.first == p2.first) return p1.second < p2.second;
	return p1.first > p2.first;
}


/*
1.	
*/

void solution(){
	int N;
	cin >> N;
	vector<pair<int,int>> arr(N);
	for(int i=0;i<N;i++){
		cin >> arr[i].first >> arr[i].second; 
	}
	sort(arr.begin(),arr.end(),cmp);
	int idx = -1;
	int cost = 0;
	for(int i=0,times=0;i<N;i++){
		if(times < arr[i].first){
			cost += arr[i].second;
			times++;
			
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

