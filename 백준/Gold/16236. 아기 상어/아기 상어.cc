#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using pii = pair<int, int>;
using piii = pair<int, pii>;
vector<vector<int>> map;
vector<vector<bool>> isVisited;
pii curPos;
piii nextPos;
int N, curSize = 2, time, cnt;
int dy[] = {1, -1, 0, 0}, dx[] = {0, 0, 1, -1};
void input()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N;
    isVisited = vector<vector<bool>>(N, vector<bool>(N));
    map = vector<vector<int>>(N, vector<int>(N));
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cin >> map[i][j];
            if (map[i][j] == 9) // 시작
            {
                map[i][j] = 0;
                curPos = {i, j};
            }
        }
    }
}
void find()
{
    nextPos = {400, {20, 20}};
    queue<piii> q;
    q.push({0, curPos});
    isVisited[curPos.first][curPos.second] = true;
    while (!q.empty())
    {
        piii cur = q.front();
        q.pop();

        for (int i = 0; i < 4; ++i)
        {
            int ny = cur.second.first + dy[i];
            int nx = cur.second.second + dx[i];
            piii next = {cur.first + 1, {ny, nx}};

            if (ny < 0 || nx < 0 || ny >= N || nx >= N || isVisited[ny][nx]) // 범위를 벗어났거나 이미 방문했다면
            {
                continue;
            }
            isVisited[ny][nx] = true;

            if (map[ny][nx] == 0 || map[ny][nx] == curSize) // 비어있거나 크기가 같다면
            {
                q.push(next);
            }
            else if (map[ny][nx] < curSize) // 아기 상어보다 작다면
            {
                if (next.first < nextPos.first) // 다른 물고기보다 거리가 가깝다면
                {
                    nextPos = next;
                }
                else if (next.first == nextPos.first)
                {
                    if (next.second.first < nextPos.second.first) // 다른 물고기보다 위에 있다면
                    {
                        nextPos = next;
                    }
                    else if (next.second.first == nextPos.second.first)
                    {
                        if (next.second.second < nextPos.second.second) // 다른 물고기보다 왼쪽에 있다면
                        {
                            nextPos = next;
                        }
                    }
                }
            }
        }
    }
}
void solve()
{
    while (true)
    {
        find();

        if (nextPos.first == 400) // 못 찾았다면
        {
            break;
        }

        ++cnt;
        if (cnt == curSize) // 크기만큼 물고기를 먹었다면
        {
            ++curSize;
            cnt = 0;
        }
        time += nextPos.first;
        map[nextPos.second.first][nextPos.second.second] = 0;
        curPos = nextPos.second;

        fill(isVisited.begin(), isVisited.end(), vector<bool>(N));
    }
    cout << time;
}
int main()
{
    input();
    solve();
    return 0;
}