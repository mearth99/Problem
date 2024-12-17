#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer(2);
    //1. 겉의 갯수 구하기: 가로*2 + 세로*2 -4 (브라운 이용)
    //2. 속의 갯수 구하기: 가로와 세로의 경우의 수를 구해서 전체의 수를 구하기. (브라운과 엘로우 이용)
    vector<pair<int,int>> cans;
    for(int i=1;i<=brown;i++){
        for(int j=1;j<=i;j++){
            if(i*2+j*2-4==brown)
                cans.push_back(make_pair(i,j));
        }
    }
    for(int i=0;i<cans.size();i++){
        if(cans[i].first*cans[i].second == brown+yellow){
            answer[0] = cans[i].first;
            answer[1] = cans[i].second;
            break;
        }
    }
    return answer;
}