#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <string>
using namespace std;

bool check(string text, int limit){
	for(int i=0;i<text.size()/2;i++){
		if(text.at(i)!=text.at(text.size()-1-i))
			return false;
	}
	return true;
}

vector<int> outputs;
vector<vector<char>> arr;
int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
  	cin.tie(NULL);
	cout.tie(NULL);	
	freopen("input.txt", "r", stdin);
	freopen("myoutput.txt", "w", stdout);
	int test_case,T=10;

	for(test_case = 1; test_case <= T; ++test_case){
		arr.resize(8,vector<char>(8));
		int limit,output=0;
		cin >> limit;
		if(limit==1){
			outputs.push_back(64);
			continue;
		}
		for(int i=0;i<8;i++){
			string temp;
			cin >> temp;
			for(int j=0;j<temp.size();j++){
				arr[i][j] = temp.at(j);
			}
		}
		//가로 탐색
		string search;
		for(int i=0;i<8;i++){
			for(int j=0;j<8-limit;j++){
				if(search.size()<limit){
					search.push_back()
				}
			}
		}
	}
	int a = 1;
	for(auto &it : outputs){
		cout << '#' << a++ << ' ' << it << '\n';
	}

	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}