#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <string>
using namespace std;

vector<vector<long long>> outputs;

int main(int argc, char** argv)
{
	freopen("input.txt", "r", stdin);
	freopen("myoutput.txt", "w", stdout);
	int test_case,T;
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case){
		int n;
		cin >> n;
		vector<long long> arr(2*n);
		vector<long long> output;
		for(int i=0;i<2*n;i++)
			cin >> arr[i];
		int left = 0, right = 0;
		while(left < 2*n || right < 2*n){

			if(3*arr[right]/4 == arr[left])  {
				output.push_back(arr[left]);
				arr[right] = -1;
				right++;
			}
			if(3*arr[right]/4 < arr[left]) right++;
			else left++;
		}
		outputs.push_back(output);
		output.clear();
		arr.clear();
	}
	int a = 1;
	for(auto &it : outputs){
		cout << '#' << a++ << ' ';
		for(auto &i : it)
			cout << i << ' ';
		cout << '\n';
	}

	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}