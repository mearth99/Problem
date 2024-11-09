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

int N,K;
vector<pair<int,int>> arr;
vector<int> bag;

bool cmp(pair<int,int> p1, pair<int,int> p2){
	if(p1.first == p2.first) 
		return p1.second > p2.second;
	else 
		return p1.first > p2.first;
}

void solution(){
	long long int price=0;
	cin >> N >> K;
	arr.resize(N);
	bag.resize(K);
	priority_queue<int, vector<int>, greater<int>> q;
	for(int i=0;i<N;i++){
		cin >> arr[i].first >> arr[i].second;
	}
	for(int j=0;j<K;j++){
		cin >> bag[j];
	}
	sort(arr.begin(),arr.end(),cmp);
	sort(bag.begin(),bag.end(), greater<int>());
	int idx = 0,jdx=0;
	for(idx=0;idx<N;idx++){
		if(arr[idx].first > bag[jdx]){
			if(!q.empty() && arr[idx].second > q.top() ){
				price= price - q.top() + arr[idx].second;
				q.pop();
				q.push(arr[idx].second);
		}
		}
		else{
			q.push(arr[idx].second);
			price+=arr[idx].second;
			jdx++;
		}
	}

	cout << price;
	return;
}

int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	solution();
	// file.clear();
    return 0;
}

