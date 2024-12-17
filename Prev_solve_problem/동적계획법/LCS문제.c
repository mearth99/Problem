/*
LCS(Longest Common Subsequence, 최장 공통 부분 수열)문제는 두 수열이 주어졌을 때, 모두의 부분 수열이 되는 수열 중 가장 긴 것을 찾는 문제이다.

예를 들어, ACAYKP와 CAPCAK의 LCS는 ACAK가 된다.
첫째 줄과 둘째 줄에 두 문자열이 주어진다. 문자열은 알파벳 대문자로만 이루어져 있으며, 최대 1000글자로 이루어져 있다.
첫째 줄에 입력으로 주어진 두 문자열의 LCS의 길이를 출력한다.
*/
#include <stdio.h>
#include <string.h>

int max(int a,int b)
{
    return a>b? a:b;
}
int main()
{
    //선언부
     
    char A[1001];
    char B[1001];
    int D[1001][1001]={0};
    int A_len,B_len;
    scanf("%s",A+1);
    scanf("%s",B+1);
 
    A_len = strlen(A+1);
    B_len = strlen(B+1);
    //실행부
    for(int i=0;i<=A_len;i++)
    {
        for(int j=0;j<=B_len;j++)
        {
            if(i==0 || j==0)
            {
                D[i][j] = 0;
            }
            else if (A[i]==B[j])
            {
                D[i][j]=D[i-1][j-1] +1;
            }
            else
            {
                D[i][j] = max(D[i-1][j],D[i][j-1]);
            }
        }
    }

    printf("%d ",D[A_len][B_len]);

    return 0;
    //후기. LCS 알고리즘을 그대로 사용하는 것이라 알고리즘 자체에 어려움은 없었지만,
    //우째서인지 Vscode C언어로 사용시 int [1000][1000] 부터 에러가 생긴다.. 뭔 문제일까
    //마지막으로 바보같이 1000을 그대로 사용하여 범위 벗어나는 문제 발생해서 1001로 수정함.

}