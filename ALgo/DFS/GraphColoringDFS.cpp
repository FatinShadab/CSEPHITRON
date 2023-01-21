/*
problem 1: print the connected components.
problem 2: Find out if the graph is bipartite.
problem 3: If bipartite do graph coloring and show.


input:
    1st line contain two integers n and m.
    n is the number of nodes.
    (the nodes will be 1, 2, ..., n)

    the next m lines will have 2 integers u and v
    representing the edge.
*/
#include <bits/stdc++.h>

using namespace std;

const int N = 10e5;

vector <int> adj_list[N];
int color[N];                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          ;
int visited[N];
int n, m;

int is_bipartite = 1;

void DFS(int src){
    printf("%d ", src);
    visited[src] = 1;

    if (!color[src])
        color[src] = 1;

    for (int adj_node : adj_list[src]){
        if (!visited[adj_node]){
            if (color[adj_node] == 0){
                color[adj_node] = (color[src] == 1) ? 2:1;
            }
            DFS(adj_node);
        }else{
            if (color[adj_node] == color[src]){
                is_bipartite = 0;
                return;
            }
        }
    }
}

int main(){
    printf("USER INPUT\n");
    scanf("%d %d", &n, &m);

    for (int i=0; i<m; i++){
        int u, v;
        scanf("%d %d", &u, &v);

        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    printf("\nConnected Components :");
    int count = 1;
    for (int i=1; i<=n; i++){
        if (!visited[i]){
            printf("\n\tCC[%d] : SRC : %d :\t", count++, i);
            DFS(i);
        }
    }

    if (is_bipartite){
        printf("\n\nGraph Type :\tThe graph is bipartite.");

        printf("\n\nNode\t|\tColor\n----------------------\n");
        for (int node=1; node <= n; node++){
            printf("%d\t|\t%d\n", node, color[node]);
        }
    }
    else
        printf("\n\nGraph Type :\tThe graph is not bipartite.");

    return 0;
}