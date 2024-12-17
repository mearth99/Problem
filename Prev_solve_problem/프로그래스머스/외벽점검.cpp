#include <string>
#include <vector>
#include <algorithm>
using namespace std;
void check_node(int start, int count, vector<bool> &node){
    int current = start;
    while(count!=0){
        if(node[current]){
            current++;
        }else{
            node[current] = true;
            count--;
            current++;
        }
        if(current==node.size())
            current = 0;
    }
}

int solution(int n, vector<int> weak, vector<int> dist) {
    int answer = 0;
    int all_check_weak = 0;
    sort(dist.begin(),dist.end(),greater<>());
    vector<bool> node(weak.size());
    for(auto man : dist){
        int man_check_weak = 0;
        int start_weak = -1;
        for(int i=0;i<weak.size();i++){
            if(node[i]) continue;
            int weak_count = 0;
            for(int j=0;j<weak.size();j++){
                if(node[j]) continue;
                if(weak[i]+man>=n){
                    if(weak[i]<=weak[j] && weak[j] < n || weak[j]<=(weak[i]+man)%n)
                        weak_count++;
                }else{
                    if(weak[i]<=weak[j] && weak[j]<=weak[i]+man)
                        weak_count++;
                }
            }
            if(man_check_weak<weak_count){
                man_check_weak = weak_count;
                start_weak = i;
            }
        }
        //현시점: man이 가장 많은 취약점을 탐색하는 최적의 위치를 찾음.
        //i에서 부터 weak_count번째까지 취약점을 담당함.
        //방문처리하면 될거같기도.. 또는 새로운 vector 만들어서 넘겨줘도됨.
        all_check_weak += man_check_weak;
        if(all_check_weak==weak.size()) return answer+1;
        answer++;
        check_node(start_weak,man_check_weak,node);
    }
    
    return -1;
}