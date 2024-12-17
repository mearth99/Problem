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
	freopen("/mnt/c/Users/dlwls/Downloads/input.txt", "r", stdin);
	freopen("/mnt/c/Users/dlwls/Downloads/myoutput.txt", "w", stdout);
	int test_case,T;
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case){
		vector<int> student(101);
		int remo;
		cin >> remo;
		for(int i=0;i<1000;i++){
			int temp;
			cin >> temp;
			student[temp]++;
		}
		int maxv = 0,output=0;
		for(int i=100;i>=0;i--){
			if(student[i] > maxv){
				maxv = student[i];
				output = i;
			}
		}
		outputs.push_back(output);
	}
	int a = 1;
	for(auto it : outputs){
		cout << '#' << a++ << ' ' << it << '\n'; 
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}