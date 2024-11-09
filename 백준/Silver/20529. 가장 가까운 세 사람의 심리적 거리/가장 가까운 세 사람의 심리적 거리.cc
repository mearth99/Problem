#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<algorithm>
using namespace std;

#define INF ((1<<31)-1)
/*
* 문제 설명 및 링크
https://www.acmicpc.net/problem/20529
가장 가까운 세사람의 심리적 거리는 2^4 가지에 해당하는 mbti를 부여받은 사람들 중 3명을 뽑아 가장 가까운 심리적 거리를 구하는 것이다.

나는 이렇게 접근하기로 했다.
1. bitmask을 부여하여 0~15까지 값으로 부여한다.
2. 조합을 이용하여 3개의 값을 뽑아낸다.
3. 뽑아낸 3개의 값을 toggle을 이용해 (XOR) 구한다.
4. 최솟값을 계속 비교하여 확인한다.
5. ESTJ = 0 , INFP = 15로 두었다.
*/
/*
* 소감
*/

void solution() {
	int N;
	int output = 100001;
	cin >> N;
	
	vector<int> arr(N, 0);
	vector<int> temp(N, 0);
	temp[0] = temp[1] = temp[2] = 1;
	for (int i = 0; i < N; i++) {
		string mbti;
		cin >> mbti;
		for (int j = 0; j < 4; j++) {
			int v = 0;
			if (mbti.at(j) == 'E' || mbti.at(j) == 'S' || mbti.at(j) == 'T' || mbti.at(j) == 'J') {
				v = 0;
			}
			else {
				v = 1;
			}
			arr[i] += (v << 3-j);
		}
	}
	if (N > 32) {
		cout << 0 << '\n';
		return;
	}
	do
	{
		vector<int> t(3);
		int t_i = 0;
		int distan = 0;
		for (int i = 0; i < N; i++) {
			if (temp[i] == 1)
				t[t_i++] = arr[i];
		}
		for (int i = 0; i < 4; i++) {
			int a = (t[0] & (1 << i)) > 0 ? 1 : 0;
			int b = (t[1] & (1 << i)) > 0 ? 1 : 0;
			int c = (t[2] & (1 << i)) > 0 ? 1 : 0;
			if (a != b) distan++;
			if (a != c) distan++;
			if (b != c) distan++;
		}
		output = min(output, distan);
		t.clear();
		/* code */
	} while (prev_permutation(temp.begin(), temp.end()));
	cout << output << '\n';
	arr.clear();
	temp.clear();
}

int main() {

	cin.tie(NULL); ios_base::sync_with_stdio(false);
	int T;
	cin >> T;
	while (T--)
		solution();
	return 0;
}

