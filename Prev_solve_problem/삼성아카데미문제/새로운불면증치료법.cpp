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
		bool arr[10] = {0};
		int check = 0;
		long long int N;
		int i=1;
		cin >> N;
		while(true){
			long long int target = N*i;
			while(target>=1){
				int value = target % 10;
				if(!arr[value]){
					arr[value] = true;
					check++;
				} 
				target /=10;
			}
			if(check==10) break;
			i++;
		}
		outputs.push_back(i*N);
	}
	int a = 1;
	for(auto &it : outputs){
		cout << '#' << a++ << ' ' << it << '\n';
	}

	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}