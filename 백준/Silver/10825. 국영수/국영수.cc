#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

struct student{
    string name;
    int korean;
    int english;
    int math;
    
};
student make_student(string name, int korean, int english, int math){
    student temp;
        temp.name = name;
        temp.korean = korean;
        temp.english = english;
        temp.math = math;
    return temp;
}
bool cmp(student &p1, student &p2){
    if(p1.korean==p2.korean){
        if(p1.english==p2.english){
            if(p1.math==p2.math){
                return p1.name < p2.name;
            }else
                return p1.math > p2.math;
        }else
            return p1.english < p2.english;

    }else
        return p1.korean > p2.korean;
}

int main(){
    int n;
    cin >> n;
    vector<student> school(n);
    for(int i=0;i<n;i++){
        string name;
        int korean, english, math;
        cin >> name >> korean >> english >> math;
        school.push_back(make_student(name, korean, english, math));
    }
    sort(school.begin(),school.end(),cmp);
    for(int i=0;i<n;i++)
        cout << school[i].name << '\n';
    return 0;
}