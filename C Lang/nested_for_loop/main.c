#include <stdio.h>

/*

|---------------------------------|
|Input  |         N (int)         |
|---------------------------------|
|output | 1+(1+2+3)+(1+2+3+...+N) |
|---------------------------------|

*/

int main(){

    int n, i, j;
    int sum=0;

    printf("Enter the upper limit 'N' - ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++){
        for(j = 1; j <= i; j++){
            sum += j;
        }
    }

    printf("Sum - %d", sum);

    return 0;
}