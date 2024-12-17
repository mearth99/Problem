
#include <iostream>
#include <vector>
#include<string>
#include <algorithm>
#include <cmath>
using namespace std;



int main()
{
    int N,M,output=0, output2=0;
    cin >> N >> M;
    vector<int> MAN(N);
    vector<int> WOMAN(M);
    int visited[1001] = {0};
    int visited2[1001] = {0};
    for(int i=0;i<N;i++)
        cin >> MAN[i];
    for(int i=0;i<M;i++)
        cin >> WOMAN[i];
    sort(MAN.begin(),MAN.end());
    sort(WOMAN.begin(),WOMAN.end());
    for(int i=0;i<N;i++){
        int feel_gap = 1000001;
        int woman_number = -1;
        for(int j=0;j<M;j++){
            if(visited[j]) continue;
            feel_gap = min(feel_gap, abs(MAN[i]-WOMAN[j]));
            woman_number = j;
        }
        if(woman_number==-1) continue;
        visited[woman_number] = 1;
        output += feel_gap;
    }
    for(int i=0;i<M;i++){
        int feel_gap = 1000001;
        int woman_number = -1;
        for(int j=0;j<N;j++){
            if(visited2[j]) continue;
            feel_gap = min(feel_gap, abs(MAN[j]-WOMAN[i]));
            woman_number = j;
        }
        if(woman_number==-1) continue;
        visited2[woman_number] = 1;
        output2 += feel_gap;
    }
    cout << min(output2,output);
    return 0;
}