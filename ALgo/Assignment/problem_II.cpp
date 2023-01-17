/*
This is a follow up of problem 1. Trim all edges of the input graph where there is an
edge from u -> v but not v -> u. Output the number of edges you have to
remove. Use the same code to take input as problem 1.
*/
#include <bits/stdc++.h>

using namespace std;

int main(){
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

    int one_directional_edges = 0;

    for (int u=0; u<=n; u++){
        for (int v=0; v<=n; v++){
            if (adj_matrix[u][v] == 1 && adj_matrix[v][u] != 1){
                one_directional_edges++;
            }
        }
    }

    printf("\n%d edge(s) have to be remove.\n", one_directional_edges);

    return 0;
}