#include <stdio.h>

int main(){

    int counter;
    double sum;
    double num1, num2;

    scanf("%d", &counter);

    for (int itr=0; itr < counter; itr++){
        scanf("%lf %lf", &num1, &num2);
        sum += num1 * num2;
    }

    printf("%.3lf", sum);

    return 0;
}