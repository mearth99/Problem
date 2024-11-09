#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
//DFS 탐색(깊이 우선)과 DP를 합친 문제로, 이미 계산한 DP가 있다면 더 이상 계산하지 않는 방식으로 계산을 단축시킬 수 있다.
//DP[a][b]=c a: 경찰차 1의 최신 사건, b: 경찰차2의 최신 사건 일때 최소비용으로 둔다면, 좌표값을 계속 기억하지 않고도 써먹을 수 있다.
//사건의 갯수가 W이기 때문에, W를 구하기 위해서는 DP[W][0] , DP[W-1][1], DP[W-2][2] ... DP[0][W] 사이의 값을 모두 구해야한다.
int D[1001][1001];
vector<pair<int,int>> road;
int N,W;
int get_distance(pair<int,int> a, pair<int,int> b){
    return abs(a.first - b.first) + abs(a.second-b.second);
}
int DFS(int p1, int p2){
    if(p1==W || p2==W) return 0;
    if(D[p1][p2] != -1) return D[p1][p2];
    int na = max(p1,p2) + 1;
    int d1,d2,r1,r2;
    if(p1==0)
        d1 = get_distance({1,1}, road[na]);
    else
        d1 = get_distance(road[p1],road[na]);
    if(p2==0)
        d2 = get_distance({N,N}, road[na]);
    else
        d2 = get_distance(road[p2],road[na]);
    r1 = d1 + DFS(na,p2);
    r2 = d2 + DFS(p1,na);
    D[p1][p2] = min(r1,r2);
    return D[p1][p2];
}
void Check(int p1, int p2){
    if(p1==W || p2==W) return;
    int na = max(p1,p2) + 1;
    int d1,d2,r1,r2;
    if(p1==0)
        d1 = get_distance({1,1}, road[na]);
    else
        d1 = get_distance(road[p1],road[na]);
    if(p2==0)
        d2 = get_distance({N,N}, road[na]);
    else
        d2 = get_distance(road[p2],road[na]);
    if(D[na][p2]+d1 > D[p1][na]+d2){
        cout << 2 << '\n';
        Check(p1,na);
    }else{
        cout << 1 << '\n';
        Check(na,p2);
    }
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
    cin >> N >> W;
    memset(D,-1,sizeof(D));
    road.push_back({0,0});
    for(int i=0;i<W;i++){
        int x,y;
        cin >> x >> y;
        road.push_back({x,y});
    }
    cout << DFS(0,0) << '\n';
    Check(0,0);
    return 0;
}