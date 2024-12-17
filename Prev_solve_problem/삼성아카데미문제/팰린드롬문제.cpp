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
		int N,same_size=0, lengths = 0;
		cin >> N >> lengths;
		vector<string> arr;
		vector<string> pallen;
		
		for(int i=0;i<N;i++){
			string temp;
			cin >> temp;
			int flag = true;
			for(int j=0,k=temp.size()-1;j<=k;j++,k--){
				if(temp.at(j)!=temp.at(k)){
					flag = false;
					break;
				} 
			}
			if(flag) pallen.push_back(temp);
			else arr.push_back(temp);
		}
		for(int i=0;i<arr.size();i++){
			string cur = arr[i];
			reverse(cur.begin(),cur.end());
			for(int j=i+1;j<arr.size();j++){
				if(cur.compare(arr[j])==0){
					same_size+=2;
					arr.erase(arr.begin()+j);
					continue;
				}
			}
		}
		int output = lengths * same_size;
		if(!pallen.empty()) output += lengths;
		outputs.push_back(output);
		arr.clear();
		pallen.clear();
	}
	int a = 1;
	for(auto &it : outputs){
		cout << '#' << a++ << ' ' << it << '\n';
	}

	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}