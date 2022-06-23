#include <stdio.h>
#include <ctype.h>

int read_a_char(void){
    FILE *inputedFile;

    inputedFile = fopen("test_1.txt", "r");

    if (inputedFile == NULL){
        printf("\nFile not found!\n");
        return 1;
    }

    // to read a char from the file
    char ch = fgetc(inputedFile);
    printf("The first char in file - %c", ch);
    char ch1 = fgetc(inputedFile);
    printf("\nThe second char in file - %c", ch);

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

int read_full_file(void){
    FILE *inputedFile;

    inputedFile = fopen("test_1.txt", "r");

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
    scanf("Enter the file path - ");
    gets(fname);

    // to read a char from the file
    // uncomment line below,
    ///read_a_char(fname);

    // to read the first word from the file
    // uncomment line below,
    ///read_1st_word(fname);
    
    // to read the full file content
    // uncomment line below,
    ///read_full_file(fname);

    return 0;
}