#include <stdio.h>
void find_century(int years)
{
    // If years is between 1 to 100 it
    // will come in 1st century
    if (years <= 100)
    {
        printf("%d", 1);
    }
    else if (years % 100 == 0)
    {
        printf("%d",years/ 100);
    }
    else
    {
        printf("%d",years/ 100 +1);
    }
}
int main()
{
    int years;
    //Ask user to input number of years
    scanf("%d", &years);
    find_century(years);
    return 0;
}