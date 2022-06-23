#include<stdio.h>

int main(){

    int len;
    long long sum = 0;

    scanf("%d", &len);
    int arr[len];

    for (int i=0; i<len; i++){
        scanf("%d", &arr[i]);
    }

    for (int i=0; i<len; i++){
        sum += arr[i];
    }

    printf("%lld", sum);

    return 0;
}