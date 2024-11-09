#include <bits/stdc++.h>
using namespace std;

bool cmp(string p1, string p2){
	return p1.size() > p2.size();
}

bool check(string s){
	for(int i=0,j=s.size()-1;i<=j;i++,j--){
		if(s.at(i)!=s.at(j)) return false;
	}
	return true;
}

int main(){
	int T;
	cin >> T;
	while(T--){
		int K;
		bool paln = false;
		cin >> K;
		vector<string> arr(K);
		for(int i=0;i<K;i++){
			cin >> arr[i];
		}
		sort(arr.begin(),arr.end(),cmp);
		for(int i=0;i<K;i++){
			if(paln) break;
			for(int j=i+1;j<K;j++){
				string front_add = arr[i] + arr[j];
				string back_add = arr[j] + arr[i];
				if(check(front_add)){
					paln = true;
					cout << front_add << endl;	
					break;	
				}else if(check(back_add)){
					paln = true;
					cout << back_add << endl;	
					break;	
				}
			}
		}
		if(!paln) cout << '0' << endl;
		arr.clear();
	}
	

    return 0;
}