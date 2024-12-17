//17298 오큰수

/*
 Ai의 오큰수는 오른쪽에 있으면서 Ai보다 큰 수 중에서 가장 왼쪽에 있는 수를 의미한다. 그러한 수가 없는 경우에 오큰수는 -1이다.
*/

/* 입력
첫째 줄에 수열 A의 크기 N (1 ≤ N ≤ 1,000,000)이 주어진다. 둘째 줄에 수열 A의 원소 A1, A2, ..., AN (1 ≤ Ai ≤ 1,000,000)이 주어진다.
*/

/* 출력
총 N개의 수 NGE(1), NGE(2), ..., NGE(N)을 공백으로 구분해 출력한다.

*/

/* 예상
자기자신보다 크면서 우측 중 가장 왼쪽에 있어야한다. 가짓수를 여러개로 나눠보자.

우측에서 부터 계산한다면?

*/
/* 결과
우측에서 계산한다면 술술풀렸던 문제다. 다만 계산결과가 1초이내가 되어야하기 때문에, buff를 계속 비워가면서 체크해줘야한다.
왼쪽에서 계산한다면 아주 어렵게 생각되지만, 오른쪽 부터 계산한다면 간단한 코드로 만들 수 있었다.
*/
#include <iostream>
#include <vector>
using namespace std;

int values[1000001];
int NGE[1000001];
bool flag;
vector<int> buff;

int main()
{
    int N;
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> values[i];
        NGE[i] = values[i];
    }
    values[N-1] = -1;
    buff.push_back(NGE[N-1]);
    for(int i=N-2;i>=0;i--){
        while(!buff.empty()){
            if(buff[buff.size()-1]<=NGE[i]){
                buff.pop_back();
            }
            else{
                values[i] = buff[buff.size()-1];
                buff.push_back(NGE[i]);
                break;
            }
        }
        if(buff.empty()){
            values[i] = -1;
            buff.push_back(NGE[i]);
        }
    }
    for(int i=0;i<N;i++){
        cout << values[i] << " ";
    }
}