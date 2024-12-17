#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    int visited[10] = {0};
    for(int i=0;i<arr.size();i++){
        if(visited[arr[i]]==0){
            fill_n(visited,10,0);
            answer.push_back(arr[i]);
            visited[arr[i]]++;
        }else
            continue;
    }
    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    cout << "Hello Cpp" << endl;

    return answer;
}