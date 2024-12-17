#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <string>
using namespace std;

vector<int> outputs;
vector<int> arr;
vector<int> DP;

//DP P에서 C 사이 집이 해변을 보기 위한 철거 비용
//DP[i][i+1] = 1(arr[i]>=arr[i+1]) or 0(else)
//DP[i][i+2] = DP[i][i+1] + DP[i+1][i+2] 


int main(int argc, char** argv)
{
	freopen("input.txt", "r", stdin);
	freopen("myoutput.txt", "w", stdout);
	int test_case,T;
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case){
		int N,output=0;
		cin >> N;
		arr.resize(N);
		DP.resize(N);
		for(int i=0;i<N;i++){
			cin >> arr[i];
		}
		int p = arr[0];
		for(int i=0;i<N;i++){
			DP[i] = 1;
			for(int j=0;j<i;j++)
				if(arr[j]<arr[i] && DP[i]<DP[j]+1)
					DP[i] = DP[j]+1;
				if(output<DP[i]) output = DP[i];
		}
		outputs.push_back(N-output+1);
	}
	int a = 1;
	for(auto &it : outputs){
		cout << '#' << a++ << ' ' << it << '\n';
	}

	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}