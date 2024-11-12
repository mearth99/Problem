#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>
using namespace std;



void solution() {
    int T;
    cin >> T;
    while (T--) {
        vector<char> arr;
        string str;
        cin >> str;
        for (auto it : str) {
            if(arr.empty())
                arr.push_back(it);
            else if(arr.back() != it)
                arr.push_back(it);
        }
        for (auto it : arr)
            cout << it;
        cout << '\n';
        arr.clear();
        str = "";
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solution();

}