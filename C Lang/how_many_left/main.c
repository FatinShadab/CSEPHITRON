#include <stdio.h>

/*
In a grid there are HH rows and WW columns of cells. All cells are white initially.

Alex picks some hh rows and ww columns. Then all cells that are in these rows or columns are colored black.

How many cells will remain white?

All values in input are integers.
    *1 \leq H, W \leq 201≤H,W≤20
    *1 \leq h \leq H1≤h≤H
    *1 \leq w \leq W1≤w≤W

Input is given from Standard Input in the following format:

    HH WW
    hh ww

example:
input:  |output:
--------|-------
3 2     |  1
2 1     |

There are 33 rows and 22 columns of cells. When two rows and one column are chosen and painted in black, there is always one uncolored cell that remains.
*/

int main(){

    int R, C, r, c;
    int totalCell;
    int cell_colored_by_row;
    int cell_colored_by_col;
    int ans;

    scanf("%d %d", &R, &C);
    scanf("%d %d", &r, &c);

    if (R == r){
        printf("%d", 0);
    }
    else{
        totalCell = R * C;
        cell_colored_by_row = r * C;
        cell_colored_by_col = c*(R-r);

        ans = totalCell - (cell_colored_by_row + cell_colored_by_col);

        printf("%d", ans);
    }

    return 0;
}