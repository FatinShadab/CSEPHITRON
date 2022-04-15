#include <stdio.h>

int main(){

    double _float;
    int _int;
    double _real;

    printf("Enter the float number - ");
    scanf("%lf", &_float);

    _int = (int)_float;
    _real = _float - _int;

    printf("\nInteger part : %d", _int);
    printf("\nReal part : %lf", _real);

    return 0;
}