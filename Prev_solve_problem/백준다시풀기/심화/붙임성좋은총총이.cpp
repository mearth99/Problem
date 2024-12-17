#include <bits/stdc++.h>
using namespace std;




void solution(){
	unordered_map<string, int> maps;
	int N,counts=1;
	cin >> N;
	for(int i=0;i<N;i++){
		string A,B;
		cin >> A >> B;
		if(A=="ChongChong"){
			maps.insert({B,1});
		}else if(maps[A]==1 && maps[B]!=1){
			counts++;
		}
		else if(B=="ChongChong"){
			maps.insert({A,1});
		}else if(maps[B]==1 && maps[A]!=1){
			counts++;
		}
	}
	cout << counts;
}

int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	solution();
    return 0;
}