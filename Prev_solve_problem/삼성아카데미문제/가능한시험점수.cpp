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
set<int> output;
int main(int argc, char** argv)
{
	freopen("input.txt", "r", stdin);
	freopen("myoutput.txt", "w", stdout);
	int test_case,T;
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case){
		output.clear();
		int N;
		cin >> N;
		vector<int> arr(N);
		vector<int> sum(N+1);
		for(int i=0;i<N;i++){
			cin >> arr[i];

		}
		sum[0] = 0;
		for(int i=0;i<N;i++){
			sum[i+1] = sum[i] + arr[i];
		}
		output.insert(0);
		for(int i=0;i<=N;i++){
			for(int j=0;j<=i;j++){
				output.insert(sum[i]-sum[j]);
			}
		}
		outputs.push_back(output.size());
	}
	int a = 1;
	for(auto &it : outputs){
		cout << '#' << a++ << ' ' << it << '\n';
	}

	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}