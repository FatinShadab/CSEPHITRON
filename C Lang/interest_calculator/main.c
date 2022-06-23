#include <stdio.h>

int main(){

    int principle, year;
    double rate;

    printf("Enter principle - ");
    scanf("%d", &principle);

    printf("Enter year - ");
    scanf("%d", &year);

    printf("Enter rate - ");
    scanf("%lf", &rate);

    printf("\nSimple Interest = %lf", (principle * year * rate)/100);
    printf("\nPrincipal + Interest = %lf", ((principle * year * rate)/100)+principle);

    return 0;
}