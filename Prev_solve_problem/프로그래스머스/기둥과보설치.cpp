#include <string>
#include <vector>

using namespace std;
/*
  1. 기둥은 바닥 위에 있거나, 보의 한쪽 끝부분 위에 있거나, 다른 기둥 위에 있어야 한다.
  2. 보는 한쪽 끝부분이 기둥 위에 있거나, 또는 양쪽 끝부분이 다른 보와 동시에 연결되어 있어야 한다.
  3. 기둥은 위쪽방향으로 설치, 보는 오른쪽방향으로 설치된다.
*/

//0: 기둥, 1: 보
bool arr[101][101][2];
int arr_size;
bool check_set(int x, int y, int a){
    if(a==0){
        if(y==0) return true;
        if(x>0 && arr[x-1][y][1]) return true;
        if(arr[x][y][1]) return true;
        if(y>0 && arr[x][y-1][0]) return true;
    }else{
        if(y>0 && arr[x][y-1][0]) return true;
        if(x<arr_size && y>0 && arr[x+1][y-1][0]) return true;
        if(x>0 && x<arr_size && arr[x-1][y][1] && arr[x+1][y][1]) return true;
    }
    return false;
}
bool check_remove(int x, int y, int a){
    arr[x][y][a] = false;
    if(a==0){
        if(y<arr_size && arr[x][y+1][0] && !check_set(x,y+1,0)) return false;

        if(y<arr_size && arr[x][y+1][1] && !check_set(x,y+1,1)) return false; 
        if(x>0 && y<arr_size && arr[x-1][y+1][1] && !check_set(x-1,y+1,1)) return false; 
    }else{
        if(arr[x][y][0] && !check_set(x,y,0)) return false;
        if(x<arr_size && arr[x+1][y][0] && !check_set(x+1,y,0)) return false;

        if(x>0 && arr[x-1][y][1] && !check_set(x-1,y,1)) return false;
        if(x<arr_size && arr[x+1][y][1] && !check_set(x+1,y,1)) return false;
    }
    return true;
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;
    arr_size = n;

    for(auto it : build_frame){
      int x = it[0];
      int y = it[1];
      int a = it[2];
      int delete_new = it[3];
      if(delete_new==1){
        if(check_set(x,y,a)) arr[x][y][a] = true;
      }
      else
        if(!check_remove(x,y,a)) arr[x][y][a] = true;
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            if(arr[i][j][0]) answer.push_back({i,j,0});
            if(arr[i][j][1]) answer.push_back({i,j,1});
        }
    }
    return answer;
}