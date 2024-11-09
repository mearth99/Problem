/*
입력
첫째 줄에 V와 E가 빈칸을 사이에 두고 주어진다. (2 ≤ V ≤ 400, 0 ≤ E ≤ V(V-1)) 다음 E개의 줄에는 각각 세 개의 정수 a, b, c가 주어진다. 
a번 마을에서 b번 마을로 가는 거리가 c인 도로가 있다는 의미이다. (a → b임에 주의) 거리는 10,000 이하의 자연수이다. (a, b) 쌍이 같은 도로가 여러 번 주어지지 않는다.

출력
첫째 줄에 최소 사이클의 도로 길이의 합을 출력한다. 운동 경로를 찾는 것이 불가능한 경우에는 -1을 출력한다.
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define INF 20000000


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int v,e,minv=INF;
    cin >> v >> e;
    
    vector<vector<int>> city(v+1,vector<int>(v+1,INF));
    vector<bool> visited(v+1);

    for(int i=0;i<e;i++){
        int from,to,cost;
        cin >> from >> to >> cost;
        city[from][to] = cost;
    }
    for(int k=1;k<=v;k++){
        for(int i=1;i<=v;i++){
            for(int j=1;j<=v;j++){
              city[i][j] = min(city[i][j],city[i][k]+city[k][j]);
            }
        }
    }
    for(int i=1;i<=v;i++){
      minv = min(minv,city[i][i]);
    }
    if(minv==INF)
      cout << -1;
    else
      cout << minv;
    return 0;
}