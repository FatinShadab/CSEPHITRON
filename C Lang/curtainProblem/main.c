#include <stdio.h>

int main(){

    int a, b, res;

    scanf("%d %d", &a, &b);

    res = a - (b*2);

    if (res < 0){
        res = 0;
        printf("%d", res);
    }
    else{
        printf("%d", res);
    }

    return 0;
}