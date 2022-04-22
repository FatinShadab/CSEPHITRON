#include <stdio.h>

int main(){

    int arraySize;
    int res = 0;

    scanf("%d", &arraySize);

    int temps[arraySize];

    for (int i = 0; i < arraySize; i++){
        scanf("%d", &temps[i]);
    }

    for (int i = 0; i < arraySize; i++){
        if (temps[i] < 0){
            res += 1;
        }
    }

    printf("%d", res);

    return 0;
}