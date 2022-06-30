#include <stdio.h>
#include <string.h>

int main(){
    // this code isn't duplicated. it's written by Fatin Shadab.
    int L, R;
    char string[100001];

    scanf("%d %d", &L, &R);
    scanf("%s", string);

    int len = (R-L)+1;
    
    char targetString[len];

    int idx=0;
    for (int i=0; i<strlen(string); i++){
        if (i >= L-1 && i <= R-1){
            targetString[idx++] = string[i];
        }
    }
    targetString[idx+1] = '\0';


    for (int i=0; i<L-1; i++){
        printf("%c", string[i]);
    }
    for (int i=len-1; i>-1; i--){
        printf("%c", targetString[i], i);
    }
    for (int i=R; i<strlen(string); i++){
        printf("%c", string[i]);
    }

    return 0;
}