#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main(){
  vector<vector<int>> maps(500, vector<int> (500));
  vector<vector<int>> rota(500, vector<int> (500));
  for(int i=0;i<500;i++){
    for(int j=0;j<500;j++)
      rota[i][j] = maps[500-j-1][i];
  }
}