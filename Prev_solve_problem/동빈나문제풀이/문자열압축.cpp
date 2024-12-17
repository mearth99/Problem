#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int zip(int length, string text){
    //aaaabbabbabb => 문자열을 3개로 자르는게 가장 단축화 한다.
    string output="";
    string pretext = text.substr(0,length);
    string curtext;
    int dup=1;
    for(int i=length;i<text.size();i+=length){
        curtext = text.substr(i,length);
        if(pretext.compare(curtext)==0)
            //문자열을 압축할 수 있다면.
            dup++;
        else{
            if(dup>1) output+= to_string(dup);
            output+= pretext;
            pretext = curtext;
            dup=1;
        }
        
    }
    if(dup>1) output+= to_string(dup);
    output += pretext;
    return output.size();
}
int solution(string s) {
    int answer = s.length();
    for(int i=1;i<=s.length()/2;i++){
        answer = min(answer,zip(i,s));
    }
    
    return answer;
}

int main(){
  string temp;
  cin >> temp;
  cout << solution(temp);
}