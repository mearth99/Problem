#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

unordered_map<int, unordered_map<int, pair<int, int>>> maps;
vector<int> dice(10);
vector<pair<int, int>> horse(4, { 0,1 });
int maxv = 0;

void DFS(int cur, int sum) {
    if (cur == 10) {
        maxv = max(maxv, sum);
        return;
    }

    for (int i = 0; i < 4; i++) {
        if (horse[i].second == 3) continue; // 이미 도착한 말은 skip

        pair<int, int> target = horse[i];
        int cnt = dice[cur];

        // 파란색 화살표 처리
        if ((target.first == 10 || target.first == 20 || target.first == 30) &&
            target.second == 1) {
            target = maps[target.first][0];
            cnt--;
        }

        // 이동
        while (cnt > 0 && target.second != 3) {
            target = maps[target.first][target.second];
            cnt--;
        }

        // 이동 가능 여부 체크
        if (target.second != 3) {  // 도착 지점이 아닐 때만 중복 체크
            bool occupied = false;
            for (int j = 0; j < 4; j++) {
                if (i != j && horse[j].first == target.first &&
                    horse[j].second == target.second) {
                    occupied = true;
                    break;
                }
            }
            if (occupied) continue;
        }

        // 이동 실행
        pair<int, int> backup = horse[i];
        horse[i] = target;

        DFS(cur + 1, sum + target.first);

        // 상태 복구
        horse[i] = backup;
    }
}

void solution() {
    // 기본 경로 초기화
    for (int i = 0; i < 40; i += 2) {
        maps[i][1] = { i + 2, 1 };
    }

    // 특수 경로 초기화
    maps[10][0] = { 13, 0 };
    maps[13][0] = { 16, 0 };
    maps[16][0] = { 19, 0 };
    maps[19][0] = { 25, 0 };

    maps[20][0] = { 22, 0 };
    maps[22][0] = { 24, 0 };
    maps[24][0] = { 25, 0 };

    maps[30][0] = { 28, 0 };
    maps[28][0] = { 27, 0 };
    maps[27][0] = { 26, 0 };
    maps[26][0] = { 25, 0 };

    maps[25][0] = { 30, 2 };
    maps[30][2] = { 35, 0 };
    maps[35][0] = { 40, 1 };
    maps[40][1] = { 0, 3 };  // 도착점

    for (auto& it : dice) {
        cin >> it;
    }

    DFS(0, 0);
    cout << maxv;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solution();
    return 0;
}