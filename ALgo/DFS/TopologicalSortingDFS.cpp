/*
Topological Sorting in a DAG.

Input Format:
--------------
    the 1st line contains 2 integers n & m.
    next m lines contain 2 integers u & v.

    here,
        n represents the nodes (1 to n)
        m represents the number of edges

        u and v represents a directed edge (u --> v)

Output:
----------
    Any valid output.

Input:
-----------
    5 3
    1 2
    3 1
    4 5

Output
------------
    3 4 1 5 2
*/
#include <bits/stdc++.h>
using namespace std;
const int N = 10e5;

vector <int> adj_list[N];
stack <int> node_stack;
int visited[N];

void dfs(int node){
    visited[node] = 1;

    for (int adj_node : adj_list[node]){
        if (!visited[adj_node])
            dfs(adj_node);
    }

    node_stack.push(node);
}

int main(){
    int n, m;
    scanf("%d %d", &n, &m);

    for (int e=0; e<m; e++){
        int u, v;
        scanf("%d %d", &u, &v);

        adj_list[u].push_back(v);
    }

    for (int i=1; i<=n; i++){
        if (!visited[i])
            dfs(i);
    }

    while (!node_stack.empty()){
        printf("%d ", node_stack.top());
        node_stack.pop();
    }
    puts("");

    return 0;
}