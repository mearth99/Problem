#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <string>
using namespace std;

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
  	cin.tie(NULL);
	cout.tie(NULL);	

	int test_case,T;
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case){
		int N, B;
		int mingap = INT32_MAX;
		cin >> N >> B;
		vector<int> arr(N);
		vector<int> sum(N+1,0);
		for (int i = 0; i < N; i++)
			cin >> arr[i];
		sum[0] = 0;
		for (int i = 1; i <= N; i++)
			sum[i] = sum[i - 1] + arr[i-1];

		for (int i = 0; i <= N; i++) {
			for (int j = 0; j <= N; j++) {
				if (i == j) continue;
				int gap = abs(sum[i] - sum[j]);
				if (gap >= B)
					mingap = min(mingap, gap);
			}
		}
		cout << '#' << test_case << ' ' << mingap-B << '\n';
		arr.clear();
	}

	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}