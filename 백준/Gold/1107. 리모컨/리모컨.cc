
#include <iostream>
#include <vector>
#include<string>
#include <algorithm>
#include <cmath>
using namespace std;

int normal[10];
int N,M,max_count;

int check(string v){
    for(auto it : v){
        if(normal[it-'0']==0) return 0;
    }
    return 1;
}

int main()
{
    fill_n(normal,10,1);
    cin >> N >> M;

    max_count = abs(N-100);
    for(int i=0;i<M;i++){
        int error_botton;
        cin >> error_botton;
        normal[error_botton] = 0;
    }
    // 모든 경우의 수를 탐색하는 것이 빠를 것이다. 즉, 가능한 숫자가 되는지 확인하고
    // 이 숫자를 만드는 숫자버튼의 횟수를 확인한다.
    for(int i=0;i<=1000000;i++){
        string v = to_string(i);
        if(check(v)){
            //이 숫자 가 가능하다
            int count = v.size() + abs(N-i);
            max_count = min(max_count, count);
        }
    }
    cout << max_count;
    return 0;
}