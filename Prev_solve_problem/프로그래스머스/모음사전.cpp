#include <string>
#include <vector>

using namespace std;
char alpabet[5] = {'A','E','I','O','U'};
int value[5] = {781, 156, 31, 6, 1};

int solution(string word) {
    int answer = 0;
    for(int i=0;i<word.size();i++)
        for(int j=0;j<5;j++){
            if(word[i]==alpabet[j])
                answer += 1 + value[i]*j;
        }
    return answer;
}