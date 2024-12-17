#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
bool cmp(vector<int>& p1,vector<int>& p2){
  return p1[1] < p2[1];
}

int solution(vector<vector<int>> routes) {
    /*
    routes[i][0]으로 정렬하되(오름차순) 카메라의 위치는 routes[i][1]로 둔다.
    1. 카메라의 위치를 계속 확인하면서, 카메라로 커버하지 못할 경우 새로운 카메라를 설치한다. 새로운 카메라는 가능한 범위내에 가장 높은 값!
    */
    int answer = 0;
    int camera = -30001;
    sort(routes.begin(),routes.end(),cmp);
    for(int i=0;i<routes.size();i++){
      if(camera<routes[i][0]){
        //카메라가 커버가 불가능한 지금 새로운 카메라를 설치한다. (최대한 멀리)
        camera = routes[i][1];
        answer++;
      }
    }
    return answer;
}