#include <iostream>
#include <queue>
#define MAX 100
using namespace std;

int W, H;
char arr[MAX][MAX];
int visit[MAX][MAX][4];  // [y][x][direction]
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };
int sy, sx, ey, ex;

void BFS() {
    queue<pair<pair<int, int>, pair<int, int>>> q;  // {{y,x}, {direction,cost}}
    
    for (int i = 0; i < 4; i++) {
        q.push({{sy,sx}, {i,0}});
        visit[sy][sx][i] = 0;
    }
    
    while (!q.empty()) {
        int y = q.front().first.first;
        int x = q.front().first.second;
        int d = q.front().second.first;
        int cost = q.front().second.second;
        q.pop();
        
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            int nextcost = cost;
            
            if (ny >= 0 && ny < H && nx >= 0 && nx < W && arr[ny][nx] != '*') {
                if (d != i) nextcost++;
                if (visit[ny][nx][i] > nextcost) {
                    visit[ny][nx][i] = nextcost;
                    q.push({{ny,nx}, {i,nextcost}});
                }
            }
        }
    }
}

void solution() {
    cin >> W >> H;
    bool flag = false;
    
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            for(int k = 0; k < 4; k++) {
                visit[i][j][k] = 0x7fffffff;
            }
        }
    }
    
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 'C') {
                if (!flag) {
                    sy = i;
                    sx = j;
                    flag = true;
                }
                else {
                    ey = i;
                    ex = j;
                }
            }
        }
    }
    
    BFS();
    
    int ans = 0x7fffffff;
    for(int i = 0; i < 4; i++) {
        ans = min(ans, visit[ey][ex][i]);
    }
    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solution();
    return 0;
}