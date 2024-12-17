#include <bits/stdc++.h>
using namespace std;

bool cmp(const pair<string,int>& a, const pair<string,int>& b) {
	if (a.second == b.second){
		if(a.first.length() == b.first.length()){
			return a.first < b.first;
		}
		return a.first.length() > b.first.length();
	}
	return a.second > b.second;
}

void solution(){
	int N,M;
	cin >> N >> M;
	unordered_map<string, int> maps;
	for(int i=0;i<N;i++){
		string target;
		cin >> target;
		if(target.length() >= M){
			maps[target] = maps[target]+1;
		}
	}

	vector<pair<string,int>> arr(maps.begin(), maps.end());
	sort(arr.begin(),arr.end(),cmp);
	for(auto it : arr){
		cout << it.first << '\n';
	}
}

int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	solution();
    return 0;
}