#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;
//4방향을 감시할 수 있다.
struct CCTV {
    int y, x, type, change;
};
int c_dir[6] = { 0, 4, 2, 4, 4, 1 };
vector<vector<int>> arr;
vector<CCTV> cctv;
int N, M;

void left(vector<vector<int>>& v,int y, int x) {
    while (x > -1 && v[y][x] != 6)
        v[y][x--] = 1;
}
void right(vector<vector<int>>& v, int y, int x) {
    while (x < M && v[y][x] != 6)
        v[y][x++] = 1;
}
void Up(vector<vector<int>>& v, int y, int x) {
    while (y > -1  && v[y][x] != 6)
        v[y--][x] = 1;
}
void Down(vector<vector<int>>& v, int y, int x) {
    while (y < N && v[y][x] != 6)
        v[y++][x] = 1;
}
void Check(CCTV target, vector<vector<int>> &temp) {   
    switch (target.type) {
        case 1:
            switch (target.change) {
                case 1: 
                    Up(temp, target.y, target.x);
                break;
                case 2:
                    Down(temp, target.y, target.x);
                break;
                case 3:
                    left(temp, target.y, target.x);
                break;
                case 4:
                    right(temp, target.y, target.x);
                break;
            }
        break;
        case 2:
            switch (target.change) {
            case 1:
                Up(temp, target.y, target.x);
                Down(temp, target.y, target.x);
                break;
            case 2:
                left(temp, target.y, target.x);
                right(temp, target.y, target.x);
                break;
            }
        break;
        case 3:
            switch (target.change) {
            case 1:
                Up(temp, target.y, target.x);
                right(temp, target.y, target.x);
                break;
            case 2:
                right(temp, target.y, target.x);
                Down(temp, target.y, target.x);
                break;
            case 3:
                left(temp, target.y, target.x);
                Down(temp, target.y, target.x);
                break;
            case 4:
                Up(temp, target.y, target.x);
                left(temp, target.y, target.x);
                break;
            }
        break;
        case 4:
            switch (target.change) {
            case 1:
                Up(temp, target.y, target.x);
                right(temp, target.y, target.x);
                left(temp, target.y, target.x);
                break;
            case 2:
                Down(temp, target.y, target.x);
                left(temp, target.y, target.x);
                right(temp, target.y, target.x);
                break;
            case 3:
                left(temp, target.y, target.x);
                Down(temp, target.y, target.x);
                Up(temp, target.y, target.x);
                break;
            case 4:
                Up(temp, target.y, target.x);
                Down(temp, target.y, target.x);
                right(temp, target.y, target.x);
                break;
            }
        break;
        case 5:
            Up(temp, target.y, target.x);
            Down(temp, target.y, target.x);
            right(temp, target.y, target.x);
            left(temp, target.y, target.x);
        break;
    }
    
}
int minv = 0x7fffffff;
void DFS(int cur, vector<CCTV> ch) {
    if (cur == cctv.size()) {
        vector<vector<int>> temp = arr;
        for (auto it : ch) 
            Check(it, temp);
        int cnt = 0;
        for (auto it : temp) {
            for (auto i : it) {
                if (i == 0)
                    cnt++;
            }
        }
        minv = min(minv, cnt);
        return;
    }
    vector<CCTV> temp = ch;
    for (int i = 1; i <= c_dir[cctv[cur].type]; i++) {
        temp[cur].change = i;
        DFS(cur + 1, temp);
    } 
}


void solution() {
    cin >> N >> M;
    arr.resize(N, vector<int>(M, 0));
    for (int i = 0; i < N;i++) {
        for (int j = 0; j < M;j++) {
            cin >> arr[i][j];
            if (arr[i][j] > 0 && arr[i][j] < 6) cctv.push_back({ i,j,arr[i][j], 0 });
        }
    }
    DFS(0, cctv);
    cout << minv;
}



int main() {
    ios_base::sync_with_stdio(NULL);
    cin.tie(0);

    solution();
    return 0;
}