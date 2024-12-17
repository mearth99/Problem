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

*/
void mini_booms();
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char text[1000001];
char boom[37];
int main()
{
    int text_length;
    int boom_length;
    //선언 및 입력부
    scanf("%s",text);
    scanf("%s",boom);
    text_length = strlen(text);
    boom_length = strlen(boom);
    char *compare = strstr(text,boom);
    while(compare!=NULL){
        char temp[1000001];
        int compare_length = strlen(compare);
        int index  = text_length-compare_length; //C4의 시작지점
        strncat(temp,text,index);
        strcat(temp,compare+boom_length); //mirkovC4nizCC44 -> mirkonizCC44, index-> n C4를 제거하여 이제 n이 시작지점이 됨
        if(index<37)
   }

    return 0;
}