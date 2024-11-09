#include <bits/stdc++.h>

using namespace std;

int main(){
	string s;
	bool wordf = false;
	getline(cin, s);
	int cnt = 0;
	//1. 공백 확인하기
	for(auto it : s){
		if(it == ' ' && wordf){ //현재가 공백이고 이전에 단어가 나왔다는 뜻이므로 증가시킨다.
			cnt++;
			wordf = false;
		}else if(it != ' '){
			wordf = true;
		}
	}
	if(s.back()!=' ' && wordf) cnt++;
	cout << cnt;
	return 0;
}