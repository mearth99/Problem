#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <string>
using namespace std;

vector<double> outputs;

int main(int argc, char** argv)
{
	freopen("/mnt/c/Users/dlwls/Downloads/input.txt", "r", stdin);
	freopen("/mnt/c/Users/dlwls/Downloads/myoutput.txt", "w", stdout);
	int test_case,T;
	cin>>T;
	
	cout<<fixed;
    cout.precision(20);
	for(test_case = 1; test_case <= T; ++test_case){
		int N,cnt=0;
		double sum=0.0;
		cin >> N;
		vector<int> arr(N);
		for(int i=0;i<N;i++){
			cin >> arr[i];
		}
		for(int i=1;i<(1<<N);i++){
			double subsum = 0;
			int subcnt = 0; 
			for(int j=0;j<N;j++){
				if(i&(1<<j)){
					subsum += arr[j];
					subcnt++;
				}
			}
			sum += (subsum)/subcnt;
			cnt++;
		}
		outputs.push_back(sum/cnt);
		arr.clear();
	}
	int a = 0;
	for(auto it : outputs)
		printf("#%d %.20g\n",a++,it);
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}