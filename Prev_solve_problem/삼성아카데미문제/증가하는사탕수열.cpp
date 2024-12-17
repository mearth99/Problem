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
		int A,B,C;
		int output = 0;
		cin >> A >> B >> C;
		if(B>=C){
			output += (B-C+1);
			B -= B-C+1;
		}	
		if(A>=B){
			output += (A-B+1);
			A-= A-B+1;
		}
		if(A>0 && B>0 && C>0) outputs.push_back(output);
		else outputs.push_back(-1);

	}
	int a = 1;
	for(auto &it : outputs){
		cout << '#' << a++ << ' ' << it << '\n';
	}

	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}