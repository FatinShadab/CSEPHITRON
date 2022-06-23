#include <stdio.h>

/*
Update code the following code swaps the contents of two arrays of equal size. You can
only write code inside the loop (in the section marked “Write Code Here”). Do not modify
anything else.

int n = 10;
int a[n], b[n];
for (int i=0; i<n; i++) {
//Write Code Here
}

*/

int main(){
    int n = 10;
    int a[n], b[n];
    for (int i=0; i < n; i++){
        scanf("%d", &a[i]);
    }
    for (int i=0; i < n; i++){
        scanf("%d", &b[i]);
    }
    for (int i=0; i<n; i++){
        int temp_a;
        int temp_b;

        temp_a = a[i];
        temp_b = b[i];

        b[i] = temp_a;
        a[i] = temp_b;

    }
    printf("\narray a:");
    for (int i=0; i < n; i++){
        printf("%d ", a[i]);
    }
    printf("\narray b:");
    for (int i=0; i < n; i++){
        printf("%d ", b[i]);
    }

    return 0;
}