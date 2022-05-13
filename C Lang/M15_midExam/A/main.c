#include <stdio.h>
#include <string.h>

int count_unique_char(char* str) {

	int hash[128] = { 0 };
	int i, c = 0;

	// reading each character of str[]
	for (i = 0; i < strlen(str); ++i) {
		// set the position corresponding 
		// to the ASCII value of str[i] in hash[] to 1
		hash[str[i]] = 1;
	}

	// counting number of unique characters
	// repeated elements are only counted once
	for (i = 0; i < 128; ++i) {
		c += hash[i];
	}

	return c;

}

int main(){

    char uname[101];

    //fgets(uname, 101, stdin);
    scanf("%s", uname);

    int unameLen = strlen(uname);

    int distinct_chars = count_unique_char(uname);

    if (distinct_chars %2 == 0){
        printf("CHAT WITH HER!");
    }
    else{
        printf("IGNORE HIM!");
    } 
    
    return 0;
}