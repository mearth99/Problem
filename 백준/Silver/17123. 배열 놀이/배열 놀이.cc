
/*
입력
첫 줄에 테스트 케이스의 수 T가 주어진다 (1 <= T <= 10).
각 테스트 케이스에 대하여: 첫 줄에 두 개의 정수 N과 M이 공백으로 구분되어 주어진다 (1 <= N <= 1,000 과 1 <= M <= 1,000 을 만족한다).
다음 N줄에 걸쳐서 2차원 배열 A가 주어지는데, i-번째 줄이 i-번째 행을 나타낸다. 각 줄의 j번째 정수는 j-번째 열의 원소 값을 나타낸다. 배열 A의 각 원소의 값은 1이상 1,000 이하의 정수이다.
다음 M줄에 걸쳐서 각 줄에 다섯 개의 정수 r1, c1, r2, c2, v가 공백으로 구분되어 주어진다. 항상 1 <= r1 <= r2 <= N 그리고 1 <= c1 <= c2 <= N 그리고 -1,000 <= v <= 1,000 을 만족한다. 

출력
각 테스트 케이스에 대해 두 줄에 걸쳐서 정답을 출력해야 한다.
두 줄 중 첫 줄에는 N개의 정수로 표현된 각 행의 합을 공백으로 구분하여 출력하고 (1번 행 부터 N번 행 까지)
둘째 줄에는 N개의 정수로 표현된 각 열의 합을 공백으로 구분하여 출력한다 (1번 열 부터 N번 열 까지).
*/
#include <vector>
#include <iostream>
using namespace std;
void print(vector<vector<int>> base,vector<vector<int>> add){
  for(int i=0;i<base.size()-1;i++){
    int pv=0;
    for(int j=0;j<base.size()-1;j++){
      pv+=base[i][j]+add[i][j];
    }
    cout << pv <<" ";
  }
  cout << endl;
  for(int i=0;i<base.size()-1;i++){
    int pv=0;
    for(int j=0;j<base.size()-1;j++){
      pv+=base[j][i]+add[j][i];
    }
    cout << pv <<" ";
  }
  cout << endl;
  return;
}

int main()
{
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int T,n,m;
  int y1,y2,x1,x2,v;
  cin >> T;
  while(T>0){
    cin >> n >> m;
    vector<vector<int>> A(n+1,vector<int>(n+1));
    vector<vector<int>> Sum(n+1,vector<int>(n+1));
    for(int i=0;i<n;i++)
      for(int j=0;j<n;j++)
        cin >> A[i][j];
    for(int k=0;k<m;k++){
      cin >> y1 >> x1 >> y2 >> x2 >> v;
      Sum[y1-1][x1-1] += v;
      Sum[y2][x1-1] += -1*v;
      Sum[y1-1][x2] += -1*v;
      Sum[y2][x2] += v;
    }
    for(int i=1;i<n;i++){
      for(int j=0;j<n;j++)
        Sum[i][j] += Sum[i-1][j];
    }
    for(int i=0;i<n;i++){
      for(int j=1;j<n;j++)
        Sum[i][j] += Sum[i][j-1];
    }
    print(A,Sum);
    T--;
  }
  return 0;
}