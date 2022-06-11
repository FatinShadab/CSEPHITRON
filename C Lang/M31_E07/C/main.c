#include<stdio.h>
#include<ctype.h>
#include <string.h>


int main(){
    int frequency[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    //  frequency of 0  1  2  3  4  5  6  7  8  9
    char string[1001];

    gets(string);

    int string_len = strlen(string);

    for (int i=0; i < string_len; i++){
        if (isdigit(string[i])){
            int index = string[i] - '0';
            frequency[index] += 1;
        }
    }

    for (int i=0; i < 10; i++){
        printf("%d ", frequency[i]);
    }

    return 0;
}