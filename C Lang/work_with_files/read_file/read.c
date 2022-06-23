#include <stdio.h>
#include <ctype.h>

int read_a_char(char *fname){
    FILE *inputedFile;

    inputedFile = fopen(fname, "r");

    if (inputedFile == NULL){
        printf("\nFile not found!\n");
        return 1;
    }

    // to read a char from the file
    char ch = fgetc(inputedFile);
    printf("The first char in file - %c", ch);

    fclose(inputedFile);

    return 0;
}

int read_1st_word(char *fname){
    FILE *inputedFile;

    inputedFile = fopen(fname, "r");

    if (inputedFile == NULL){
        printf("\nFile not found!\n");
        return 1;
    }

    // to read the first word from the file
    printf("The first word in file - ");
    char c = fgetc(inputedFile);
    while (isspace(c) == 0){
        printf("%c", c);
        c = fgetc(inputedFile);
    }

    fclose(inputedFile);

    return 0;
}

int read_full_file(char *fname){
    FILE *inputedFile;

    inputedFile = fopen(fname, "r");

    if (inputedFile == NULL){

        printf("\nFile not found!\n");
        return 1;
    }

    while (1){
        char c = fgetc(inputedFile);
        if (c == EOF){
            break;
        }
        else{
            printf("%c", c);
        }
    }

    fclose(inputedFile);

    return 0;
}


int main(){
    char fname[1000];
    printf("Enter the file path - ");
    gets(fname);

    int op;
    printf("\nEnter -\n1 (to test read_a_char func)\n2 (to test read_1st_word)\n3 (to test read_full_file)\n- ");
    scanf("%d", &op);

    if (op == 1){
    // to read a char from the file
        read_a_char(fname);
    }
    else if(op == 2){
    // to read the first word from the file
        read_1st_word(fname);
    }
    else if(op == 3){
    // to read the full file content
        read_full_file(fname);       
    }
    else{
        printf("\nInvalid option - %d!", op);
    }

    return 0;
}