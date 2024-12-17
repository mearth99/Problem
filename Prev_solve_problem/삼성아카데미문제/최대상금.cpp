#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <string>
using namespace std;

int output = 0;

void DFS(string number, int count, int cur_count){
	if(count == cur_count){
		output = max(output, stoi(number));
		return;
	}
	for(int i=0;i<number.size()-1;i++){
		for(int j=i+1;j<number.size();j++){
			swap(number[i],number[j]);
			DFS(number,count,cur_count+1);
			swap(number[i],number[j]);
		}
	}
	return;
}

int main(int argc, char** argv)
{
	int test_case,T;
	vector<int> outputs;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case){
		output = 0;
		int count;
		string number;
		cin >> number >> count;
        if(count > number.size()) count = number.size();
		DFS(number,count,0);
		outputs.push_back(output);
	}
	int a=1;
	for(auto it : outputs)
		cout << '#' << a++ << ' ' << it << '\n';
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}