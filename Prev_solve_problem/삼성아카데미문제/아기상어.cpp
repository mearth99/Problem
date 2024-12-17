#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <string>
using namespace std;

vector<int> outputs;

/*
	1. 아기상어는 가까이(위, 왼쪽)에 있는 먹이를 먹으러 가지만, 길막을 당하여 가지 못할 수 있다.
	2. Priority Queue로 우선순위에 따라 조절할 수 있다.
	3. 
*/

int main(int argc, char** argv)
{
	freopen("input.txt", "r", stdin);
	freopen("myoutput.txt", "w", stdout);
	int test_case,T;
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case){
		int N;
		cin >> N;
		vector<vector<int>> arr(N, vector<int>(N));
	}
	int a = 1;
	for(auto &it : outputs){
		cout << '#' << a++ << ' ' << it << '\n';
	}

	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}