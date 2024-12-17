#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int time = 0;
    int now_weight = 0;
    queue<int> wait;
    for(int i=0;i<truck_weights.size();i){
        //트럭의 진입
        if(now_weight+truck_weights[i]>weight){
            //현재 트럭 무게가 너무 무거워서, 더 이상 탑승하지 못하고 기다려야함. 따라서 아무도 안탔다는 0을 넣음.
            wait.push(0);
        }else{
            //트럭이 들어갈 수 있을 정도로 다리가 괜찮음.
            wait.push(truck_weights[i]);
            now_weight+=truck_weights[i];
            i++;
        }
        //트럭의 출입
        if(wait.size()==bridge_length){
            now_weight-=wait.front();
            wait.pop();
        }
        time++;
        
    }
    wait.push(-1);
    while(wait.front()!=-1){
        if(wait.size()==bridge_length)
            wait.pop();
        wait.push(0);
        time++;
    }
    return time+1;
}