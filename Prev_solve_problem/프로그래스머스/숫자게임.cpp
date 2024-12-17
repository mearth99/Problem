#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    int a=0,b=0;
    while(a<A.size()&&b<A.size()){
        if(A[a]<B[b]){
            answer++;
            b++;
            a++;
        }else
            b++;
    }
    return answer;
}