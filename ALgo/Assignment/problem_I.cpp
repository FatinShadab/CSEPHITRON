#include <bits/stdc++.h>

using namespace std;

int main(){
    int is_bi_directional = 1;

    int n, m;
    scanf("%d %d", &n, &m);

    int adj_matrix[n+1][n+1];
    for(int row=0; row<=n; row++)
        for (int col=0; col<=n; adj_matrix[row][col++] = 0);

    // !!! valid input range for u, v is [0, n]
    for (int i=0; i < m; i++){
        int u, v;
        scanf("%d %d", &u, &v);

        adj_matrix[u][v] = 1;
    }

    // Block Start: print adj_matrix
    printf("\nGraph Adjacency Matrix :\n\n  | ");
    for (int v=0; v<=n; v++){
        printf("%d ", v);
    }
    printf("\n--|-");
    for (int v=0; v<=n; v++)
        printf("--");
    puts("");

    for (int u=0; u<=n; u++){
        printf("%d | ", u);
        for (int v=0; v<=n; v++){
            printf("%d ", adj_matrix[u][v]);
        }
        puts("");
    }
    // Block End : print adj_matrix

    for (int u=0; u<=n; u++){
        for (int v=0; v<=n; v++){
            if (adj_matrix[u][v] == 1 && adj_matrix[v][u] != 1){
                is_bi_directional = 0;
                break;
            }
        }

        if (!is_bi_directional){
            break;
        }
    }

    printf((is_bi_directional) ? "\nThe graph is BI-Directional.\n":"\nThe graph isn't BI-Directional.\n");

    return 0;
}