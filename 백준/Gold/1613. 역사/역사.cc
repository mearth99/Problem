/*
입력
첫째 줄에 첫 줄에 사건의 개수 n(400 이하의 자연수)과 알고 있는 사건의 전후 관계의 개수 k(50,000 이하의 자연수)가 주어진다. 
다음 k줄에는 전후 관계를 알고 있는 두 사건의 번호가 주어진다. 이는 앞에 있는 번호의 사건이 뒤에 있는 번호의 사건보다 먼저 일어났음을 의미한다. 
물론 사건의 전후 관계가 모순인 경우는 없다. 다음에는 사건의 전후 관계를 알고 싶은 사건 쌍의 수 s(50,000 이하의 자연수)이 주어진다. 
다음 s줄에는 각각 서로 다른 두 사건의 번호가 주어진다. 사건의 번호는 1보다 크거나 같고, N보다 작거나 같은 자연수이다.

출력
s줄에 걸쳐 물음에 답한다. 각 줄에 만일 앞에 있는 번호의 사건이 먼저 일어났으면 -1, 
뒤에 있는 번호의 사건이 먼저 일어났으면 1, 어떤지 모르면(유추할 수 없으면) 0을 출력한다.
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
    int n,m,t;
    cin >> n >> m;
    
    vector<vector<int>> city(n+1,vector<int>(n+1));

    for(int i=0;i<m;i++){
        int from,to;
        cin >> from >> to;
        city[from][to] = -1;
        city[to][from] = 1;
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(city[i][j]==0){
                  if(city[i][k]==1&&city[k][j]==1)
                    city[i][j] = 1;
                  else if(city[i][k]==-1&&city[k][j]==-1)
                    city[i][j] = -1;
                }
                
            }
        }
    }
    cin >> t;
    for(int i=1;i<=t;i++){
      int x,y;
      cin >> y >> x;
      cout << city[y][x] << '\n';
    }

    return 0;
}