#include <string>
#include <vector>
#include <set>
using namespace std;
int NN(int N,int count){
    int output = N;
    while(--count){
        output *= 10;
        output += N;
    }
    return output;
}

int solution(int N, int number) {
    //N==number ==> 1
    if(N==number) return 1;
    
    set<int> dp[9];
    //1. N 하나로 만들 수 있는 값은 N이다.
    dp[1].insert(N);
    for(int i=2;i<=8;i++){
        dp[i].insert(NN(N,i));
        //set안에 있는 값과 사칙연산을 통해 새로운 값을 만든다.
        for(int j=1;j<=i;j++){
            for(int k=1;k<=i;k++){
                if(j+k!=i) continue;
                    for(auto a : dp[j]){
                        for(auto b : dp[k]){
                            dp[i].insert(a+b);
                            dp[i].insert(a-b);
                            if(b!=0)
                                dp[i].insert(a/b);
                            dp[i].insert(a*b);
                        }
                    }
                }
        }
        if(dp[i].find(number) != dp[i].end()){
            //만일 찾을 수 있다면.
            return i;
        }
    }

    return -1;
}