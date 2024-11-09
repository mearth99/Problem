#include <stdio.h>

int main(void) {
    int n, k;
    int arr[201][201];
    scanf("%d %d", &n, &k);
    arr[1][1] = 1;
    for(int i = 2; i < 201; i++) {
        arr[i][1] = 1;
        arr[1][i] = i;
    }
    for(int i = 2; i <= n; i++) {
        for(int j = 2; j <= k; j++) {
            arr[i][j] = (arr[i - 1][j] + arr[i][j - 1]) % 1000000000; 
        }
    }
    printf("%d", arr[n][k]);
}