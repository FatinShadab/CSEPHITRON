#include <stdio.h>

int main(){

    float celsius;

    printf("Enter temperature in Celsius - ");
    scanf("%f", &celsius);

    printf("\nTemperature in Fahrenheit - %.1f F", (((celsius*9)/5)+32));

    return 0;
}