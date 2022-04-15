#include <stdio.h>

int main(){

    int num;

    printf("Enter the number - ");
    scanf("%d", &num);

    if (num % 2 == 0){
        printf("\nThe %d is a even number.", num);
    }
    else{
        printf("\nThe %d is a odd number.", num);
    }

    return 0;
}