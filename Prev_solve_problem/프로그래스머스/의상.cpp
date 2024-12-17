#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    //수학적 계산을 하기에 앞서, 여러가지 의상의 종류가 있을 탠대, 이를 구분하여 각기 다른 종류의 의상 갯수를 세어야한다.
    //type = clothes[i][1]에 존재하며, clothes[i][0]은 의상의 이름이다.
    //1을 통해 종류를 구분하면서 의상의 갯수를 추가하는 식으로 관리해야한다.
    //vector을 통해 string 종류를 추가시키는데, 추가시키기 전에 먼저 타입을 확인한다. 타입이 같으면 추가하지 않는다.
    //타입이 같은 경우, 대신 의상의 갯수를 증가시킨다.
    vector<string> clothes_type;
    int clothes_count[31] = {0};
    for(int i=0;i<clothes.size();i++){
        int flag = 0;
        for(int j=0;j<clothes_type.size();j++){
            if(clothes[i][1].compare(clothes_type[j])==0){
                flag = 1;
                clothes_count[j]++;
            }
        }
        if(flag==0){
            clothes_type.push_back(clothes[i][1]);
            clothes_count[clothes_type.size()-1]++;
        }
    }
    for(int i=0;i<clothes_type.size();i++){
        answer *= (clothes_count[i]+1); 
    }
    
    return answer-1;
    
}