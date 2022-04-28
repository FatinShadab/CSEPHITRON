#include <stdio.h>

int main(){

    int def;
    int a, b;
    int res = 1;

    scanf("%d %d", &a, &b);

    if (a == b){
        printf("%d", res);
    }
    else{
        def = a - b;
        for (int i = 0; i < def; i++){
            res *= 32;
        }
        printf("%d", res);
    }

    return 0;
}