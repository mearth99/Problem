#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <string>
using namespace std;

int output = 0;

/*
사재기는 시세가 감소해간다면 아무것도 구할 수 없고,
시세가 증가해가면 계속 구매하면 된다.
즉, 현재 값보다 더 큰 값이 앞으로 있다면. 구매하면 된다.
앞으로 큰값이 있다는 건 어떻게 알 수 있을까?
*/

int main(int argc, char** argv)
{
	int test_case,T;
	vector<long long> outputs;
	vector<long long> arr;
	freopen("/mnt/c/Users/dlwls/Downloads/input.txt", "r", stdin);
	freopen("/mnt/c/Users/dlwls/Downloads/myoutput.txt", "w", stdout);
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case){
		long long N,getMax = 0,output = 0,buy_cnt=0;
		cin >> N;
		for(int i=0;i<N;i++){
			int temp;
			cin >> temp;
			arr.push_back(temp);
		}
		getMax = *max_element(arr.begin(),arr.end());
		for(int i=0;i<N;i++){
			if(arr[i]<getMax){
				output -= arr[i];
				buy_cnt++;
			} else if(arr[i]==getMax){
				output += (buy_cnt) * getMax;
				if(i!=N-1)
					getMax = *max_element(arr.begin()+i+1,arr.end());
					buy_cnt=0;
			}
		}
		outputs.push_back(output);
		arr.clear();
	}
	int a=1;
	for(auto it : outputs)
		cout << '#' << a++ << ' ' << it << '\n';
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}