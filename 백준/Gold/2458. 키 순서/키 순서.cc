/*
입력
첫째 줄에 학생들의 수 N (2 ≤ N ≤ 500)과 두 학생 키를 비교한 횟수 M (0 ≤ M ≤ N(N-1)/2)이 주어진다.
다음 M개의 각 줄에는 두 학생의 키를 비교한 결과를 나타내는 N보다 작거나 같은 서로 다른 양의 정수 a와 b가 주어진다. 
이는 번호가 a인 학생이 번호가 b인 학생보다 키가 작은 것을 의미한다.
출력
자신이 키가 몇 번째인지 알 수 있는 학생이 모두 몇 명인지를 출력한다.

시도
단방향 관계로 1을 설정하고, 플로이드 와샬을 돌린 뒤, 각 열에 대한 합계를 구한 값이 n-1인 개수를 구한다.
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m,answer=0;
    cin >> n >> m;
    vector<vector<int>> student(n+1, vector<int>(n+1,0));
    for(int i=0;i<m;i++){
      int small,tall;
      cin >> small >> tall;
      student[small][tall] = 1; //숫자가 1이면 i가 j보다 작다.
      student[tall][small] = -1; //숫자가 -1이면 i가 j보다 크다.
    }
    for(int k=1;k<=n;k++)
      for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++){
          if(student[i][j]==0)
            if(student[i][k]==1&&student[k][j]==1) // k가 j보다 작고, 동시에 i가 k보다 작으면, i는 j보다 작다.
              student[i][j] = 1;
            else if(student[i][k]==-1&&student[k][j]==-1)
              student[i][j] = -1;
        }
    for(int i=0;i<=n;i++){
      int count =0;
      for(int j=0;j<=n;j++){
        if(student[i][j]==1 || student[i][j]==-1)
          count++;
      }
      if(count == n-1)
        answer++;
    }
    cout << answer;
    return 0;
}