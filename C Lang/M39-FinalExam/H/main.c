#include <stdio.h>
#include <string.h>


int main(){
    char string[101];
    scanf("%s", string);

    int strLen = strlen(string);

    int numbers[strLen];

    int idx = 0;
    for (int i=0; i<strLen; i++){
        if (string[i] == '1' || string[i] == '2' || string[i] == '3'){
            numbers[idx++] = (int) string[i] - '0';
        }
    }

    for (int i=0; i<(idx-1); i++){
        for (int j= i+1; j<idx; j++){
            if (numbers[i] > numbers[j]){
                int temp = numbers[i];
                numbers[i] = numbers[j];
                numbers[j] = temp;
            }
        }
    }

    printf("%d", numbers[0]);
    for (int i=1; i<idx; i++){
        printf("+%d", numbers[i]);
    }

    return 0;
}