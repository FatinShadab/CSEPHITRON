#include <stdio.h>

void create_file(char *fname){
    File *file;
    file = open(fname, 'w');
    fclose(file);
}

int main(){
    // to create a file
    // uncomment line below,
    create_file(fname="autoG.txt");
    
    return 0;
}