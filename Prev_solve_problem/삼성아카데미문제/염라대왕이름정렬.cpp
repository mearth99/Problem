#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <string>
#include <set>
using namespace std;

vector<int> outputs;

struct cmp{
	bool operator() (const string &p1, const string &p2) const{
		if(p1.length() == p2.length()){
			return p1 < p2;
		}
		else return p1.length() < p2.length();
	}
};

int main(int argc, char** argv)
{
	freopen("input.txt", "r", stdin);
	freopen("myoutput.txt", "w", stdout);
	int test_case,T;
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case){
		int N;
		cin >> N;
		set<string, cmp> namebook;
		for(int i=0;i<N;i++){
			string temp;
			cin >> temp;
			namebook.insert(temp);
		}
		cout << '#' << test_case << '\n'; 
		for(const auto& it : namebook){
			cout << it << '\n';
		}
		namebook.clear();
	}
	// int a = 1;
	// for(auto &it : outputs){
	// 	cout << '#' << a++ << ' ' << it << '\n';
	// }

	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}