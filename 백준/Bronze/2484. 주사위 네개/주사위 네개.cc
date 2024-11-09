#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
/*
l과 r을 0에서 부터 증가시킨다.
r-l은 현재 대상자의 계단 길이가 된다.
히스토그램 값이 r-l보다 큰지 확인한다.
크다면 ,같다면, r을 증가시킨다.
작다면, l을 증가시킨다.
*/
int roll[7];
int inputs[4];

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N,output=0;
    cin >> N;
    for(int i=0;i<N;i++){
        int two=0, curmax=0;
        memset(roll,0,sizeof(roll));
        for(int j=0;j<4;j++){
            cin >> inputs[j];
            roll[inputs[j]]++;
        }
        for(int j=1;j<7;j++){
            if(roll[j]==4)
                output = max(output,5000*j+50000);
            else if(roll[j]==3)
                output = max(output, 10000+ j*1000);
            else if(roll[j]==2){
                if(two==0)
                    two = j;
                else 
                    output = max(output, 2000+j*500+two*500);
            }
            else if(roll[j]==1)
                curmax = j;
        }
        output = max(output, curmax*100);
        if(two>0)
            output = max(output, 1000+100*two);
    }
    cout << output;
}