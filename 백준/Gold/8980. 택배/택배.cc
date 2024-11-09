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

struct present{
	int from;
	int to;
	int cnt;
};

bool cmp(present &p1, present &p2){
	if(p1.to == p2.to) return p1.from < p2.from;
	return p1.to < p2.to;
}


/*
1.	
*/

void solution(){
	int N, C, M;
	int cur_M = 0, cnt=0;
	cin >> N >> C >> M;
	vector<present> arr(M);
	for(int i=0;i<M;i++){
		cin >> arr[i].from >> arr[i].to >> arr[i].cnt;
	}
	sort(arr.begin(), arr.end(), cmp);
	queue<pair<int,int>> q; //to, cnt
	for(int i=0;i<M;i++){
		while(!q.empty() && q.front().first <= arr[i].from){
			cur_M -= q.front().second;
			q.pop();
		}
		if(cur_M + arr[i].cnt <= C){
			cur_M += arr[i].cnt;
			cnt += arr[i].cnt;
			q.push({arr[i].to, arr[i].cnt});
		}else if(cur_M + arr[i].cnt > C && cur_M < C){
			cnt += C-cur_M;
			q.push({arr[i].to, C-cur_M});
			cur_M = C;
		}
	}
	cout << cnt;
	return;
	
}

int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	solution();
	// file.clear();
    return 0;
}

