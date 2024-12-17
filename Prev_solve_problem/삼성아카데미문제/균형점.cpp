#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <string>
#include <cmath>
using namespace std;

//1. 균형점을 탐색하기 위해 일일히 탐색하는 것은 많은 시간 소모가 소요된다.
//2. 이분 탐색을 통해 접근한다면 이 수치를 상당 부분 떨어뜨릴 수 있다.
//3. 좌표는 오름차순으로 정렬되어 있다.


vector<pair<int,int>> arr;
void search(int num){
	int start_pos = arr[num].first;
	int end_pos = arr[num+1].first;

	double left_pos = start_pos;
	double right_pos = end_pos;
	double mid = 0;
	int limit_cnt = 0;
	while(left_pos <= right_pos && limit_cnt <= 100){
		mid = (left_pos + right_pos) / 2.0;

		double left_value=0, right_value=0;
		for(int i=0;i<arr.size();i++){
			if(i<=num)
				left_value += arr[i].second / ((mid-arr[i].first)*(mid-arr[i].first));
			else
				right_value += arr[i].second / ((mid-arr[i].first)*(mid-arr[i].first));
		}
		if(abs(left_value - right_value)<= pow(10,-13)){
			break;
		}
		else if(left_value > right_value){ //left의 값이 높으므로, right쪽으로 이동해야한다.
			left_pos = mid;
		}
		else {
			right_pos = mid;
		}
		limit_cnt++;
	}
	printf(" %.10f", mid);
	return;
}

int main(int argc, char** argv)
{
	freopen("input.txt", "r", stdin);
	freopen("myoutput.txt", "w", stdout);
	int test_case,T;
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case){
		int N;
		cin >> N;
		arr.resize(N); // first : distacne, second: weight

		for(int i=0;i<N;i++){
			cin >> arr[i].first;
		}
		for(int i=0;i<N;i++){
			cin >> arr[i].second;
		}
		cout << "#" << test_case; 

		for(int i=0;i<N-1;i++){
			search(i);
		}
		cout << '\n';
		arr.clear();
	}


	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}