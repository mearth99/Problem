/*
입력
첫 줄에 Y대학교 건물의 수 n과 길의 수 m이 주어진다. (n ≤ 250, m ≤ n * (n - 1) / 2 )
다음 m줄에 걸쳐, u v b (1 ≤ u ≤ n, 1 ≤ v ≤ n, u != v, b = 0 또는 1) 의 형태로 길에 대한 정보가 주어진다.
b가 0일 경우 u에서 v로 가는 일방통행 길인 것이고, b가 1일 경우 u와 v를 잇는 양방향 길이다.
어떤 두 건물 사이를 잇는 길은 최대 한 개이다.
다음 줄에 학생들의 질문의 수 k가 주어진다. (1 ≤ k ≤ 30,000)
다음 k줄에 걸쳐 s e (1 ≤ s ≤ n, 1 ≤ e ≤ n)의 형태로 학생들의 질문들이 주어진다.
이는 질문한 학생이 건물 s에서 건물 e로 가고 싶다는 의미이다.

출력
출력은 k줄에 걸쳐 이루어진다.
각 질문에 대해, 최소 몇 개의 일방통행인 길을 양방향 통행으로 바꿔야 출발지에서 도착지로 갈 수 있는지를 출력한다.
모든 길을 양방향으로 바꾸더라도 서로 도달 불가능한 건물은 없다.
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define INF 20000000

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m;
    cin >> n >> m;
    
    vector<vector<int>> roads(n+1,vector<int>(n+1,INF));
    for(int i=1;i<=n;i++)
        roads[i][i] = 0;

    for(int i=0;i<m;i++){
        int u,v,b;
        cin >> u >> v >> b;
        roads[u][v] = 0;
        if(b==0)
            roads[v][u] = 1;
        else
            roads[v][u] = 0;
   }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                roads[i][j] = min(roads[i][j], roads[i][k]+roads[k][j]);
            }
        }
    }
    int k;
    cin >> k;

    for(int i=1;i<=k;i++){
        int from, to;
        cin >> from >> to;
        cout << roads[from][to] << '\n';
    }
    return 0;
}