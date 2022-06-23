#include<stdio.h>

int main(){
    int len;
    scanf("%d", &len);
    int arr[len];

    for (int i=0; i < len; i++){
        scanf("%d", &arr[i]);
    }

    for (int i=(len-1); i >= 0; i--){
        printf("%d ", arr[i]);
    }

    return 0;
}