/*
입력
첫째 줄에 도시의 개수 n이 주어지고 둘째 줄에는 버스의 개수 m이 주어진다. 그리고 셋째 줄부터 m+2줄까지 다음과 같은 버스의 정보가 주어진다. 
먼저 처음에는 그 버스의 출발 도시의 번호가 주어진다. 버스의 정보는 버스의 시작 도시 a, 도착 도시 b, 한 번 타는데 필요한 비용 c로 이루어져 있다. 
시작 도시와 도착 도시가 같은 경우는 없다. 비용은 100,000보다 작거나 같은 자연수이다.
시작 도시와 도착 도시를 연결하는 노선은 하나가 아닐 수 있다.
출력
n개의 줄을 출력해야 한다. i번째 줄에 출력하는 j번째 숫자는 도시 i에서 j로 가는데 필요한 최소 비용이다. 만약, i에서 j로 갈 수 없는 경우에는 그 자리에 0을 출력한다.
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define INF 20000000

int main()
{
    int n,m;
    cin >> n >> m;
    
    vector<vector<int>> city(n+1,vector<int>(n+1,INF));
    for(int i=1;i<=n;i++)
        city[i][i] = 0;
    for(int i=0;i<m;i++){
        int go,dest,pay;
        cin >> go >> dest >> pay;
        city[go][dest] = min(pay,city[go][dest]);
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                city[i][j] = min(city[i][j], city[i][k]+city[k][j]);
            }
    }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(city[i][j]==INF)
                cout << 0 << " ";
            else
               cout << city[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}