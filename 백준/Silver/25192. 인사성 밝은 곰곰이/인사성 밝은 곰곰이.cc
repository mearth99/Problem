#include <bits/stdc++.h>
using namespace std;



void solution(){
	int N,count=0;
	cin >> N;
	set<string> maps;
	for(int i=0;i<N;i++){
		string temp;
		cin >> temp;
		if(temp.compare("ENTER")==0){
			count += maps.size();
			maps.clear();
		}
		else{
			maps.insert(temp);
		}
	}
	cout << count + maps.size();
}

int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	solution();
    return 0;
}