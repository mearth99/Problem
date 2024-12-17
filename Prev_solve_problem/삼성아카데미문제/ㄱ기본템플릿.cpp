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
	ios::sync_with_stdio(false);
  	cin.tie(NULL);
	cout.tie(NULL);	
	freopen("input.txt", "r", stdin);
	freopen("myoutput.txt", "w", stdout);
	int test_case,T;
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case){
		
	}
	int a = 1;
	for(auto &it : outputs){
		cout << '#' << a++ << ' ' << it << '\n';
	}

	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}