#include<iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;


int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;
	vector<int> output;
	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
	for(test_case = 1; test_case <= 10; test_case++)
	{
		int N,temp,sum=0;
		cin >> N;
		vector<int> arr(N);
		
		for(int i=0;i<N;i++){
			cin >> arr[i];
		}
		for(int i=2;i<N-2;i++){
			//조망권 확보: 타깃이 가장 높은 값이면 조망권 확보.
			int opp = max({arr[i-2],arr[i-1],arr[i+1],arr[i+2]});
			if(arr[i]>opp) sum += arr[i] - opp;
		}
		output.push_back(sum);
    	arr.clear();
	}
	int test = 1;
	for(auto it : output){
		cout << '#' << test++ << " " << it << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}