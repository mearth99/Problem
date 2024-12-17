#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <string>
using namespace std;

int main(int argc, char** argv)
{
	freopen("/mnt/c/Users/dlwls/Downloads/input.txt", "r", stdin);
	freopen("/mnt/c/Users/dlwls/Downloads/myoutput.txt", "w", stdout);
	int test_case,T;
	T=10;

	for(test_case = 1; test_case <= T; ++test_case){
		int dump_cnt;
		cin >> dump_cnt;
		vector<int> arr(100);
		priority_queue<int> downq;
		priority_queue<int, vector<int>, greater<int>> upq;
		for(int i=0;i<100;i++){
			cin >> arr[i];
			downq.push(arr[i]);
			upq.push(arr[i]);
		}
		while(1){
			int d = downq.top(); downq.pop();
			int u = upq.top(); upq.pop();
			downq.push(d-1);
			upq.push(u+1);
			dump_cnt--;
			if(d-u == 0 || d-u == 1 || dump_cnt==0) break;
		}
		cout << '#' << test_case << ' ' << downq.top() - upq.top() << '\n';
		arr.clear();
	}

	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}