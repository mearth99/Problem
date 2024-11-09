#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int main() {
	int R, C;

	cin >> R >> C;

	int **pleasure = new int*[R];
	//2차원 배열 동적할당
	for (int i = 0; i < R; i++) {
		pleasure[i] = new int[C];
	}

	pair <int, int> blank;
	int min = 1001; //1000최대
	//배열 입력
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> pleasure[i][j];
			if (min > pleasure[i][j] && (i + j) % 2 == 1) {
				min = pleasure[i][j];
				blank.first = i;
				blank.second = j;
			}
		}
	}


	string move;
	int i, j;
	if (R % 2 == 1) { //R이 홀수 일때
		for (i = 0; i < R; i++) {
			for (j = 0; j < C - 1; j++) {
				if (i % 2 == 0)
					move += 'R'; //오른쪽 방향
				else
					move += 'L'; //왼쪽 방향
			}
			if (i == R - 1)
				break;
			move += 'D'; //아래쪽 방향
		}
	}
	else if (C % 2 == 1) { //C가 홀수 일때
		for (i = 0; i < C; i++) {
			for (j = 0; j < R - 1; j++) {
				if (i % 2 == 0)
					move += 'D'; //아래쪽 방향
				else
					move += 'U'; //위쪽 방향
			}
			if (i == C - 1)
				break;
			move += 'R'; //오른쪽 방향
		}
	}
	else { //R, C 모두 짝수 일때
		//모두 짝수일 때는 모든 칸을 지나갈수 없음. 무조건 한칸은 지나가지 않음
		int r, c;
		if (blank.first % 2 == 1)
			r = blank.first - 1; //blank가 있는 윗줄까지
		else
			r = blank.first; //blank가 있는 줄까지 

		//blank가 있는 줄 전까지  
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < C - 1; j++) {
				if (i % 2 == 0)
					move += 'R';
				else
					move += 'L';
			}
			move += 'D';
		}


		//blank 전
		c = blank.second;

		for (int i = 0; i < c; i++) {
			if (i % 2 == 0)
				move += "DR";
			else
				move += "UR";
		}

		//blank 후
		for (int i = c; i < C - 1; i++) {
			if (i % 2 == 0)
				move += "RD";
			else
				move += "RU";
		}

		for (int i = r + 2; i < R; i++) {
			move += 'D';
			for (int j = 0; j < C - 1; j++) {
				if (i % 2 == 0)
					move += 'L';
				else
					move += 'R';
			}
		}

	}

	cout << move << endl;

	return 0;
}