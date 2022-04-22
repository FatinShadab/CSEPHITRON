#include <stdio.h>

int main(){
    
    int x, y, n;

    scanf("%d %d %d", &x, &y, &n);

    for (int itr = 1; itr <= n; itr++){
        if (itr % x == 0 && itr % y != 0){
            printf("Fizz\n");
        }
        else if(itr % y ==0 && itr % x != 0){
            printf("Buzz\n");
        }
        else if(itr % x == 0 && itr % y == 0){
            printf("FizzBuzz\n");
        }
        else{
            printf("%d\n", itr);
        }
    }

    return 0;
}