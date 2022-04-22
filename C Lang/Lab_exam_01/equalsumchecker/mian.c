#include <stdio.h>

int main(){
    
    int sum;
    int a, b;

    scanf("%d %d", &a, &b);

    sum = a + b;

    if (sum >= 10){
        printf("error");
    }
    else{
        printf("%d", sum);
    }

    return 0;
}