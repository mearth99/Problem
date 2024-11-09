#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <string>
using namespace std;

vector<int> outputs;
vector<int> DP;

int main(int argc, char** argv)
{
	int test_case,T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case){
		int N,output=0;
		cin >> N;
		DP.push_back(-1);
		for(int i=0,c=0;i<N;i++){
			cin >> c;
			if(DP.back()<c){
				DP.push_back(c);
			}else{
				auto idx = lower_bound(DP.begin(),DP.end(),c);
				*idx = c;
			}
		}
		outputs.push_back(N-DP.size()+1);
		DP.clear();
	}
	int a = 1;
	for(auto &it : outputs){
		cout << '#' << a++ << ' ' << it << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}