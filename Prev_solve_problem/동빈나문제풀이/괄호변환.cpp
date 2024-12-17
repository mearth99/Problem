#include <string>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;

bool correct(string text){
    stack<char> s;
    for(int i=0;i<text.length();i++){
        if(text.at(i)=='(') s.push('(');
        else{
            if(s.top() == '(') s.pop();
            else s.push(')');
        }
    }
    if(!s.empty()) return false;
    return true;
}

string solution(string p) {
    string answer = "";
    int left = 0;
    int right = 0;
    string u,v;
    for(int i=0;i<p.length();i++){
        if(p.at(i)=='(') left++;
        if(p.at(i)==')') right++;

        if(left==right){
            u=p.substr(0,i+1);
            v=p.substr(i+1);
            break;
        } 
    }
    if(correct(u)){
        v=solution(v);
        answer= u+v;
        return answer;
    }
    else{
        answer = "(";
        answer += solution(v);
        answer += ")";
        u = u.substr(1,u.length()-1);
        for(int i=0;i<u.length();i++){
            if(u.at(i)=='(') answer += ')';
            else answer += '(';
        }
        return answer;
    }
}