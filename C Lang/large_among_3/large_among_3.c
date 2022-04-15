#include <stdio.h>

int main(){

    int num1, num2, num3;

    printf("Enter the three number separated by space -");
    scanf("%d %d %d", &num1, &num2, &num3);

    if (num1 > num2){
        if (num1 > num3){
            printf("%d is large among %d, %d", num1, num2, num3);
        }
        else{
            printf("%d is large among %d, %d", num3, num1, num2);
        }
    }
    else{
        if (num2 > num3){
            printf("%d is large among %d, %d", num2, num1, num3);
        }
        else{
            printf("%d is large among %d, %d", num3, num1, num2);
        }
    }

    return 0;
}