#include <stdio.h>

int main(){
    int numbers[100];

    for (int i=0; i<100; i++){
        int number;
        scanf("%d", &number);
        numbers[i] = number;
        if (number == 42){
            break;
        }
    }

    int idx = 0;
    while (numbers[idx] != 42){
        printf("%d\n", numbers[idx]);
        idx++;
    }

    return 0;
}