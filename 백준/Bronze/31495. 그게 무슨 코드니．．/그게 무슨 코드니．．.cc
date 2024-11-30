#include<iostream>
#include<map>
#include<unordered_map>
#include<string>
using namespace std;



void solution() {
    string str;
    getline(cin, str);
    if (str.length() > 2 && str.front() == '\"' && str.back() == '\"') {
        for (int i = 1; i < str.length() - 1; i++) {
            cout << str[i];
        }
    }
    else {
        cout << "CE";
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solution();

}