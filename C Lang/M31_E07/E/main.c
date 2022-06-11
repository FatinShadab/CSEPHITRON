#include<stdio.h>

int main(){

    int sum = 0;
    char input[6];
    gets(input);

    for (int i=0; i<5; i++){
        sum += input[i] - '0';
    }

    printf("%d", sum);

    return 0;
}