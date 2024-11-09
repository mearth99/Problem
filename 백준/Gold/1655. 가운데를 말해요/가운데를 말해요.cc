#include <bits/stdc++.h>
using namespace std;

// ofstream file("output.txt");
// void outfile(){
// 	if(file.is_open()){

// 	}else{
// 		cout << "파일 에러.";
// 		return;
// 	}
// }


void solution(){
	priority_queue<int> downq;
	priority_queue<int, vector<int>, greater<int>> upq;


	int N;
	cin >> N;
	for(int i=1;i<=N;i++){
		int input;
		cin >> input;
		if(downq.size() == upq.size()){
			downq.push(input);
		}else{
			upq.push(input);
		}
		if(!downq.empty() && !upq.empty() && downq.top() > upq.top()){
			int v1=downq.top(),v2=upq.top();
			downq.pop(); upq.pop();
			downq.push(v2); upq.push(v1);
		}
		cout << downq.top() << '\n';
	}
}

int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	solution();
	// file.clear();
    return 0;
}

