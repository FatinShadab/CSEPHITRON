#include <stdio.h>
#include <string.h>

struct name{
    char firstName[21];
    char lastName[21];
};

int main(){
    int names;
    scanf("%d", &names);
    struct name allNames[names];
    for (int i=0; i<names; i++){
        char fname[21];
        char lname[21]; 
        scanf("%s %s", fname, lname);
        strcpy(allNames[i].firstName, fname);
        strcpy(allNames[i].lastName, lname);
    }

    int matched = 0;

    for (int i=0; i<names; i++){
        if (matched == 0){
            for (int j=0; j<names; j++){
                if (i != j){
                    if (strcmp(allNames[i].firstName, allNames[j].firstName) == 0){
                        if (strcmp(allNames[i].lastName, allNames[j].lastName) == 0){
                            matched++;
                            //printf("\nPerforming matched - (%s %s) : (%s %s) [matched : %d]",allNames[i].firstName, allNames[i].lastName, allNames[j].firstName, allNames[j].lastName, matched);
                            break;
                        }
                    }
                    //printf("\nPerforming match with - (%s %s) : (%s %s) [matched : %d]",allNames[i].firstName, allNames[i].lastName, allNames[j].firstName, allNames[j].lastName, matched);
                }
            }
        }
        else{
            break;
        }
    }

    if (matched != 0){
        printf("Yes");
    }
    else{
        printf("No");
    }

    return 0;
}