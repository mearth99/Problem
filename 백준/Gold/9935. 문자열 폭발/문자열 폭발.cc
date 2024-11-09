//9935 문자열폭팔

/* 입력
첫째 줄에 문자열이 주어진다. 문자열의 길이는 1보다 크거나 같고, 1,000,000보다 작거나 같다.

둘째 줄에 폭발 문자열이 주어진다. 길이는 1보다 크거나 같고, 36보다 작거나 같다.

두 문자열은 모두 알파벳 소문자와 대문자, 숫자 0, 1, ..., 9로만 이루어져 있다.
*/

/* 출력
첫째 줄에 모든 폭발이 끝난 후 남은 문자열을 출력한다.
*/

/* 예상
찾는건 strstr로 할 수 있으나, 연쇄폭팔이 발생할 수 있으니 한번의 탐색에서 해결해야한다. 폭팔가능한 문자열의 길이를 구할 수 있기 때문에, 최대 탐색거리를 구할 수 있다.

strstr로 처음 찾는 위치를 반환한다면, 이에 따라 연속하여 탐색한다.
즉, strstr로 전체에서 찾고 문자를 폭팔시키고, 폭팔 위치의 이전 36 이후 36범위로 좁게 잡고 계속 폭팔 시킨다.
*/
/* 결과
굳이 범위로 잡지 않고, 백터를 이용해 백터 공간에서 계속 폭팔시켰다.
*/
#include <iostream>
#include <vector>

using namespace std;

vector<char> buff;
string input, bomb;
bool flag;
int main()
{
    cin >> input >> bomb;
    int input_size = input.size();
    int bomb_size = bomb.size();

    for(int i=0;i<input_size;i++){
        buff.push_back(input[i]);
        if(buff.size()>=bomb_size){ //만일 백터에 들어간 size가 bomb_size보다 크면, 탐색을 실행한다.
            flag=true;
            for(int i=0;i<bomb_size;i++){
                if(buff[buff.size()-bomb_size+i] != bomb[i]){
                    flag = false;
                    break;
                }
            }
            if(flag){ //만일 문자열이 일치하여 폭팔해야한다면,
                for(int i=0;i<bomb_size;i++){
                    buff.pop_back();
                }
            }
        }
    }
    if(buff.empty()){
        cout << "FRULA";
    }else{
        for(int i=0;i<buff.size();i++){
            cout << buff[i];
        }
    }
    return 0;
}