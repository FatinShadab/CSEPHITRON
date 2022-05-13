#include <ctype.h>
#include <stdio.h>
 
int main()
{
    char word[1000];
    scanf("%s", word);

    word[0] = toupper(word[0]);
 
    printf("%s", word);
    return 0;
}