#include <stdio.h>

int main(){

    int failed = 0;
    int students;
    int passMarks;

    scanf("%d %d", &students, &passMarks);

    int studentMarks[students];

    for (int i=0; i < students; i++){
        scanf("%d", &studentMarks[i]);
    }

    for (int i=0; i < students; i++){
        if (studentMarks[i] < passMarks){
            failed += 1;
        }
    }

    printf("%d", failed);

    return 0;
}