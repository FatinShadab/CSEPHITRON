#include <stdio.h>

int main(){

    int workHr, salaryPerHr;

    printf("Enter total work hr (int) - ");
    scanf("%d", &workHr);

    printf("Enter salary per hour (int) - ");
    scanf("%d", &salaryPerHr);

    printf("\nSalary = %d", workHr*salaryPerHr);

    return 0;
}