#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool check(vector<int> rocks , int v, int remove_limit){
    int prev = rocks[0];
    int remove = 0;
    for(int i=1;i<rocks.size();i++){
        if(rocks[i]-prev<v){
            //최솟값이 더 크기 때문에, 돌을 제거해야하며, 이때 prev는 변하지 않는다.
            remove++;
        }else{
            //돌 사이 거리가 최솟값보다 크기 때문에 돌을 제거할 필요가 없고, prev는 변한다.
            prev = rocks[i];
        }
    } //만약, remove가 제한보다 작거나 같은 경우, 이는 최솟값을 높여서 도전해봐도 된다는 소리다.
    if(remove<=remove_limit) return true;
    else return false;
}

int solution(int distance, vector<int> rocks, int n) {
    int start = 0, end = distance, mid;
    sort(rocks.begin(),rocks.end());

    while(start<=end){
        mid = (start + end) / 2;
        if(check(rocks, mid, n))
            start = mid + 1;
        else
            end = mid -1;
    }
    return mid;
}