#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
bool cmp(vector<int> &p1, vector<int> &p2){
    if(p1[0]<p2[0]&&p1[1]<p2[1])
        return true;
    return false;
}
bool cmp2(vector<int> &p1, vector<int> &p2){
    if(p1[0]+p1[1] < p2[0]+p2[1])
        return true;
    return false;
}

int solution(vector<vector<int>> scores) {
    int answer = 0;
    vector<vector<int>> ranks;
    pair<int,int> oneho = {scores[0][0],scores[0][1]};
    //1. 두 점수가 모두 낮은 사원 -> 인센티브를 받지 못함.
    //1.1 두 점수가 모두 높은 사원을 찾는다. , 비교를 통해 솎아낸다.
    //2. 합을 통해 정렬한다.
    //3. 등수를 나열한다. 끝
    sort(scores.begin(),scores.end(),cmp);
    pair<int> target = make_pair(scores[scores.size()-1][0],scores[scores.size()-1][1]);
    for(auto idx: scores){
        if(idx[0]<target.first&&idx[1]<target.second){
            if(idx[0]==oneho.first&&idx[1]==oneho.second)
                return -1;
            continue;
        }else
            ranks.push_back(idx);
    }
    sort(ranks.begin(),ranks.end(),cmp2);
    for(int i=ranks.size()-1,rank=1,count=0;i>=0;i--){
        if(ranks[i][0]==oneho.first&&ranks[i][1]==oneho.second)
            return rank;
        if(ranks[i][0]==ranks[i-1][0]&&ranks[i][1]==ranks[i-1][1]){
            count++;
        }else{
            rank+=count+1;
            count=0;
        }
    }
    return answer;
}