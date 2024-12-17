#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <string>
using namespace std;
int N;
vector<vector<int>> rotation(vector<vector<int>> arr){
	vector<vector<int>> output(N,vector<int>(N));
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++)
			output[i][j] = arr[N-1-j][i];
	}
	return output;
}

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
  	cin.tie(NULL);
	cout.tie(NULL);	
	int test_case,T;
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case){
		
		cin >> N;
		vector<vector<int>> arr(N,vector<int>(N));
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++)
				cin >> arr[i][j];
		}
		vector<vector<int>> one = rotation(arr);
		vector<vector<int>> two = rotation(one);
		vector<vector<int>> three = rotation(two);
		cout << '#' << test_case << '\n';
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++)
				cout << one[i][j]; 
			cout << " ";
			for(int j=0;j<N;j++)
				cout << two[i][j];
			cout << " "; 
			for(int j=0;j<N;j++)
				cout << three[i][j];
			cout << " "; 
			cout << '\n';
		}
		arr.clear();
		one.clear();
		two.clear();
		three.clear();
	}


	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}