#include <stdio.h>
#include <math.h>

int main(){

    int num1, num2;

    printf("Enter the 1st number - ");
    scanf("%d", &num1);

    printf("\nEnter the 2nd number - ");
    scanf("%d", &num2);

    printf("\nSum = %d", num1 + num2);
    printf("\nDifference = %d", num1 - num2);
    printf("\nProduct = %d", num1 * num2);
    printf("\nQuotient = %d", num1 / num2);
    printf("\nModulus = %d", num1 % num2);

    return 0;
}