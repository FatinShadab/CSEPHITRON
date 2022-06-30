#include <stdio.h>

int main(){
    int N;
    int K;
    int X = 1;

    scanf("%d", &N);
    scanf("%d", &K);

    for (int i=1; i<=N; i++){
        int opOne = X*2;
        int opTwo = X+K;
        //printf("\nOp 1: %d\nOp 2: %d\n========", opOne, opTwo);
        if (opOne > opTwo){
            X = opTwo;
        }
        else{
            X = opOne;
        }
    }

    printf("%d", X);

    return 0;
}