#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <string>
#include <map>
using namespace std;

vector<int> outputs;

int main(int argc, char** argv)
{
	freopen("input.txt", "r", stdin);
	freopen("myoutput.txt", "w", stdout);
	int test_case,T;
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case){
		int N,K,word_size;
		cin >> N >> K;
		word_size = N/4;
		map<string,int> arr;
		for(int i=0;i<3;i++){
			//변3개를 회전하면서 총 3번 다른 값이 나타난다.
			for(int j=0;j)
		}
	}	
	int a = 1;
	for(auto &it : outputs){
		cout << '#' << a++ << ' ' << it << '\n';
	}

	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}