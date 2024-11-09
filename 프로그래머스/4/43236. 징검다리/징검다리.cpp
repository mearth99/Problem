#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool check(vector<int> rocks , int v, int remove_limit){
    int prev = 0, remove = 0;
    for(int i=0;i<rocks.size();i++){
        if(rocks[i]-prev>=v) prev = rocks[i];
        else remove++;
    }
    if(remove<=remove_limit) return true;
    else return false;
}

int solution(int distance, vector<int> rocks, int n) {
    int start = 0, end = distance, mid=0,answer = 0;
    sort(rocks.begin(),rocks.end());
    rocks.push_back(distance);
    while(start<=end){
        mid = (start + end) / 2;
        if(check(rocks, mid, n)){
            start = mid + 1;
            answer = max(answer,mid);
        }
        else end = mid -1; 
    }
    return answer;
}