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
	int test_case,T;
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case){
		int N,M;
		int output = -98764531;
		cin >> N >> M;
		vector<int> arr(N);
		vector<int> arr2(M);
		for(int i=0;i<N;i++){
			cin >> arr[i];
		}
		for(int i=0;i<M;i++){
			cin >> arr2[i];
		}
		if(N<M){
			for(int k=0;k<=M-N;k++){
				int sum = 0;
				for(int i=0;i<N;i++){
					sum += arr[i]*arr2[i+k];
				}
				output = max(output,sum);
			}
			
		}else{
			for(int k=0;k<=N-M;k++){
				int sum = 0;
				for(int i=0;i<M;i++){
					sum += arr[i+k]*arr2[i];
				}
				output = max(output,sum);
			}
		}
		outputs.push_back(output);		
	}
	int a = 1;
	for(auto &it : outputs){
		cout << '#' << a++ << ' ' << it << '\n';
	}

	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}