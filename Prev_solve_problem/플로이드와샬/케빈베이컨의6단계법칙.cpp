/*
입력
첫째 줄에 유저의 수 N (2 ≤ N ≤ 100)과 친구 관계의 수 M (1 ≤ M ≤ 5,000)이 주어진다. 
둘째 줄부터 M개의 줄에는 친구 관계가 주어진다. 친구 관계는 A와 B로 이루어져 있으며, A와 B가 친구라는 뜻이다.
A와 B가 친구이면, B와 A도 친구이며, A와 B가 같은 경우는 없다. 친구 관계는 중복되어 들어올 수도 있으며, 친구가 한 명도 없는 사람은 없다. 
또, 모든 사람은 친구 관계로 연결되어져 있다. 사람의 번호는 1부터 N까지이며, 두 사람이 같은 번호를 갖는 경우는 없다.

출력
첫째 줄에 BOJ의 유저 중에서 케빈 베이컨의 수가 가장 작은 사람을 출력한다. 그런 사람이 여러 명일 경우에는 번호가 가장 작은 사람을 출력한다.
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define INF 20000000

int main()
{
    int n,m,value=INF,answer=0;
    cin >> n >> m;
    
    vector<vector<int>> city(n+1,vector<int>(n+1,INF));
    for(int i=1;i<=n;i++)
        city[i][i] = 0;
    for(int i=0;i<m;i++){
        int from,to;
        cin >> from >> to;
        city[from][to] = 1;
        city[to][from] = 1;
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                city[i][j] = min(city[i][j], city[i][k]+city[k][j]);
            }
        }
    }
    for(int i=1;i<=n;i++){
      int sum=0;
      for(int j=1;j<=n;j++){
        sum+=city[i][j];
      }
      if(value>sum){
        answer = i;
        value = sum;
      }
    }
    cout << answer;
    return 0;
}