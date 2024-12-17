#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <string>
using namespace std;

vector<string> outputs;
int rever(string text){
	string target = text;
	reverse(text.begin(),text.end());
	return text.compare(target);
}
int some(string text){
	string target = text.substr(0,(text.size()-1)/2);
	return rever(target);
}

int main(int argc, char** argv)
{
	freopen("input.txt", "r", stdin);
	freopen("myoutput.txt", "w", stdout);
	int test_case,T;
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case){
		string text;
		cin >> text;
		if(rever(text)==0 && some(text)==0) outputs.push_back("YES");
		else outputs.push_back("NO");
	}
	int a = 1;
	for(auto &it : outputs){
		cout << '#' << a++ << ' ' << it << '\n';
	}

	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}