#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <stack>
#include <cstring>
#include <string>
using namespace std;

vector<int> outputs;

int main(int argc, char** argv)
{
	freopen("input.txt", "r", stdin);
	freopen("myoutput.txt", "w", stdout);
	int test_case;


	for(test_case = 1; test_case <= 10; ++test_case){
		int N;
		cin >> N;
		char cur;
		stack<char> s;
		for(int i=0;i<N;i++){
			//입력 부분
			cin >> cur;
			//1. S에 없으면 S에 넣는다.
			//2. S가 있다면 Top와 비교한다.
			if(s.empty()){
				s.push(cur);
			}else{
				char opp = s.top();
				if(cur=='>' && opp=='<' || cur==')' && opp=='(' || cur=='}' && opp=='{' || cur==']' && opp=='['){
					s.pop();
				}else{
					s.push(cur);
				}
			}
		}
		if(s.empty()) outputs.push_back(1);
		else outputs.push_back(0);
	}
	int a = 1;
	for(auto it : outputs)
		cout << '#' << a++ << ' ' << it << '\n';
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}