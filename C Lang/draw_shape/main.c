#include <stdio.h>

/*
Nested For loop means loop within loop

paterns and shapes are drawn by nested loop.

for loop{       // first loop = rows
    for loop{   // second loop = columns

    }
}
*/



void shapeOne(){
/*
    Shape: -

        *****
        *****
        *****
        *****
        *****

    Slove -
        step 0: write 1st "for loop" with total row number
        step 1: write 2nd "for loop" with total column number
    
*/

   for (int i = 0; i < 5; i++)                  // total row - 5
   {
       for (int j = 0; j < 5; j++)              // total column - 5
       {
           printf("%c", 4);
       }
       printf("\n");
   }
   

}

void shapeTwo(){
/*
    Shape: -

        987654321
        987654321
        987654321
        987654321
        987654321

    Slove -
        step 0: write 1st "for loop" with total row number
        step 1: write 2nd "for loop (reverse loop)" with total column number
    
*/

   for (int i = 0; i < 5; i++)
   {
       for (int j = 9; j > 0; j--)
       {
           printf("%d", j);
       }
       printf("\n");
   }
   
}

void shapeThree(){
/*
    Shape -

        *
        **
        ***
        ****
        *****
        ******
*/

    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < i; j++)
        {
            printf("%c", 4);
        }
        printf("\n");
        
    }
    

}

void shapeFour(){
/*
    Shape -

        *****
        ****
        ***
        **
        *

*/

    for (int i = 0; i < 5; i++)
    {
        for (int j = 5; j > i; j--)
        {
            printf("%c", 4);
        }
        printf("\n");
    }
    
}

void shapeFive(){
/*
    Shape - 
    r:1        *
    r:2       ***
    r:3      *****
    r:4     *******
    r:5    *********
*/
    for (int i = 1; i <= 5; i++)
    {
        for (int j = 1; j <= (5-i); j++)
        {
            printf(" ");
        }
        for (int k = 1; k <= ((2*i)-1); k++)
        {
            printf("%c",4);
        }
        printf("\n");
        
    }
    
}



int main(){

    printf("\n");
    shapeOne();
    printf("\n");
    shapeTwo();
    printf("\n");
    shapeThree();
    printf("\n");
    shapeFour();
    printf("\n");
    shapeFive();

    return 0;
}