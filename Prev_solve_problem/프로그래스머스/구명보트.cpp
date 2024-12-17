#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> people, int limit) {
    //구명보트는 한개당 최대 2명.
    //오름차순으로 정렬한다음, 가장 왼쪽과 오른쪽의 합이 limit가 딱 되는 걸 선택.
    int answer = people.size();
    int left = 0, right = people.size()-1;
    sort(people.begin(),people.end());
    while(left < right){
        if(people[left]+people[right] <=limit){
            answer--;
            left++;
        }
        right--;
    }
    
    return answer;
}