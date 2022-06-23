# include <stdio.h>

int main(){

    int a, b, c, res;
    int prices[3];

    scanf("%d %d %d", &a, &b, &c);

    prices[0] = a + b;
    prices[1] = a + c;
    prices[2] = b + c;

    res = prices[0];
    for( int i = 1; i < 3; i++){

        if(res > prices[i]){

            res = prices[i];

        }   
   }

    printf("%d", res);
    
    return 0;
}