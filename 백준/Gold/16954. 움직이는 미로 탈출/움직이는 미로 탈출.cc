#include <iostream>
#include <queue>
using namespace std;

int arr[8][8];
int visited[8][8][9] = {0};
int dy[8] = { -1,1,0,0,-1,-1,1,1 };
int dx[8] = { 0,0,-1,1,-1,1,-1,1 };
struct escape {
    int y, x, times;
};
bool check_wall(int y,int x, int times) {
    int ny = y - times;
    if (ny >= 0 && ny < 8 && !arr[ny][x]) {
        return true;
    }
    
    return false;
}
int BFS() {
    queue<escape> q;
    q.push({ 7,0,0 });
    while (!q.empty()) {
        int y = q.front().y;
        int x = q.front().x;
        int times = q.front().times;
        q.pop();
        if (y == 0 && x == 7 || times >= 8) {
            return 1;
        }
        if (check_wall(y, x, times)) continue;
        for (int i = 0; i < 8; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny >= 0 && ny < 8 && nx >= 0 && nx < 8 && !visited[ny][nx][times]) {
                visited[ny][nx][times] = 1;
                if (check_wall(ny,nx, times)) continue;
                q.push({ ny,nx,times + 1 });
            }
        }
        visited[y][x][times] = 1;
        q.push({ y, x, times + 1 });
    }
    return 0;
}

int main() {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            char temp;
            cin >> temp;
            if (temp == '.')
                arr[i][j] = 1;
            else
                arr[i][j] = 0;
        }
    }
    cout << BFS();
    return 0;
}