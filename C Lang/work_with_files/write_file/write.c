#include <stdio.h>
#include <string.h>

void create_file(char *fname){
    FILE *file;
    file = fopen(fname, "w");
    fclose(file);
}

int create_copy(char *fname){
    char ch;
    char s[100] = "copyed_";
    
    FILE *originalFile = fopen(fname, "r");
    if (originalFile == NULL){
        printf("\nFile not found!\n");
        return -1;
    }
    strcat(s, fname);
    FILE *copyedFile = fopen(s, "w");
    
    while( ( ch = fgetc(originalFile) ) != EOF ){
        fputc(ch, copyedFile);
    }
      
    fclose(originalFile);
    fclose(copyedFile);

    return 0;
}

int main(){
    char fname[1000];
    printf("Enter the file path - ");
    gets(fname);

    int op;
    printf("\nEnter -\n1 (to test create_file func)\n2 (to test create_copy func)\n - ");
    scanf("%d", &op);

    if (op == 1){
    // to read a char from the file
        create_file(fname);
    }
    else if(op == 2){
    // to copy one file data to another file
        create_copy(fname);
    }
    else if(op == 3){
    // to read the full file content
        //read_full_file(fname);       
    }
    else{
        printf("\nInvalid option - %d!", op);
    }

    return 0;
}