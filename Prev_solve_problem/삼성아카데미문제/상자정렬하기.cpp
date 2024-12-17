#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <string>
using namespace std;

vector<vector<int>> outputs;

int main(int argc, char** argv)
{
	freopen("input.txt", "r", stdin);
	freopen("myoutput.txt", "w", stdout);
	int test_case,T;
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case){
		int N;
		cin >> N;
		vector<int> arr(N+1);
		for(int i=0;i<N;i++){
			int temp;
			cin >> temp;
			arr[temp] = i;
		}
		int target = N-1;
		vector<int> out;
		while(target!=1){
			if(arr[target]==target){
				target--;
			}
			target = arr[target];
			out.push_back(target);
		}
		outputs.push_back(out);
	}
	int a = 1;
	for(auto &it : outputs){
		cout << it.size();
		if(it.size() ==0 ) cout << '\n';
		else{
			for(auto i : it){
				cout << i << " ";
			}
			cout << '\n';
		}
		
	}

	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}