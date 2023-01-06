/*
Example Graph:

    0 ----- 1       2 ----- 3
            |       |
            |       |
            5 ----- 4

    Graph properties:

        # number of nodes -> 6
        # number of edges -> 5

    list of adj nodes ->
    0 1
    2 3
    1 5
    2 4
    5 4

    Input format : 
    6 5
    0 1
    2 3
    1 5
    2 4
    5 4
*/
#include <bits/stdc++.h>

using namespace std;

const int N = 1e5;

int visited[N];
vector <int> adj_list[N];

void bfs(int src){
    queue <int> check;

    check.push(src);
    visited[src] = 1;

    while (!check.empty()){
        int node =  check.front();
        check.pop();

        printf("%d -> ", node);

        for (int adj_node : adj_list[node]){
            if (visited[adj_node] != 1){
                visited[adj_node] = 1;
                check.push(adj_node);
            }
        }

    }
};

int main(){
    int src;
    int nodes, edges;
    scanf("%d %d", &nodes, &edges);

    for (int edge=0; edge < edges; edge++){
        int u, v;
        scanf("%d %d", &u, &v);

        adj_list[u].push_back(v);
        adj_list[v].push_back(u);

        if (edge == 0) src = u;
    }

    printf("The graph : ");
    bfs(src);
    printf("NULL\n");

    return 0;
}