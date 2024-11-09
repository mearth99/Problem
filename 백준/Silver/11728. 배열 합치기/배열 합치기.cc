#include<iostream>
#include<string>
#include<cstring>
#include<map>
#include<vector>
using namespace std;
/*
1. a.end < b.first
 => a에 b를 연결해서 출력하면됨.
2. b.end < a.first
 b에 a를 연결해서 출력하면 됨
3. b.first < a.end || a.first < b.end
 투포인터를 이용하여 번갈아가며 출력하면 됨.
*/

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N,M;
    cin >> N >> M;
    vector<int> A,B;
    for(int i=0;i<N;i++){
        int a;
        cin >> a;
        A.push_back(a);
    }
    for(int i=0;i<M;i++){
        int b;
        cin >> b;
        B.push_back(b);
    }
    int a=0,b=0;
    while(a!=A.size() || b!=B.size()){
        if(a==A.size()){
            cout << B[b] << " ";
            b++;
        }
        else if(b==B.size()){
            cout << A[a] << " ";
            a++;
        }
        else{
            if(A[a]<=B[b]){
                cout << A[a] << " ";
                a++;
            }else{
                cout << B[b] << " ";
                b++;
            }
        }
    }  
}