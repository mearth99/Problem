#include <string>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
int DP[1001][1001];
vector<char> s;
int main(){
    string s1, s2;
    cin >> s1;
    cin >> s2;
    for(int i=1;i<=s1.length();i++){
        for(int j=1;j<=s2.length();j++){
            if(s1[i-1]==s2[j-1]){
                DP[i][j] = DP[i-1][j-1] + 1; 
            }else{
                if(DP[i-1][j]>=DP[i][j-1])
                    DP[i][j] = DP[i-1][j];
                else
                    DP[i][j] = DP[i][j-1];
            }
        }
    }
    int i = s1.length();
    int j = s2.length();
    while(i!=0&&j!=0){   
        if(DP[i][j]==DP[i-1][j])
            i--;
        else if(DP[i][j]==DP[i][j-1]) 
            j--;
        else{
            s.push_back(s1[i-1]);
            i--;
            j--;
        }
    }
    cout << DP[s1.length()][s2.length()] << '\n';
    for(int i=s.size()-1;i>=0;i--)
        cout << s[i];
    return 0;
}
