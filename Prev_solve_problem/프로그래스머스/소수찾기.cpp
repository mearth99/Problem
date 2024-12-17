#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <iostream>
using namespace std;
bool visit[7] = {0};
bool prime[10000000] = {0};
set<int> canmake;
string make;
void dfs(int count,string numbers, int sizes){
    if(count == sizes){
        canmake.insert(stoi(make));
        return;
    }
    for (int i = 0; i < numbers.size(); i++) {
        if (!visit[i]) {
            visit[i] = true;
            make.push_back(numbers.at(i));
            dfs(count + 1, numbers, sizes);
            visit[i] = false;
            make.pop_back();
        }
    }
}
int solution(string numbers) {
    int answer = 0;
    for (int i = 2; i <= 9999999; i++)
    {
        // prime[i] 가 1이면 이미 소수가 아니므로 continue
        if (prime[i] == 1)
            continue;
        // i*k (k<i) 까지의 수는 이미 검사했으므로 j는 i*i 부터 검사해준다.
        for (int j = i * i; j <= 9999999; j += i)
            prime[j] = 1;
    }
    prime[0] = prime[1] = 1;
    for(int i=1;i<=numbers.size();i++){
        dfs(0,numbers,i);
    }
    for(auto& v : canmake){
        if(prime[v]==0)
            answer++;
    }
    
    return answer;
}