#include <bits/stdc++.h>
using namespace std;

/*
	요약. 정렬한 arr ->
	1. arr[i].first >= arr[i].second;
	2. arr[i].first <= arr[i+1].first;
	3. second가 동일한 경우 -> second가 동일하지 않고 먼저 사용한 arr의 first보다는 커야함
*/

// ofstream file("output.txt");
// void outfile(vector<pair<int,int>> arr){
// 	if(file.is_open()){
// 		for(int i=0;i<arr.size();i++){
			
// 			file << '<' << ' ' << arr[i].first << ' ' << arr[i].second << ' ' << endl;
// 		}
// 	}else{
// 		cout << "파일 에러.";
// 		return;
// 	}
// }

bool cmp(pair<int,int> p1, pair<int,int> p2){
	if(p1.second != p2.second)
		return p1.second < p2.second;
	else
		return p1.first < p2.first;
}

void solution(){
	int N,now=0;
	pair<int,int> prev;
	long long int cnt = 0;
	cin >> N;
	vector<pair<int,int>> arr(N,{0,0});
	for(int i=0;i<N;i++){
		cin >> arr[i].first;
	}
	for(int i=0;i<N;i++){
		cin >> arr[i].second;
	}
	sort(arr.begin(),arr.end(),cmp);
	prev = arr[0];
	arr.push_back({INT32_MAX,INT32_MAX});
	for(int i=0;i<=N;i++){
		int maxv = max(prev.first , arr[i].second);
		if(arr[i].first < maxv){
			int gap = (maxv-arr[i].first+29)/30;
			arr[i].first += gap * 30;
			cnt += gap;
		}
		now = max(now, arr[i].first);
		if(arr[i].second!=arr[i+1].second){
			prev = {now,arr[i].second};
			now = 0;
		}

	}
	cout << cnt;
}

int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	solution();
	// file.clear();
    return 0;
}

