#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int grade[3] = {0};
    int patterns[3] = {1,2,1};
    int patterns3[5] = {3,1,2,4,5};
    for(int i=0,i3=0;i<answers.size();i++){
        //패턴 초기화
        if(patterns[0]>5)
            patterns[0] = 1;
        if(patterns[2]==2)
            patterns[2]++;
        if(patterns[2]>5)
            patterns[2]=1;
        if(i3>4)
            i3=0;
        //비교
        if(patterns[0]==answers[i])
            grade[0]++;
        if(patterns[1]==answers[i])
            grade[1]++;
        if(patterns3[i3]==answers[i])
            grade[2]++;
        //증감
        patterns[0]++;
        if(patterns[1]==2){
            patterns[1] = patterns[2];
            patterns[2]++;
        }
        else
            patterns[1] = 2;
        if(i%2!=0)
            i3++;
        
    }
    int max_v = max({grade[0],grade[1],grade[2]});
    for(int i=0;i<3;i++){
      if(max_v==grade[i])
        answer.push_back(grade[i]);
    } 
    return answer;
}