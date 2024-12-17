#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <string>
using namespace std;

vector<int> outputs;

int main(int argc, char** argv)
{
	freopen("input.txt", "r", stdin);
	freopen("myoutput.txt", "w", stdout);
	int test_case,T;
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case){
		int N,K,minv=1e9;
		cin >> N >> K;
		vector<int> arr(N);
		for(int i=0;i<N;i++)
			cin >> arr[i];
		sort(arr.begin(),arr.end(),greater<>());
		for(int i=0;i+K-1<N;i++){
			minv = min(minv, arr[i]-arr[i+K-1]);
		}
		outputs.push_back(minv);
	}
	int a = 1;
	for(auto &it : outputs){
		cout << '#' << a++ << ' ' << it << '\n';
	}

	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}