/*
Check if there is any cycle in a directed graph.

input format;
    n, m (n : number of node (1 to n) and  m :number of edges)
    next m lines contain 2 integers u and v (u and v represent the edge u --> v)

Input:
4 5
1 3
2 1
2 4
3 2
3 4

Output:
Cycle exists.
*/
#include <bits/stdc++.h>
using namespace std;
const int N  = 2e5;

vector <int> adj_list[N];
int visited[N];

bool detectCycle(int node){

    visited[node] = 1;

    for (int adj_node: adj_list[node]){
        /*
            - visited[adj_node] == 0 -> unexplored node | apply detectCycle
            - visited[adj_node] == 1 -> paused node | cycle detected
            - visited[adj_node] == 2 -> done node | continue
        */
        if (visited[adj_node] == 0){
            bool got_cycle = detectCycle(adj_node);
            if (got_cycle){
                return true;
            }
        }
        else if (visited[adj_node] == 1){
            return true;
        }
    }

    visited[node] = 2;

    return false;
}

int main(){
    int n, m;
    scanf("%d %d", &n, &m);

    for (int i=0; i<m; i++){
        int u, v;
        scanf("%d %d", &u, &v);
        adj_list[u].push_back(v);
    }

    for (int i=1; i<=n; i++){
        if (visited[i] == 0){
            bool got_cycle = detectCycle(i);
            if (got_cycle){
                printf("Cycle exists.\n");
                return 0;
            }
        }
    }

    printf("No cycle exists.\n");

    return 0;
}