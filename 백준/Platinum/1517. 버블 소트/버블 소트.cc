#include <bits/stdc++.h>
using namespace std;
#define MAX 500001
long long arr[MAX];
long long sort_arr[MAX];
long long cnt = 0;
void merge_sort(int left, int mid, int right){
    int i, j, k, l;
    i = left;
    j = mid+1;
    k = left;
    while(i <= mid && j <= right){
        if(arr[i] <=arr[j])
            sort_arr[k++] = arr[i++];
        else{
            sort_arr[k++] = arr[j++];
            cnt += j-k;
        }
    }
    int tmp = i>mid ? j: i;
    while(k<=right) sort_arr[k++] = arr[tmp++];
    for(int a = left; a<=right; a++) arr[a] = sort_arr[a];
}

void merge(int left, int right){
    int mid = (left + right)/2;
    if(left < right){
        merge(left, mid);
        merge(mid+1,right);
        merge_sort(left, mid, right);
    }
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    for(int i=0;i<N;i++)
        cin >> arr[i];

    merge(0,N-1);
    cout << cnt;
    
    return 0;
}