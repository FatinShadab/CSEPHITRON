#include <stdio.h>

int main(){

    int howmanynum5 = 0, howmanynum7 = 0;
    int nums[3];

    scanf("%d %d %d", &nums[0], &nums[1], &nums[2]);

    for (int i = 0; i < 3; i++){
        if (nums[i] == 5){
            howmanynum5 += 1;
        }
        if (nums[i] == 7){
            howmanynum7 += 1;
        }
    }

    if (howmanynum5 == 2 && howmanynum7 == 1){
        printf("YES");
    }
    else{
        printf("NO");
    }

    return 0;
}